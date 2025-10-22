import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import '../models/doctor.dart';
import 'second_page.dart';


Widget buildServiceButton(String? title, IconData icon, Color iconColor, Color backgroundColor, Color textColor) {
  return Container(
    height: 90,
    width: 100,
    padding: const EdgeInsets.all(11),
    decoration: BoxDecoration(
      color: backgroundColor,
      borderRadius: BorderRadius.circular(15),
      boxShadow: [
        BoxShadow(
          color: Colors.black.withOpacity(0.2),
          spreadRadius: 2,
          blurRadius: 5,
          offset: const Offset(0, 3),
        ),
      ],
    ),
    child: Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(
          icon,
          color: iconColor,
          size: title == null ? 40 : 32,
        ),
        if (title != null) ...[
          const SizedBox(height: 8),
          Text(
            title,
            style: TextStyle(
              fontSize: 10,
              fontWeight: FontWeight.bold,
              color: textColor,
            ),
            textAlign: TextAlign.center,
          ),
        ],
      ],
    ),
  );
}

class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  Future<List<Doctor>> _fetchDoctors() async {
    try {
      final querySnapshot = await FirebaseFirestore.instance.collection('doctors').get();
      return querySnapshot.docs.map((doc) => Doctor.fromFirestore(doc)).toList();
    } catch (e) {
      print("Error fetching doctors: $e");
      return [];
    }
  }

  @override
  Widget build(BuildContext context) {
    return Row(
      mainAxisAlignment: MainAxisAlignment.spaceEvenly,
      children: [
        GestureDetector(
          onTap: () async {
            final doctors = await _fetchDoctors();

            if (doctors.isNotEmpty) {
              Navigator.push(
                context,
                MaterialPageRoute(
                  builder: (context) => SecondPage(specialty: "123"),
                ),
              );
            } else {
              // Show an error message if no doctors are found
              ScaffoldMessenger.of(context).showSnackBar(
                SnackBar(content: Text('No doctors found')),
              );
            }
          },
          child: buildServiceButton(
            'View Doctors',
            Icons.local_hospital,
            Colors.white,
            Colors.blue,
            Colors.white,
          ),
        ),
      ],
    );
  }
}
