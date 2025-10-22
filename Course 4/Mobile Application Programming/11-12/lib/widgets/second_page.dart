import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import '../models/doctor.dart';
import '../models/user.dart';
import '../models/user_manager.dart';

class SecondPage extends StatefulWidget {
  final String specialty;
  const SecondPage({super.key, required this.specialty});

  @override
  _SecondPageState createState() => _SecondPageState();
}

class _SecondPageState extends State<SecondPage> {
  List<Doctor> _doctors = [];
  bool _isLoading = true;

  @override
  void initState() {
    super.initState();
    _fetchDoctors();
  }

  Future<void> _fetchDoctors() async {
    try {
      final querySnapshot =
      await FirebaseFirestore.instance.collection('doctors').where('specialty', isEqualTo: widget.specialty).get();

      final doctors = querySnapshot.docs
          .map((doc) => Doctor.fromFirestore(doc))
          .toList();

      setState(() {
        _doctors = doctors;
        _isLoading = false;
      });
    } catch (e) {
      setState(() {
        _isLoading = false;
      });
      print('Error fetching doctors: $e');
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blue,
        title: const Text('Top Doctors'),
      ),
      backgroundColor: Colors.blue,
      body: _isLoading
          ? const Center(child: CircularProgressIndicator())
          : _doctors.isEmpty
          ? const Center(
        child: Text(
          'No doctors available',
          style: TextStyle(color: Colors.white, fontSize: 18),
        ),
      )
          : Padding(
        padding: const EdgeInsets.all(0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Container(
              margin: const EdgeInsets.all(0),
              width: double.infinity,
              padding:
              const EdgeInsets.fromLTRB(50.0, 80.0, 30.0, 30.0),
              decoration: const BoxDecoration(color: Colors.blue),
              child: const Row(
                crossAxisAlignment: CrossAxisAlignment.center,
                children: [
                  Text(
                    'Top doctors',
                    style: TextStyle(
                      fontSize: 32,
                      fontWeight: FontWeight.bold,
                      color: Colors.white,
                    ),
                  ),
                  Icon(Icons.star, color: Colors.yellow),
                ],
              ),
            ),
            Expanded(
              child: Container(
                width: double.infinity,
                height: double.infinity,
                decoration: const BoxDecoration(
                  color: Colors.white,
                  borderRadius: BorderRadius.only(
                    topLeft: Radius.circular(50),
                  ),
                ),
                child: Padding(
                  padding: const EdgeInsets.all(21.0),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Row(
                        mainAxisAlignment:
                        MainAxisAlignment.spaceBetween,
                        children: [
                          const Text(
                            'Categories',
                            style: TextStyle(
                                fontSize: 22,
                                fontWeight: FontWeight.bold),
                          ),
                          TextButton(
                            onPressed: () {},
                            child: const Text('See all',
                                style: TextStyle(color: Colors.grey)),
                          ),
                        ],
                      ),
                      const SizedBox(height: 0),
                      Expanded(
                        child: ListView.builder(
                          itemCount: _doctors.length,
                          itemBuilder: (context, index) {
                            final doctor = _doctors[index];
                            return Column(
                              children: [
                                DoctorCard(
                                  name: doctor.name,
                                  specialty: doctor.specialty,
                                  rating: doctor.rating,
                                  availableTimes:
                                  doctor.availableTimes,
                                  timerColor: Colors.yellow,
                                ),
                                const SizedBox(height: 10),
                              ],
                            );
                          },
                        ),
                      ),
                    ],
                  ),
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class DoctorCard extends StatelessWidget {
  final String name;
  final String specialty;
  final double rating;
  final String availableTimes;
  final Color timerColor;

  const DoctorCard({
    required this.name,
    required this.specialty,
    required this.rating,
    required this.availableTimes,
    required this.timerColor,
  });

  @override
  Widget build(BuildContext context) {
    final currentUser = UserManager().currentUser;

    return Card(
      color: Colors.white,
      elevation: 4,
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(10),
      ),
      child: Padding(
        padding: const EdgeInsets.all(7.0),
        child: Row(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            ClipRRect(
              borderRadius: BorderRadius.circular(10),
              child: Image.asset(
                'assets/doctor.jpg',
                width: 110,
                height: 105,
                fit: BoxFit.cover,
              ),
            ),
            const SizedBox(width: 16),
            Expanded(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  const SizedBox(height: 1),
                  Text(
                    name,
                    style: const TextStyle(
                      fontSize: 18,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  Text(
                    specialty,
                    style: const TextStyle(
                      fontSize: 16,
                      color: Colors.grey,
                    ),
                  ),
                  const SizedBox(height: 16),
                  Row(
                    children: [
                      Row(
                        children: [
                          const Icon(Icons.star, color: Colors.yellow),
                          const SizedBox(width: 4),
                          Text(
                            rating.toString(),
                            style: const TextStyle(
                              fontSize: 16,
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(width: 16),
                      Icon(Icons.timer, color: timerColor),
                      Text(
                        availableTimes,
                        style: const TextStyle(
                          fontSize: 12,
                        ),
                      ),
                      const SizedBox(width: 16),
                      if (currentUser is! Admin) ...[],
                    ],
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}
