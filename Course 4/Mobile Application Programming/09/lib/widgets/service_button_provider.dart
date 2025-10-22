import 'package:flutter/material.dart';

class Doctor {
  final String name;
  final String specialty;
  final double rating;
  final String availableTimes;
  final Color timerColor;

  Doctor({
    required this.name,
    required this.specialty,
    required this.rating,
    required this.availableTimes,
    required this.timerColor,
  });
}

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

class ServiceButtonProvider with ChangeNotifier {
  final List<ServiceButtonData> _buttons = [
    ServiceButtonData(
      title: 'Diagnostic',
      icon: Icons.medical_services,
      backgroundColor: Colors.white,
      textColor: Colors.orange,
      borderColor: Colors.white,
      isNavigable: true,
      doctors: [
        Doctor(name: 'Dr. Smith111', specialty: 'Cardiology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.blue),
        Doctor(name: 'Dr. Jones111111', specialty: 'Neurology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.yellow),
        Doctor(name: 'Dr. Taylor1111', specialty: 'Pediatrics', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.green),
      ],
    ),
  ];


  ServiceButtonData? _selectedButton;

  ServiceButtonData? get selectedButton => _selectedButton;

  void setSelectedButton(ServiceButtonData button) {
    _selectedButton = button;
    notifyListeners();
  }

  List<ServiceButtonData> get buttons => _buttons;
}
