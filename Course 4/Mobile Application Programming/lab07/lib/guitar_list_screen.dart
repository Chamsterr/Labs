import 'package:flutter/material.dart';
import 'database_helper.dart';
import 'guitar.dart';
import 'guitar_detail_screen.dart';

class GuitarListScreen extends StatefulWidget {
  @override
  _GuitarListScreenState createState() => _GuitarListScreenState();
}

class _GuitarListScreenState extends State<GuitarListScreen> {
  late Future<List<Guitar>> futureGuitars;

  @override
  void initState() {
    super.initState();
    futureGuitars = DatabaseHelper().getGuitars();
  }

  void _refreshGuitarList() {
    setState(() {
      futureGuitars = DatabaseHelper().getGuitars();
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Guitar List')),
      body: FutureBuilder<List<Guitar>>(
        future: futureGuitars,
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return Center(child: CircularProgressIndicator());
          } else if (snapshot.hasError) {
            return Center(child: Text('Error: ${snapshot.error}'));
          } else if (!snapshot.hasData || snapshot.data!.isEmpty) {
            return Center(child: Text('No guitars found.'));
          }

          final guitars = snapshot.data!;
          return ListView.builder(
            itemCount: guitars.length,
            itemBuilder: (context, index) {
              return ListTile(
                title: Text(guitars[index].name),
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => GuitarDetailScreen(
                        guitar: guitars[index],
                        onDelete: _refreshGuitarList,
                      ),
                    ),
                  ).then((_) => _refreshGuitarList());
                },
              );
            },
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => GuitarDetailScreen(onDelete: _refreshGuitarList), // Pass the callback here
            ),
          ).then((_) => _refreshGuitarList()); // Ensure refresh on return
        },
        child: Icon(Icons.add),
      ),
    );
  }
}
