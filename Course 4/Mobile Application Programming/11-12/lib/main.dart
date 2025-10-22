import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:lab_04_05_06_part1_v2/widgets/login_page.dart';
import 'package:lab_04_05_06_part1_v2/widgets/main_page.dart';
import 'package:lab_04_05_06_part1_v2/widgets/profile_page.dart';
import 'package:lab_04_05_06_part1_v2/widgets/register_page.dart';
import 'models/doctor.dart' as doctor_model;

void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();
  runApp(MyApp());
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      initialRoute: '/main',
      routes: {
        '/login': (context) => const LoginPage(),
        '/register': (context) => const RegistrationPage(),
        '/main': (context) => const MainPage(),
        '/profile': (context) => const ProfilePage(),
      },
    );
  }
}

Future<void> addUser(User user) async {
  final userRef = FirebaseFirestore.instance.collection('users').doc(user.id);
  await userRef.set({
    'id': user.id,
    'name': user.name,
  });
}

Future<void> addDoctor(doctor_model.Doctor doctor) async {
  final doctorRef = FirebaseFirestore.instance.collection('doctors').doc(doctor.id);
  await doctorRef.set({
    'name': doctor.name,
    'specialty': doctor.specialty,
    'rating': doctor.rating,
    'availableTimes': doctor.availableTimes,
    'timerColorValue': doctor.timerColorValue,
    'title': doctor.title,
  });
}

Future<List<doctor_model.Doctor>> fetchDoctors() async {
  final doctorSnapshot = await FirebaseFirestore.instance.collection('doctors').get();
  return doctorSnapshot.docs.map((doc) => doctor_model.Doctor.fromFirestore(doc)).toList();
}

Future<void> clearDoctorsData() async {
  final doctorSnapshot = await FirebaseFirestore.instance.collection('doctors').get();
  for (var doc in doctorSnapshot.docs) {
    await doc.reference.delete();
  }
}

Future<void> clearUsersData() async {
  final userSnapshot = await FirebaseFirestore.instance.collection('users').get();
  for (var doc in userSnapshot.docs) {
    await doc.reference.delete();
  }
}

Future<void> addDefaultUsers() async {
  final userBox = FirebaseFirestore.instance.collection('users');

  final admin = User(id: 'admin_id', name: 'Admin User');
  final regularUser = User(id: 'user_id', name: 'Regular User');

  await addUser(admin);
  await addUser(regularUser);
}

Future<void> addDefaultDoctors() async {
  final doctorBox = FirebaseFirestore.instance.collection('doctors');

  final doctor = doctor_model.Doctor(
      id: 'doctor_1',
      name: 'Dr. John Smith',
      specialty: 'Pediatrician',
      rating: 4.5,
      availableTimes: '10 - 12',
      timerColorValue: 0,
      title: 'Shots'
  );

  await addDoctor(doctor);
}

class User {
  final String id;
  final String name;

  User({required this.id, required this.name});

  factory User.fromMap(Map<String, dynamic> map) {
    return User(
      id: map['id'] ?? '',
      name: map['name'] ?? '',
    );
  }

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'name': name,
    };
  }
}