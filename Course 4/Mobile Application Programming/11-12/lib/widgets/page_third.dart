// import 'package:flutter/material.dart';
//
// class PageThird extends StatelessWidget {
//   const PageThird({super.key});
//
//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(title: const Text('Doctors')),
//       body: Center(
//         child: ElevatedButton(
//           onPressed: () {
//             // Здесь можно добавить логику для добавления доктора, если нужно
//             print('Add Doctor button pressed');
//           },
//           child: const Text('Add Doctor'),
//         ),
//       ),
//     );
//   }
// }


import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:lab_04_05_06_part1_v2/models/user.dart';
import '../models/user_manager.dart';

class PageThird extends StatefulWidget {
  const PageThird({super.key});

  @override
  _PageThirdState createState() => _PageThirdState();
}

class _PageThirdState extends State<PageThird> {
  String? selectedRole;
  List<Map<String, dynamic>> doctors = [];
  bool isLoading = true;

  @override
  void initState() {
    super.initState();
    _loadData();
  }

  Future<void> _loadData() async {
    setState(() {
      isLoading = true;
    });

    try {
      print('Loading current user...');
      await _loadCurrentUser();
      print('Loading doctors...');
      await _loadDoctors();
    } catch (e) {
      print('Error during loading data: $e');
    } finally {
      setState(() {
        isLoading = false;
      });
    }
  }

  Future<void> _loadCurrentUser() async {
    try {
      final userDoc = await FirebaseFirestore.instance.collection('users').doc('user_id').get();
      if (userDoc.exists) {
        UserManager().setCurrentUser(userDoc.data() as User?);
        selectedRole = userDoc.data()?['role'];
        print('Current user loaded: $selectedRole');
      } else {
        print('User not found.');
      }
    } catch (e) {
      print('Error loading user: $e');
    }
  }

  Future<void> _loadDoctors() async {
    try {
      final doctorSnapshot = await FirebaseFirestore.instance.collection('doctors').get();
      setState(() {
        doctors = doctorSnapshot.docs.map((doc) => {'id': doc.id, ...doc.data()}).toList();
        print('Doctors loaded: ${doctors.length}');
      });
    } catch (e) {
      print('Error loading doctors: $e');
    }
  }

  Future<void> _addDoctor() async {
    await _showDoctorDialog();
  }

  Future<void> _editDoctor(Map<String, dynamic> doctor) async {
    await _showDoctorDialog(doctor: doctor);
  }

  Future<void> _deleteDoctor(String doctorId) async {
    if (isLoading) return;

    setState(() {
      isLoading = true;
    });

    try {
      print('Deleting doctor with ID: $doctorId');
      await FirebaseFirestore.instance.collection('doctors').doc(doctorId).delete();

      await _loadDoctors();
    } catch (e) {
      print('Error deleting doctor: $e');
    } finally {
      setState(() {
        isLoading = false;
      });
    }
  }

  Future<void> _showDoctorDialog({Map<String, dynamic>? doctor}) async {
    final TextEditingController nameController = TextEditingController(text: doctor?['name'] ?? '');
    final TextEditingController specialtyController = TextEditingController(text: doctor?['specialty'] ?? '');
    final TextEditingController ratingController = TextEditingController(text: doctor?['rating']?.toString() ?? '0');
    final TextEditingController availableTimesController = TextEditingController(text: doctor?['availableTimes'] ?? '');
    final TextEditingController timerColorController = TextEditingController(text: doctor?['timerColorValue']?.toString() ?? '0');
    final TextEditingController titleController = TextEditingController(text: doctor?['title'] ?? '');

    await showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text(doctor == null ? 'Add Doctor' : 'Edit Doctor'),
          content: SingleChildScrollView(
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                TextField(
                  controller: nameController,
                  decoration: const InputDecoration(labelText: 'Doctor Name'),
                ),
                TextField(
                  controller: specialtyController,
                  decoration: const InputDecoration(labelText: 'Specialty'),
                ),
                TextField(
                  controller: ratingController,
                  keyboardType: TextInputType.number,
                  decoration: const InputDecoration(labelText: 'Rating'),
                ),
                TextField(
                  controller: availableTimesController,
                  decoration: const InputDecoration(labelText: 'Available Times'),
                ),
                TextField(
                  controller: timerColorController,
                  decoration: const InputDecoration(labelText: 'Timer Color Value'),
                ),
                TextField(
                  controller: titleController,
                  decoration: const InputDecoration(labelText: 'Title'),
                ),
              ],
            ),
          ),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Cancel'),
            ),
            TextButton(
              onPressed: () async {
                final newDoctor = {
                  'name': nameController.text,
                  'specialty': specialtyController.text,
                  'rating': double.tryParse(ratingController.text) ?? 0,
                  'availableTimes': availableTimesController.text,
                  'timerColorValue': int.tryParse(timerColorController.text) ?? 0,
                  'title': titleController.text,
                };


                if (nameController.text.isEmpty || specialtyController.text.isEmpty) {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(content: Text('Name and specialty cannot be empty')),
                  );
                  return;
                }

                try {
                  setState(() {
                    isLoading = true;
                  });

                  if (doctor == null) {

                    await FirebaseFirestore.instance.collection('doctors').add(newDoctor);
                  } else {

                    await FirebaseFirestore.instance
                        .collection('doctors')
                        .doc(doctor['id'])
                        .update(newDoctor);
                  }


                  await _loadDoctors();
                  Navigator.of(context).pop();

                } catch (e) {
                  print('Error saving doctor: $e');
                } finally {
                  setState(() {
                    isLoading = false;
                  });
                }
              },
              child: const Text('Save'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: const Text('Doctors')),
      body: isLoading
          ? const Center(child: CircularProgressIndicator())
          : Column(
        children: [
          Row(
            children: [
              ElevatedButton(
                onPressed: _addDoctor,
                child: const Text('Add Doctor'),
              ),
            ],
          ),
          Expanded(
            child: ListView.builder(
              itemCount: doctors.length,
              itemBuilder: (context, index) {
                final doctor = doctors[index];
                return ListTile(
                  title: Text(doctor['name']),
                  subtitle: Text(doctor['specialty']),
                  trailing: Row(
                    mainAxisSize: MainAxisSize.min,
                    children: [
                      IconButton(
                        icon: const Icon(Icons.edit),
                        onPressed: () => _editDoctor(doctor),
                      ),
                      IconButton(
                        icon: const Icon(Icons.delete),
                        onPressed: () => _deleteDoctor(doctor['id']),
                      ),
                    ],
                  ),
                );
              },
            ),
          ),
        ],
      ),
    );
  }
}
