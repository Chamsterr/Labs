import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:lab_04_05_06_part1_v2/widgets/search_bar.dart' as my_search_bar;
import 'package:lab_04_05_06_part1_v2/widgets/info_card.dart';

void main() {

  group('MainPage Widget Tests', () {

    testWidgets('Enter text in SearchBar updates text', (WidgetTester tester) async {
      await tester.pumpWidget(const MaterialApp(
        home: Scaffold(body: my_search_bar.SearchBar()),
      ));

      final textField = find.byType(TextField);
      expect(textField, findsOneWidget);

      await tester.enterText(textField, 'Search for doctors');
      await tester.pump();

      expect(find.text('Search for doctors'), findsOneWidget);
    });

    testWidgets('InfoCard is displayed with correct content', (WidgetTester tester) async {
      await tester.pumpWidget(const MaterialApp(
        home: Scaffold(body: InfoCard()),
      ));

      expect(find.byType(InfoCard), findsOneWidget);

    });
  });
}
