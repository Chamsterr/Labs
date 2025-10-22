import 'package:flutter/material.dart';

class NewsSection extends StatelessWidget {
  final List<Map<String, dynamic>> news;

  const NewsSection({Key? key, required this.news}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      shrinkWrap: true,
      itemCount: news.length,
      itemBuilder: (context, index) {
        final newsItem = news[index];
        return Card(
          margin: const EdgeInsets.symmetric(vertical: 8.0),
          child: ExpansionTile(
            title: Text(newsItem['title'], style: const TextStyle(fontSize: 18)),
            children: [
              Padding(
                padding: const EdgeInsets.all(16.0),
                child: Text(
                  newsItem['content'],
                  style: const TextStyle(fontSize: 16),
                ),
              ),
            ],
          ),
        );
      },
    );
  }
}
