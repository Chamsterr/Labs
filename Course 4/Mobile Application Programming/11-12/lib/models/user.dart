import 'package:hive/hive.dart';

@HiveType(typeId: 1)
class User {
  @HiveField(0)
  final String id;

  @HiveField(1)
  final String name;

  @HiveField(2)
  final String role;

  User({required this.id, required this.name, required this.role});
}

@HiveType(typeId: 2)
class Admin extends User {
  Admin({required String id, required String name})
      : super(id: id, name: name, role: 'Admin');
}

@HiveType(typeId: 3)
class RegularUser extends User {
  RegularUser({required String id, required String name})
      : super(id: id, name: name, role: 'User');
}


class UserAdapter extends TypeAdapter<User> {
  @override
  final int typeId = 1;

  @override
  User read(BinaryReader reader) {
    final id = reader.readString();
    final name = reader.readString();
    final role = reader.readString();
    return User(id: id, name: name, role: role);
  }

  @override
  void write(BinaryWriter writer, User obj) {
    writer.writeString(obj.id);
    writer.writeString(obj.name);
    writer.writeString(obj.role);
  }
}

class AdminAdapter extends TypeAdapter<Admin> {
  @override
  final int typeId = 2;

  @override
  Admin read(BinaryReader reader) {
    final id = reader.readString();
    final name = reader.readString();
    return Admin(id: id, name: name);
  }

  @override
  void write(BinaryWriter writer, Admin obj) {
    writer.writeString(obj.id);
    writer.writeString(obj.name);
  }
}

class RegularUserAdapter extends TypeAdapter<RegularUser> {
  @override
  final int typeId = 3;

  @override
  RegularUser read(BinaryReader reader) {
    final id = reader.readString();
    final name = reader.readString();
    return RegularUser(id: id, name: name);
  }

  @override
  void write(BinaryWriter writer, RegularUser obj) {
    writer.writeString(obj.id);
    writer.writeString(obj.name);
  }
}
