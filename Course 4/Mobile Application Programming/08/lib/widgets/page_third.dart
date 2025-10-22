import 'package:flutter/material.dart';
import 'package:hive/hive.dart';
import '../models/user.dart';
import '../models/favorite_doctor.dart';
import '../models/user_manager.dart';
import '../models/DoctorHive.dart' as doctor_hive;

class PageThird extends StatefulWidget {
  const PageThird({super.key});

  @override
  _PageThirdState createState() => _PageThirdState();
}

class _PageThirdState extends State<PageThird> {
  String? selectedRole;
  List<FavoriteDoctor> favoriteDoctors = [];
  List<doctor_hive.Doctor> doctors = [];

  @override
  void initState() {
    super.initState();
    final userBox = Hive.box<User>('users');

    User? user = userBox.get('user_id');
    if (user != null) {
      UserManager().setCurrentUser(user);
    }

    selectedRole = userBox.get('selectedRole')?.role;

    _loadFavoriteDoctors();
    _loadDoctors();
  }

  void _loadFavoriteDoctors() {
    final favoritesBox = Hive.box<FavoriteDoctor>('favorites');
    final currentUserId = UserManager().currentUser?.id;

    setState(() {
      favoriteDoctors = favoritesBox.values
          .where((doctor) => doctor.userId == currentUserId)
          .toList();
    });
  }

  void _loadDoctors() {
    final doctorBox = Hive.box<doctor_hive.Doctor>('doctors');
    setState(() {
      doctors = doctorBox.values.toList();
    });
  }

  void _onRoleChanged(String? value) {
    setState(() {
      selectedRole = value;
      if (selectedRole == 'Admin') {
        UserManager().setCurrentUser(Hive.box<User>('users').get('admin_id'));
      } else {
        UserManager().setCurrentUser(Hive.box<User>('users').get('user_id'));
      }
    });

    Hive.box<User>('users').put('selectedRole', UserManager().currentUser!);
    _loadFavoriteDoctors();
  }

  void _addDoctor() {
    _showDoctorDialog();
  }

  void _editDoctor(doctor_hive.Doctor doctor) {
    _showDoctorDialog(doctor: doctor);
  }

  void _deleteDoctor(doctor_hive.Doctor doctor) {
    final doctorBox = Hive.box<doctor_hive.Doctor>('doctors');
    final favoritesBox = Hive.box<FavoriteDoctor>('favorites');

    setState(() {
      doctorBox.delete(doctor.name);

      final List<int> keysToRemove = favoritesBox.keys
          .where((key) =>
      (favoritesBox.get(key) as FavoriteDoctor).name == doctor.name)
          .cast<int>()
          .toList();

      for (var key in keysToRemove) {
        favoritesBox.delete(key);
      }

      _loadDoctors();
      _loadFavoriteDoctors();
    });
  }

  void _showDoctorDialog({doctor_hive.Doctor? doctor}) {
    final TextEditingController nameController =
    TextEditingController(text: doctor?.name ?? '');
    final TextEditingController specialtyController =
    TextEditingController(text: doctor?.specialty ?? '');
    final TextEditingController ratingController =
    TextEditingController(text: doctor?.rating.toString() ?? '0');
    final TextEditingController availableTimesController =
    TextEditingController(text: doctor?.availableTimes ?? '');
    final TextEditingController timerColorController =
    TextEditingController(text: doctor?.timerColorValue.toString() ?? '0');
    final TextEditingController titleController =
    TextEditingController(text: doctor?.title ?? '');

    showDialog(
      context: context,
      builder: (context) {
        return AlertDialog(
          title: Text(doctor == null ? 'Add Doctor' : 'Edit Doctor'),
          content: Column(
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
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: const Text('Cancel'),
            ),
            TextButton(
              onPressed: () {
                final doctorBox = Hive.box<doctor_hive.Doctor>('doctors');

                final newDoctor = doctor_hive.Doctor(
                  name: nameController.text,
                  specialty: specialtyController.text,
                  rating: double.tryParse(ratingController.text) ?? 0,
                  availableTimes: availableTimesController.text,
                  timerColorValue: int.tryParse(timerColorController.text) ?? 0,
                  title: titleController.text,
                );

                if (doctor == null) {
                  // Adding a new doctor
                  doctorBox.put(newDoctor.name, newDoctor);
                } else {
                  // Editing an existing doctor
                  doctorBox.put(doctor.name, newDoctor);
                }

                _loadDoctors();
                Navigator.of(context).pop();
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
      appBar: AppBar(
        title: const Text('Hello Page'),
        backgroundColor: Colors.blue,
      ),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: <Widget>[
          const Text(
            'Select User Role:',
            style: TextStyle(fontSize: 20),
          ),
          ListTile(
            title: const Text('Admin'),
            leading: Radio<String>(
              value: 'Admin',
              groupValue: selectedRole,
              onChanged: _onRoleChanged,
            ),
          ),
          ListTile(
            title: const Text('Regular User'),
            leading: Radio<String>(
              value: 'User',
              groupValue: selectedRole,
              onChanged: _onRoleChanged,
            ),
          ),
          const SizedBox(height: 20),
          if (UserManager().currentUser != null) ...[
            Text(
              'Current User: ${UserManager().currentUser!.name}',
              style: const TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
            ),
            const SizedBox(height: 10),
            Text(
              'Role: ${selectedRole ?? 'Not selected'}',
              style: const TextStyle(fontSize: 16),
            ),
          ],
          const SizedBox(height: 20),
          if (selectedRole == 'Admin') ...[
            const Text(
              'Manage Doctors:',
              style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
            ),
            ElevatedButton(
              onPressed: _addDoctor,
              child: const Text('Add Doctor'),
            ),
            Expanded(
              child: ListView.builder(
                itemCount: doctors.length,
                itemBuilder: (context, index) {
                  final doctor = doctors[index];
                  return ListTile(
                    title: Text(doctor.name),
                    subtitle: Text('Specialty: ${doctor.specialty}'),
                    trailing: Row(
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        IconButton(
                          icon: const Icon(Icons.edit),
                          onPressed: () => _editDoctor(doctor),
                        ),
                        IconButton(
                          icon: const Icon(Icons.delete),
                          onPressed: () => _deleteDoctor(doctor),
                        ),
                      ],
                    ),
                  );
                },
              ),
            ),
          ],
          if (UserManager().currentUser?.role != 'Admin') ...[
            const Text(
              'Favorite Doctors:',
              style: TextStyle(fontSize: 20, fontWeight: FontWeight.bold),
            ),
            Expanded(
              child: ListView.builder(
                itemCount: favoriteDoctors.length,
                itemBuilder: (context, index) {
                  final doctor = favoriteDoctors[index];
                  return ListTile(
                    title: Text(doctor.name),
                    subtitle: Text('Specialty: ${doctor.specialty} - Rating: ${doctor.rating}'),
                  );
                },
              ),
            ),
          ],
        ],
      ),
    );
  }
}
