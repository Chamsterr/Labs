import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import '../models/doctor.dart';
import 'build_service_button.dart';
import 'second_page.dart';

class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  Future<List<String>> _fetchSpecialties() async {
    final querySnapshot = await FirebaseFirestore.instance.collection('doctors').get();
    final specialties = querySnapshot.docs
        .map((doc) => doc['specialty'] as String)
        .toSet()
        .toList();
    return specialties;
  }

  Future<List<Doctor>> _fetchDoctorsBySpecialty(String specialty) async {
    final querySnapshot = await FirebaseFirestore.instance
        .collection('doctors')
        .where('specialty', isEqualTo: specialty)
        .get();

    return querySnapshot.docs
        .map((doc) => Doctor.fromFirestore(doc))
        .toList();
  }

  @override
  Widget build(BuildContext context) {
    return FutureBuilder<List<String>>(
      future: _fetchSpecialties(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        }

        if (snapshot.hasError) {
          return Center(child: Text('Error: ${snapshot.error}'));
        }

        final specialties = snapshot.data ?? [];

        return Column(
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: <Widget>[
                for (var specialty in specialties)
                  GestureDetector(
                    onTap: () async {
                      final doctors = await _fetchDoctorsBySpecialty(specialty);
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => SecondPage(specialty: specialty),
                        ),
                      );
                    },
                    child: buildServiceButton(
                      specialty,
                      Icons.medical_services,
                      Colors.white,
                      Colors.orange,
                      Colors.grey.shade300,
                    ),
                  ),
              ],
            ),
          ],
        );
      },
    );
  }
}
