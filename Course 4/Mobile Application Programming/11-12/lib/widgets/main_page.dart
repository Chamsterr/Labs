import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:firebase_messaging/firebase_messaging.dart';
import 'header.dart';
import 'search_bar.dart' as my_search_bar;
import 'service_buttons.dart';
import 'info_card.dart';
import 'page_third.dart';
import '/widgets/news_section.dart';

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  _MainPageState createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  FirebaseMessaging _firebaseMessaging = FirebaseMessaging.instance;

  final List<Map<String, dynamic>> _news = [
    {
      'title': 'Breaking News 1',
      'content': 'This is the content of Breaking News 1.',
      'expanded': false,
    },
    {
      'title': 'Breaking News 2',
      'content': 'This is the content of Breaking News 2.',
      'expanded': false,
    },
    {
      'title': 'Breaking News 3',
      'content': 'This is the content of Breaking News 3.',
      'expanded': false,
    },
  ];

  @override
  void initState() {
    super.initState();

    FirebaseMessaging.onMessage.listen((RemoteMessage message) {
      if (message.notification != null) {
        print('Received a message: ${message.notification?.title}');
        print('Message body: ${message.notification?.body}');
      }
    });

    _firebaseMessaging.getToken().then((token) {
      print("Firebase Messaging token: $token");
    });
  }

  @override
  Widget build(BuildContext context) {
    final user = FirebaseAuth.instance.currentUser;

    return Scaffold(
      appBar: AppBar(
        title: const Text('Main Page'),
        actions: [
          if (user != null)
            IconButton(
              icon: const Icon(Icons.account_circle),
              onPressed: () {
                Navigator.pushNamed(context, '/profile');
              },
            ),
        ],
      ),
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
    return SafeArea(
      child: SingleChildScrollView(
        child: Padding(
          padding: const EdgeInsets.all(33.0),
          child: Column(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: <Widget>[
              const Header(),
              const SizedBox(height: 50),
              const Text('Hello', style: TextStyle(fontSize: 30)),
              const SizedBox(height: 20),
              const my_search_bar.SearchBar(),
              const SizedBox(height: 20),
              const InfoCard(),
              const SizedBox(height: 20),
              const Text(
                'What do you need?',
                style: TextStyle(fontSize: 25, fontWeight: FontWeight.bold),
              ),
              const SizedBox(height: 20),
              const ServiceButtons(),
              const SizedBox(height: 20),
              buildNewsSection(),
            ],
          ),
        ),
      ),
    );
  }

  Widget buildNewsSection() {
    return NewsSection(news: _news);
  }
}