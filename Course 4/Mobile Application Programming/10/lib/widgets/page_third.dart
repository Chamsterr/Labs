import 'package:flutter/material.dart';

class PageThird extends StatefulWidget {
  const PageThird({super.key});

  @override
  _PageThirdState createState() => _PageThirdState();
}

class _PageThirdState extends State<PageThird> {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Hello Page'),
        backgroundColor: Colors.blue,
      ),
      body: const Center(
        child: Text(
          'Hello',
          style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold),
          textAlign: TextAlign.center,
        ),
      ),
    );
  }
}
