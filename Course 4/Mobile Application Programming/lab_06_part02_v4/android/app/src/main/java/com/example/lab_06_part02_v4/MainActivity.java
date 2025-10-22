package com.example.lab_06_part02_v4;
import android.content.IntentFilter;
import android.content.Intent;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.net.Uri;
import android.os.BatteryManager;
import android.os.Bundle;
import io.flutter.embedding.android.FlutterActivity;
import io.flutter.plugin.common.MethodChannel;

import java.util.HashMap;

public class MainActivity extends FlutterActivity {
    private static final String ACCELEROMETER_CHANNEL = "com.example.my_app/accelerometer";
    private static final String SMS_CHANNEL = "com.example.my_app/sms";
    private static final String BATTERY_CHANNEL = "com.example.my_app/battery";

    private SensorManager sensorManager;
    private Sensor accelerometer;
    private SensorEventListener sensorEventListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        new MethodChannel(getFlutterEngine().getDartExecutor().getBinaryMessenger(), ACCELEROMETER_CHANNEL)
                .setMethodCallHandler((call, result) -> {
                    if (call.method.equals("getAccelerometerData")) {
                        startAccelerometer(result);
                    } else {
                        result.notImplemented();
                    }
                });

        new MethodChannel(getFlutterEngine().getDartExecutor().getBinaryMessenger(), SMS_CHANNEL)
                .setMethodCallHandler((call, result) -> {
                    if (call.method.equals("sendSms")) {
                        String phoneNumber = call.argument("phone");
                        String message = call.argument("message");
                        sendSms(phoneNumber, message);
                        result.success("SMS sent successfully!");
                    } else {
                        result.notImplemented();
                    }
                });

        new MethodChannel(getFlutterEngine().getDartExecutor().getBinaryMessenger(), BATTERY_CHANNEL)
                .setMethodCallHandler((call, result) -> {
                    if (call.method.equals("getBatteryLevel")) {
                        int batteryLevel = getBatteryLevel();
                        result.success(batteryLevel);
                    } else {
                        result.notImplemented();
                    }
                });

        sensorManager = (SensorManager) getSystemService(SENSOR_SERVICE);
        accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
    }

    private void startAccelerometer(MethodChannel.Result result) {
            sensorEventListener = new SensorEventListener() {
            @Override
            public void onSensorChanged(SensorEvent event) {
                float x = event.values[0];
                float y = event.values[1];
                float z = event.values[2];

                HashMap<String, Float> data = new HashMap<>();
                data.put("x", x);
                data.put("y", y);
                data.put("z", z);

                result.success(data);
                sensorManager.unregisterListener(this);
            }

            @Override
            public void onAccuracyChanged(Sensor sensor, int accuracy) {
            }
        };

        sensorManager.registerListener(sensorEventListener, accelerometer, SensorManager.SENSOR_DELAY_NORMAL);
    }

    private void sendSms(String phoneNumber, String message) {
        Intent smsIntent = new Intent(Intent.ACTION_VIEW);
        smsIntent.setData(Uri.parse("sms:" + phoneNumber));
        smsIntent.putExtra("sms_body", message);
        startActivity(smsIntent);
    }

    private int getBatteryLevel() {
        Intent batteryIntent = registerReceiver(null, new IntentFilter(Intent.ACTION_BATTERY_CHANGED));
        int batteryLevel = batteryIntent.getIntExtra(BatteryManager.EXTRA_LEVEL, -1);
        int batteryScale = batteryIntent.getIntExtra(BatteryManager.EXTRA_SCALE, -1);
        return (int) ((batteryLevel / (float) batteryScale) * 100);
    }
}
