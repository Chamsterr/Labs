import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';
import 'package:lab_04_05_06_part1_v2/widgets/news_section.dart';

void main() {
  group('NewsSection Widget Tests', () {
    final List<Map<String, dynamic>> sampleNews = [
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

    testWidgets('renders NewsSection with three news items', (WidgetTester tester) async {
      await tester.pumpWidget(
        MaterialApp(
          home: Scaffold(
            body: NewsSection(news: sampleNews),
          ),
        ),
      );

      expect(find.byType(ExpansionTile), findsNWidgets(3));
      expect(find.text('Breaking News 1'), findsOneWidget);
      expect(find.text('Breaking News 2'), findsOneWidget);
      expect(find.text('Breaking News 3'), findsOneWidget);
    });

    testWidgets('expands news item when tapped', (WidgetTester tester) async {
      await tester.pumpWidget(
        MaterialApp(
          home: Scaffold(
            body: NewsSection(news: sampleNews),
          ),
        ),
      );

      final firstNewsTile = find.text('Breaking News 1');
      expect(firstNewsTile, findsOneWidget);

      await tester.tap(firstNewsTile);
      await tester.pumpAndSettle();

      expect(find.text('This is the content of Breaking News 1.'), findsOneWidget);
    });

    testWidgets('allows scrolling and tapping news items', (WidgetTester tester) async {
      await tester.pumpWidget(
        MaterialApp(
          home: Scaffold(
            body: SizedBox(
              height: 200,
              child: NewsSection(news: sampleNews),
            ),
          ),
        ),
      );

      expect(find.text('Breaking News 1'), findsOneWidget);
      expect(find.text('Breaking News 2'), findsOneWidget);

      final firstNewsTile = find.text('Breaking News 1');
      expect(firstNewsTile, findsOneWidget);
      await tester.tap(firstNewsTile);
      await tester.pumpAndSettle();

      expect(find.text('This is the content of Breaking News 1.'), findsOneWidget);

      final secondNewsTile = find.text('Breaking News 2');
      expect(secondNewsTile, findsOneWidget);
      await tester.tap(secondNewsTile);
      await tester.pumpAndSettle();


      await tester.drag(find.byType(ListView), const Offset(0, -2000));
      await tester.pumpAndSettle();

      final thirdNewsTile = find.text('Breaking News 3');
      expect(thirdNewsTile, findsOneWidget);

      expect(find.text('Breaking News 3'), findsOneWidget);

      await tester.tap(thirdNewsTile);
      await tester.pumpAndSettle();

      expect(find.text('This is the content of Breaking News 3.'), findsOneWidget);
    });
  });
}
