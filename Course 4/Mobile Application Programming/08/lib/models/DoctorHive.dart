import 'package:flutter/material.dart';
import 'package:hive/hive.dart';


@HiveType(typeId: 0)
class Doctor extends HiveObject {
  @HiveField(0)
  final String name;

  @HiveField(1)
  final String specialty;

  @HiveField(2)
  final double rating;

  @HiveField(3)
  final String availableTimes;

  @HiveField(4)
  final int timerColorValue;

  @HiveField(5)
  final String title;

  Doctor({
    required this.name,
    required this.specialty,
    required this.rating,
    required this.availableTimes,
    required this.timerColorValue,
    required this.title,
  });

  Color get timerColor => Color(timerColorValue);
}

class DoctorAdapter extends TypeAdapter<Doctor> {
  @override
  final int typeId = 0;

  @override
  Doctor read(BinaryReader reader) {
    final name = reader.readString();
    final specialty = reader.readString();
    final rating = reader.readDouble();
    final availableTimes = reader.readString();
    final timerColorValue = reader.readInt();
    final title = reader.readString();

    return Doctor(
      name: name,
      specialty: specialty,
      rating: rating,
      availableTimes: availableTimes,
      timerColorValue: timerColorValue,
      title: title,
    );
  }

  @override
  void write(BinaryWriter writer, Doctor obj) {
    writer.writeString(obj.name);
    writer.writeString(obj.specialty);
    writer.writeDouble(obj.rating);
    writer.writeString(obj.availableTimes);
    writer.writeInt(obj.timerColorValue);
    writer.writeString(obj.title);
  }
}
