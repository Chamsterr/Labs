import 'package:flutter/material.dart';

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
    required this.isNavigable,
    this.doctors,
  });
}

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
