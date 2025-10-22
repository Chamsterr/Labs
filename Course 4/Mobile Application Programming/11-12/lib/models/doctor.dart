import 'package:cloud_firestore/cloud_firestore.dart';

class Doctor {
  final String id;
  final String name;
  final String specialty;
  final double rating;
  final String availableTimes;
  final int timerColorValue;
  final String title;

  Doctor({
    required this.id,
    required this.name,
    required this.specialty,
    required this.rating,
    required this.availableTimes,
    required this.timerColorValue,
    required this.title,
  });

  get timerColor => null;

  // Static method to create Doctor from Firestore document
  static Doctor fromFirestore(QueryDocumentSnapshot<Map<String, dynamic>> doc) {
    final data = doc.data() as Map<String, dynamic>;
    return Doctor(
      id: doc.id,
      name: data['name'] ?? '',
      specialty: data['specialty'] ?? '',
      rating: (data['rating'] ?? 0.0).toDouble(),
      availableTimes: data['availableTimes'] ?? '',
      timerColorValue: data['timerColorValue'] ?? 0,
      title: data['title'] ?? '',
    );
  }

  // Method to convert Doctor to Firestore map
  Map<String, dynamic> toFirestore() {
    return {
      'name': name,
      'specialty': specialty,
      'rating': rating,
      'availableTimes': availableTimes,
      'timerColorValue': timerColorValue,
      'title': title,
    };
  }

}
