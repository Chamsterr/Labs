import 'package:flutter/material.dart';
import 'header.dart';
import 'search_bar.dart' as my_search_bar;
import 'service_buttons.dart';
import 'info_card.dart';
import 'page_third.dart';

class MainPage extends StatelessWidget {
  const MainPage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: PageView(
        physics: const BouncingScrollPhysics(),
        children: <Widget>[
          buildMainContent(),
          const PageThird(),
        ],
      ),
    );
  }

  Widget buildMainContent() {
    return const SafeArea(
      child: Padding(
        padding: EdgeInsets.all(33.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: <Widget>[
            Header(),
            SizedBox(height: 50),
            Text('Hello,', style: TextStyle(fontSize: 30)),
            Text(
              'Mikita!',
              style: TextStyle(fontSize: 30, fontWeight: FontWeight.bold, color: Colors.black),
            ),
            SizedBox(height: 20),
            my_search_bar.SearchBar(),
            SizedBox(height: 20),
            InfoCard(),
            SizedBox(height: 20),
            Text('What do you need?', style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold)),
            SizedBox(height: 20),
            ServiceButtons(),
          ],
        ),
      ),
    );
  }
}
