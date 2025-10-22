import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Sensor and SMS Sender',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: SensorAndSmsPage(),
    );
  }
}

class SensorAndSmsPage extends StatefulWidget {
  @override
  _SensorAndSmsPageState createState() => _SensorAndSmsPageState();
}

class _SensorAndSmsPageState extends State<SensorAndSmsPage> {
  static const platform = MethodChannel('com.example.my_app/accelerometer');
  static const smsPlatform = MethodChannel('com.example.my_app/sms');
  static const batteryPlatform = MethodChannel('com.example.my_app/battery');
  double _x = 0;
  double _y = 0;
  double _z = 0;
  String _batteryLevel = "Unknown";

  final TextEditingController _phoneController = TextEditingController();
  final TextEditingController _messageController = TextEditingController();

  Future<void> _getAccelerometerData() async {
    try {
      final Map<Object?, Object?> result =
      await platform.invokeMethod('getAccelerometerData');
      setState(() {
        _x = result['x'] as double? ?? 0;
        _y = result['y'] as double? ?? 0;
        _z = result['z'] as double? ?? 0;
      });
    } on PlatformException catch (e) {
      print("Failed to get accelerometer data: '${e.message}'.");
    }
  }

  Future<void> _sendSms() async {
    try {
      final String phoneNumber = _phoneController.text;
      final String message = _messageController.text;

      final result = await smsPlatform.invokeMethod('sendSms', {
        'phone': phoneNumber,
        'message': message,
      });
      print(result);
    } on PlatformException catch (e) {
      print("Failed to send SMS: '${e.message}'.");
    }
  }

  Future<void> _getBatteryLevel() async {
    try {
      final int result = await batteryPlatform.invokeMethod('getBatteryLevel');
      setState(() {
        _batteryLevel = '$result%';
      });
    } on PlatformException catch (e) {
      print("Failed to get battery level: '${e.message}'.");
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Sensor and SMS Sender'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: <Widget>[
            Text('Accelerometer Data:'),
            Text('X: $_x'),
            Text('Y: $_y'),
            Text('Z: $_z'),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _getAccelerometerData,
              child: Text('Get Accelerometer Data'),
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _getBatteryLevel,
              child: Text('Get Battery Level'),
            ),
            SizedBox(height: 20),
            Text('Battery Level: $_batteryLevel'),
            SizedBox(height: 40),
            TextField(
              controller: _phoneController,
              decoration: InputDecoration(
                labelText: 'Phone Number',
              ),
              keyboardType: TextInputType.phone,
            ),
            TextField(
              controller: _messageController,
              decoration: InputDecoration(
                labelText: 'Message',
              ),
              keyboardType: TextInputType.multiline,
              maxLines: null,
            ),
            SizedBox(height: 20),
            ElevatedButton(
              onPressed: _sendSms,
              child: Text('Send SMS'),
            ),
          ],
        ),
      ),
    );
  }
}
