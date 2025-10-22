import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import 'guitar.dart';

class DatabaseHelper {
  static final DatabaseHelper _instance = DatabaseHelper._internal();
  factory DatabaseHelper() => _instance;

  DatabaseHelper._internal();

  static Database? _database;

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDatabase();
    return _database!;
  }

  Future<Database> _initDatabase() async {
    String path = join(await getDatabasesPath(), 'guitars.db');
    return await openDatabase(
      path,
      version: 1,
      onCreate: (db, version) {
        return db.execute(
          'CREATE TABLE guitars(id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, strings INTEGER)',
        );
      },
    );
  }

  Future<void> insertGuitar(Guitar guitar) async {
    final db = await database;
    await db.insert('guitars', guitar.toMap(),
        conflictAlgorithm: ConflictAlgorithm.replace);
  }

  Future<List<Guitar>> getGuitars() async {
    final db = await database;
    final List<Map<String, dynamic>> maps = await db.query('guitars');
    return List.generate(maps.length, (i) {
      return Guitar.fromMap(maps[i]);
    });
  }

  Future<void> updateGuitar(Guitar guitar) async {
    final db = await database;
    await db.update('guitars', guitar.toMap(),
        where: 'id = ?', whereArgs: [guitar.id]);
  }

  Future<void> deleteGuitar(int id) async {
    final db = await database;
    await db.delete('guitars', where: 'id = ?', whereArgs: [id]);
  }
}
