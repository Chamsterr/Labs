import 'package:hive/hive.dart';

@HiveType(typeId: 1) // FavoriteDoctor
class FavoriteDoctor {
  @HiveField(0)
  final String userId;

  @HiveField(1)
  final String name;

  @HiveField(2)
  final String specialty;

  @HiveField(3)
  final double rating;

  FavoriteDoctor({
    required this.userId,
    required this.name,
    required this.specialty,
    required this.rating,
  });
}

class FavoriteDoctorAdapter extends TypeAdapter<FavoriteDoctor> {
  @override
  final int typeId = 1;

  @override
  FavoriteDoctor read(BinaryReader reader) {
    final userId = reader.readString();
    final name = reader.readString();
    final specialty = reader.readString();
    final rating = reader.readDouble();
    return FavoriteDoctor(userId: userId, name: name, specialty: specialty, rating: rating);
  }

  @override
  void write(BinaryWriter writer, FavoriteDoctor obj) {
    writer.writeString(obj.userId);
    writer.writeString(obj.name);
    writer.writeString(obj.specialty);
    writer.writeDouble(obj.rating);
  }
}
