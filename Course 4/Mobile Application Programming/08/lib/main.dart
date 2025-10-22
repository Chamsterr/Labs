import 'package:flutter/material.dart';
import 'package:hive/hive.dart';
import 'package:hive_flutter/hive_flutter.dart';
import 'models/DoctorHive.dart' as doctor_hive;
import 'models/user.dart';
import 'models/favorite_doctor.dart';
import 'widgets/main_page.dart' as main_page;

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Hive.initFlutter();

  Hive.registerAdapter(FavoriteDoctorAdapter());
  Hive.registerAdapter(AdminAdapter());
  Hive.registerAdapter(RegularUserAdapter());
  Hive.registerAdapter(doctor_hive.DoctorAdapter());

  await Hive.openBox<FavoriteDoctor>('favorites');
  await Hive.openBox<User>('users');

  if (!Hive.isBoxOpen('doctors')) {
    await Hive.openBox<doctor_hive.Doctor>('doctors');
  }

  final userBox = Hive.box<User>('users');
  if (userBox.isEmpty) {
    final admin = Admin(id: 'admin_id', name: 'Admin User');
    userBox.put(admin.id, admin);

    final regularUser = RegularUser(id: 'user_id', name: 'Regular User');
    userBox.put(regularUser.id, regularUser);
  }

  await clearDoctorsData();
  // await addDefaultDoctors();

  runApp(const MaterialApp(home: main_page.MainPage()));
}

Future<void> addDefaultDoctors() async {
  final doctorBox = Hive.box<doctor_hive.Doctor>('doctors');

  if (doctorBox.isEmpty) {
    final doctor = doctor_hive.Doctor(
      name: 'Dr. John Smith',
      specialty: 'Pediatrician',
      rating: 4.5,
      availableTimes: '10 - 12',
      timerColorValue: 0, title: 'Shots',
    );


  }
}

Future<void> clearDoctorsData() async {
  final doctorBox = Hive.box<doctor_hive.Doctor>('doctors');
  await doctorBox.clear();
}


Future<void> clearHiveData() async {
  await Hive.deleteBoxFromDisk('favorites');
  await Hive.deleteBoxFromDisk('users');
  await Hive.deleteBoxFromDisk('doctors');
}
