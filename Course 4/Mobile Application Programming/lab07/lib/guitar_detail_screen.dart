import 'package:flutter/material.dart';
import 'package:path_provider/path_provider.dart';
import 'dart:io';
import 'database_helper.dart';
import 'guitar.dart';

class GuitarDetailScreen extends StatefulWidget {
  final Guitar? guitar;
  final VoidCallback? onDelete;

  GuitarDetailScreen({this.guitar, this.onDelete});

  @override
  _GuitarDetailScreenState createState() => _GuitarDetailScreenState();
}

class _GuitarDetailScreenState extends State<GuitarDetailScreen> {
  final _formKey = GlobalKey<FormState>();
  String? _name;
  int? _strings;
  String? _savedData = '';
  String? _selectedDirectoryType;

  final List<Map<String, String>> _directories = [
    {'label': 'Temporary', 'type': 'Temporary'},
    {'label': 'Application Support', 'type': 'ApplicationSupport'},
    {'label': 'Application Documents', 'type': 'Documents'},
    {'label': 'Application Cache', 'type': 'Cache'},
    if (Platform.isIOS) ...[
      {'label': 'Application Library (iOS only)', 'type': 'ApplicationLibrary'},
    ],
    if (Platform.isAndroid) ...[
      {'label': 'External Storage (Android only)', 'type': 'ExternalStorage'},
      {'label': 'External Cache (Android only)', 'type': 'ExternalCache'},
      {'label': 'Downloads (Android only)', 'type': 'Downloads'},
    ],

  ];

  @override
  void initState() {
    super.initState();
    if (widget.guitar != null) {
      _name = widget.guitar!.name;
      _strings = widget.guitar!.strings;
    }
    _selectedDirectoryType = _directories.first['type'];
  }

  Future<String> _getDirectoryPath(String directoryType) async {
    Directory? directory;
    switch (directoryType) {
      case 'Documents':
        directory = await getApplicationDocumentsDirectory();
        break;
      case 'Temporary':
        directory = await getTemporaryDirectory();
        break;
      case 'ApplicationSupport':
        directory = await getApplicationSupportDirectory();
        break;
      case 'ApplicationLibrary':
        if (Platform.isIOS) {
          directory = await getLibraryDirectory();
        }
        break;
      case 'Cache':
        directory = await getApplicationCacheDirectory();
        break;
      case 'ExternalStorage':
        if (Platform.isAndroid) {
          directory = await getExternalStorageDirectory();
        }
        break;
      case 'ExternalCache':
        if (Platform.isAndroid) {
          directory = (await getExternalCacheDirectories())?.first;
        }
        break;
      case 'Downloads':
        if (Platform.isAndroid) {
          directory = await getDownloadsDirectory();
          print(directory);
        }
        break;
      default:
        directory = await getApplicationDocumentsDirectory();
    }
    print("directory?.path");
    print(directory?.path);
    return directory?.path ?? '';
  }

  Future<void> _saveGuitarToFile() async {
    final path = await _getDirectoryPath(_selectedDirectoryType!);
    final file = File('$path/guitar.txt');
    final data = 'Guitar Name: $_name, Strings: $_strings';

    try {
      await file.writeAsString(data);
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Data saved to $_selectedDirectoryType')));
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Error saving data: $e')));
    }
  }

  Future<void> _readGuitarFromFile() async {
    final path = await _getDirectoryPath(_selectedDirectoryType!);
    final file = File('$path/guitar.txt');
    print(file);
    try {
      if (await file.exists()) {
        final contents = await file.readAsString();
        setState(() {
          _savedData = contents;
        });
        ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Data read from $_selectedDirectoryType')));
      } else {
        setState(() {
          _savedData = 'File not found in $_selectedDirectoryType';
        });
      }
    } catch (e) {
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Error reading data: $e')));
    }
  }

  void _deleteGuitar() {
    showDialog(
      context: context,
      builder: (BuildContext context) {
        return AlertDialog(
          title: Text('Confirm Delete'),
          content: Text('Are you sure you want to delete this guitar?'),
          actions: [
            TextButton(
              onPressed: () {
                Navigator.of(context).pop();
              },
              child: Text('Cancel'),
            ),
            TextButton(
              onPressed: () async {
                if (widget.guitar != null) {
                  await DatabaseHelper().deleteGuitar(widget.guitar!.id!);
                  Navigator.of(context).pop();
                  Navigator.pop(context);
                  if (widget.onDelete != null) widget.onDelete!();
                }
              },
              child: Text('Delete'),
            ),
          ],
        );
      },
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(widget.guitar == null ? 'Add Guitar' : 'Edit Guitar')),
      body: Padding(
        padding: const EdgeInsets.all(16.0),
        child: Form(
          key: _formKey,
          child: SingleChildScrollView(
            child: Column(
              children: [
                TextFormField(
                  initialValue: _name,
                  decoration: InputDecoration(labelText: 'Name'),
                  validator: (value) => value!.isEmpty ? 'Please enter a name' : null,
                  onSaved: (value) => _name = value,
                ),
                TextFormField(
                  initialValue: _strings?.toString(),
                  decoration: InputDecoration(labelText: 'Number of Strings'),
                  keyboardType: TextInputType.number,
                  validator: (value) {
                    if (value!.isEmpty) {
                      return 'Please enter the number of strings';
                    }
                    final n = int.tryParse(value);
                    return n == null || n <= 0 ? 'Please enter a valid number' : null;
                  },
                  onSaved: (value) => _strings = int.tryParse(value!),
                ),
                SizedBox(height: 20),
                ElevatedButton(
                  onPressed: () {
                    if (_formKey.currentState!.validate()) {
                      _formKey.currentState!.save();
                      if (widget.guitar == null) {
                        DatabaseHelper().insertGuitar(Guitar(name: _name!, strings: _strings!));
                      } else {
                        DatabaseHelper().updateGuitar(Guitar(id: widget.guitar!.id, name: _name!, strings: _strings!));
                      }
                      Navigator.pop(context);
                    }
                  },
                  child: Text(widget.guitar == null ? 'Add' : 'Update'),
                ),
                SizedBox(height: 20),
                if (widget.guitar != null)
                  ElevatedButton(
                    onPressed: _deleteGuitar,
                    child: Text('Delete'),
                    style: ElevatedButton.styleFrom(backgroundColor: Colors.red),
                  ),
                SizedBox(height: 20),

                DropdownButton<String>(
                  value: _selectedDirectoryType,
                  onChanged: (String? newValue) {
                    setState(() {
                      _selectedDirectoryType = newValue;
                    });
                  },
                  items: _directories.map((directory) {
                    return DropdownMenuItem<String>(
                      value: directory['type'],
                      child: Text(directory['label']!),
                    );
                  }).toList(),
                ),

                ElevatedButton(
                  onPressed: _saveGuitarToFile,
                  child: Text('Save to Selected Directory'),
                ),
                ElevatedButton(
                  onPressed: _readGuitarFromFile,
                  child: Text('Read from Selected Directory'),
                ),

                if (_savedData != null) Text('Read Data: $_savedData'),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
