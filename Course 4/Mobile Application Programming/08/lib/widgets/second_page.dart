import 'package:flutter/material.dart';
import 'package:hive/hive.dart';
import '../models/favorite_doctor.dart';
import '../models/user.dart';
import '../models/DoctorHive.dart';
import '../models/user_manager.dart';
import 'build_service_button.dart';


class SecondPage extends StatelessWidget {
  final List<Doctor> doctors;

  const SecondPage({super.key, required this.doctors});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Colors.blue,
      ),
      backgroundColor: Colors.blue,
      body: Padding(
        padding: const EdgeInsets.all(0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Container(
              margin: const EdgeInsets.all(0),
              width: double.infinity,
              padding: const EdgeInsets.fromLTRB(50.0, 80.0, 30.0, 30.0),
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
                        mainAxisAlignment: MainAxisAlignment.spaceBetween,
                        children: [
                          const Text(
                            'Categories',
                            style: TextStyle(fontSize: 22, fontWeight: FontWeight.bold),
                          ),
                          TextButton(
                            onPressed: () {},
                            child: const Text('See all', style: TextStyle(color: Colors.grey)),
                          ),
                        ],
                      ),
                      const SizedBox(height: 0),
                      Expanded(
                        child: ListView.builder(
                          itemCount: doctors.length,
                          itemBuilder: (context, index) {
                            final doctor = doctors[index];
                            return Column(
                              children: [
                                DoctorCard(
                                  name: doctor.name,
                                  specialty: doctor.specialty,
                                  rating: doctor.rating,
                                  availableTimes: doctor.availableTimes,
                                  timerColor: doctor.timerColor,
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


class DoctorCard extends StatefulWidget {
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
  _DoctorCardState createState() => _DoctorCardState();
}

class _DoctorCardState extends State<DoctorCard> {
  late bool isFavorite;

  @override
  void initState() {
    super.initState();
    isFavorite = _checkIfFavorite();
  }

  bool _checkIfFavorite() {
    final favoritesBox = Hive.box<FavoriteDoctor>('favorites');
    final currentUser = UserManager().currentUser;
    return favoritesBox.values.any((doctor) =>
    doctor.name == widget.name && doctor.userId == currentUser?.id);
  }

  void _toggleFavorite() {
    final favoritesBox = Hive.box<FavoriteDoctor>('favorites');
    final currentUser = UserManager().currentUser;

    if (currentUser == null) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Пожалуйста, войдите в систему для добавления в избранное.'),
        ),
      );
      return;
    }

    if (currentUser is Admin) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Администраторы не могут добавлять докторов в избранное.'),
        ),
      );
      return;
    }

    final favoriteDoctor = FavoriteDoctor(
      name: widget.name,
      specialty: widget.specialty,
      rating: widget.rating,
      userId: currentUser.id,
    );

    if (isFavorite) {
      favoritesBox.deleteAll(favoritesBox.keys.where((key) {
        final doc = favoritesBox.get(key);
        return doc != null &&
            doc.name == widget.name &&
            doc.userId == currentUser.id;
      }));
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text('${widget.name} убран из избранного!'),
        ),
      );
    } else {
      favoritesBox.add(favoriteDoctor);
      ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(
          content: Text('${widget.name} добавлен в избранное!'),
        ),
      );
    }

    setState(() {
      isFavorite = !isFavorite;
    });
  }

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
                    widget.name,
                    style: const TextStyle(
                      fontSize: 18,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  Text(
                    widget.specialty,
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
                            widget.rating.toString(),
                            style: const TextStyle(
                              fontSize: 16,
                              fontWeight: FontWeight.bold,
                            ),
                          ),
                        ],
                      ),
                      const SizedBox(width: 16),
                      Icon(Icons.timer, color: widget.timerColor),
                      Text(
                        '${widget.availableTimes}',
                        style: const TextStyle(
                          fontSize: 12,
                        ),
                      ),
                      const SizedBox(width: 16),
                      if (currentUser is! Admin) ...[
                        IconButton(
                          icon: Icon(
                            isFavorite ? Icons.favorite : Icons.favorite_border,
                            color: isFavorite ? Colors.red : Colors.grey,
                          ),
                          onPressed: _toggleFavorite,
                        ),
                      ],
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

