import 'package:flutter/material.dart';
import 'build_service_button.dart';
import 'second_page.dart';

class ServiceButtonData {
  final String title;
  final IconData icon;
  final Color backgroundColor;
  final Color textColor;
  final Color borderColor;
  final bool isNavigable;
  final List<Doctor>? doctors;

  ServiceButtonData({
    required this.title,
    required this.icon,
    required this.backgroundColor,
    required this.textColor,
    required this.borderColor,
    this.isNavigable = false,
    this.doctors,
  });
}


class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  @override
  Widget build(BuildContext context) {
    final List<ServiceButtonData> buttons = [
      ServiceButtonData(
        title: 'Diagnostic',
        icon: Icons.medical_services,
        backgroundColor: Colors.white,
        textColor: Colors.orange,
        borderColor: Colors.white,
        isNavigable: true,
        doctors: [
          Doctor(name: 'Dr. Smith', specialty: 'Cardiology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.blue),
          Doctor(name: 'Dr. Jones', specialty: 'Neurology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.yellow),
          Doctor(name: 'Dr. Taylor', specialty: 'Pediatrics', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.green),
        ],
      ),
      ServiceButtonData(
        title: 'Shots',
        icon: Icons.local_hospital,
        backgroundColor: Colors.blue,
        textColor: Colors.white,
        borderColor: Colors.black,
        isNavigable: true,
        doctors: [
          Doctor(name: 'Dr. Smith 2', specialty: 'Cardiology 3', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.blue),
          Doctor(name: 'Dr. Jones 3', specialty: 'Neurology 3', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.yellow),
          Doctor(name: 'Dr. Taylor 3', specialty: 'Pediatrics 3', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.green),
        ],
      ),
      ServiceButtonData(
        title: 'Consultation',
        icon: Icons.chat,
        backgroundColor: Colors.blue,
        textColor: Colors.white,
        borderColor: Colors.black,
      ),
      ServiceButtonData(
        title: 'Ambulance',
        icon: Icons.local_taxi,
        backgroundColor: Colors.blue,
        textColor: Colors.white,
        borderColor: Colors.black,
      ),
      ServiceButtonData(
        title: 'Nurse',
        icon: Icons.local_pharmacy,
        backgroundColor: Colors.white,
        textColor: Colors.orange,
        borderColor: Colors.white,
      ),
      ServiceButtonData(
        title: 'Lab Work',
        icon: Icons.science,
        backgroundColor: Colors.blue,
        textColor: Colors.white,
        borderColor: Colors.black,
      ),
    ];

    return Column(
      children: [

        Builder(
          builder: (BuildContext newContext) => Row(
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: <Widget>[
              for (var button in buttons.sublist(0, 3))
                GestureDetector(
                  onTap: button.isNavigable
                      ? () {
                    Navigator.push(
                      newContext,
                      MaterialPageRoute(
                        builder: (context) => SecondPage(doctors: button.doctors!),
                      ),
                    );
                  }
                      : null,
                  child: buildServiceButton(
                    button.title,
                    button.icon,
                    button.backgroundColor,
                    button.textColor,
                    button.borderColor,
                  ),
                ),
            ],
          ),
        ),
        const SizedBox(height: 22),
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            for (var button in buttons.sublist(3))
              buildServiceButton(
                button.title,
                button.icon,
                button.backgroundColor,
                button.textColor,
                button.borderColor,
              ),
          ],
        ),
      ],
    );
  }
}
