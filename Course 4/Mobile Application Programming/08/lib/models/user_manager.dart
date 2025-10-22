import 'package:lab_04_05_06_part1_v2/models/user.dart';

import '../models/user.dart';

class UserManager {
  static final UserManager _instance = UserManager._internal();
  User? _currentUser;

  factory UserManager() {
    return _instance;
  }

  UserManager._internal();

  User? get currentUser => _currentUser;

  void setCurrentUser(User? user) {
    _currentUser = user;
  }
}
