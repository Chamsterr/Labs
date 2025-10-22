import 'package:flutter/material.dart';
import 'service_button_data.dart';

abstract class ServiceButtonState {
  List<ServiceButtonData> get buttons;
}

class ServiceButtonInitial extends ServiceButtonState {
  @override
  List<ServiceButtonData> get buttons => [
    ServiceButtonData(
      title: 'Diagnostic',
      icon: Icons.medical_services,
      backgroundColor: Colors.white,
      textColor: Colors.orange,
      borderColor: Colors.white,
      isNavigable: true,
      doctors: [
        Doctor(name: 'Dr. Smith1', specialty: 'Cardiology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.blue),
        Doctor(name: 'Dr. Jones1', specialty: 'Neurology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.yellow),
        Doctor(name: 'Dr. Taylor1', specialty: 'Pediatrics', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.green),
      ],
    ),
  ];
}

class ServiceButtonLoaded extends ServiceButtonState {
  final List<ServiceButtonData> buttons;

  ServiceButtonLoaded(this.buttons);
}
