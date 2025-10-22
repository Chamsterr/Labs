import 'package:flutter/material.dart';

Widget buildServiceButton(String? title, IconData icon, Color iconColor, Color backgroundColor, Color textColor) {
  return Container(
    height: 90,
    width: 100,
    padding: const EdgeInsets.all(11),
    decoration: BoxDecoration(
      color: backgroundColor,
      borderRadius: BorderRadius.circular(15),
      boxShadow: [
        BoxShadow(
          color: Colors.black.withOpacity(0.2),
          spreadRadius: 2,
          blurRadius: 5,
          offset: const Offset(0, 3),
        ),
      ],
    ),
    child: Column(
      mainAxisAlignment: MainAxisAlignment.center,
      children: [
        Icon(
          icon,
          color: iconColor,
          size: title == null ? 40 : 32,
        ),
        if (title != null) ...[
          const SizedBox(height: 8),
          Text(
            title,
            style: TextStyle(
              fontSize: 10,
              fontWeight: FontWeight.bold,
              color: textColor,
            ),
            textAlign: TextAlign.center,
          ),
        ],
      ],
    ),
  );
}
