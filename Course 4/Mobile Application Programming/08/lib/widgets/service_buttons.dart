import 'package:flutter/material.dart';
import 'package:hive/hive.dart';
import '../models/DoctorHive.dart' as doctor_hive;
import 'build_service_button.dart';
import 'second_page.dart';

class ServiceButtonData {
  final String title;
  final IconData icon;
  final Color backgroundColor;
  final Color textColor;
  final Color borderColor;
  final bool isNavigable;

  ServiceButtonData({
    required this.title,
    required this.icon,
    required this.backgroundColor,
    required this.textColor,
    required this.borderColor,
    this.isNavigable = false,
  });
}

class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  @override
  Widget build(BuildContext context) {
    final Box<doctor_hive.Doctor> doctorsBox = Hive.box<doctor_hive.Doctor>('doctors');

    final List<ServiceButtonData> buttons = [
      ServiceButtonData(
        title: 'Diagnostic',
        icon: Icons.medical_services,
        backgroundColor: Colors.white,
        textColor: Colors.orange,
        borderColor: Colors.white,
        isNavigable: true,
      ),
    ];

    return Column(
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            for (var button in buttons)
              GestureDetector(
                onTap: button.isNavigable
                    ? () {
                  final doctors = doctorsBox.values.toList();
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => SecondPage(doctors: doctors),
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
      ],
    );
  }
}