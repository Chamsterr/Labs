import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:lab_04_05_06_part1_v2/widgets/service_button_bloc.dart';
import 'package:lab_04_05_06_part1_v2/widgets/service_button_data.dart';
import 'package:lab_04_05_06_part1_v2/widgets/service_buttons.dart';
import 'package:lab_04_05_06_part1_v2/widgets/events.dart';
import 'header.dart';
import 'search_bar.dart' as my_search_bar;
import 'info_card.dart';
import 'page_third.dart';

class MainPage extends StatelessWidget {
  const MainPage({super.key});

  @override
  Widget build(BuildContext context) {
    return BlocProvider(
      create: (_) => ServiceButtonBloc()
        ..add(LoadServiceButtons(buttons: [
          ServiceButtonData(
            title: 'Diagnostic',
            icon: Icons.medical_services,
            backgroundColor: Colors.white,
            textColor: Colors.orange,
            borderColor: Colors.white,
            isNavigable: true,
            doctors: [
              Doctor(name: 'Dr. Smith1', specialty: 'Cardiology', rating: 5.0, availableTimes: "10:00 AM - 3:00 PM", timerColor: Colors.blue),
            ],
          ),
        ])),
      child: Scaffold(
        body: PageView(
          physics: const BouncingScrollPhysics(),
          children: <Widget>[
            buildMainContent(),
            const PageThird(),
          ],
        ),
      ),
    );
  }

  Widget buildMainContent() {
    return const SafeArea(
      child: Padding(
        padding: EdgeInsets.all(33.0),
        child: SingleChildScrollView(
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
      ),
    );
  }
}
