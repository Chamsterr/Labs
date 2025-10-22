import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'second_page.dart';
import 'service_button_provider.dart';
import 'build_service_button.dart';

class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  @override
  Widget build(BuildContext context) {
    final buttons = Provider.of<ServiceButtonProvider>(context).buttons;

    return Column(
      children: [
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            for (var button in buttons.take(3))
              GestureDetector(
                onTap: button.isNavigable
                    ? () {
                  context.read<ServiceButtonProvider>().setSelectedButton(button);
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => SecondPage(),
                    ),
                  );
                }
                    : null,
                child: buildServiceButton(
                  button.title,
                  button.icon,
                  button.backgroundColor,
                  button.textColor,
                  button.borderColor,
                ),
              ),
          ],
        ),
        const SizedBox(height: 22),
        Row(
          mainAxisAlignment: MainAxisAlignment.spaceBetween,
          children: <Widget>[
            for (var button in buttons.skip(3))
              GestureDetector(
                onTap: button.isNavigable
                    ? () {
                  context.read<ServiceButtonProvider>().setSelectedButton(button);
                }
                    : null,
                child: buildServiceButton(
                  button.title,
                  button.icon,
                  button.backgroundColor,
                  button.textColor,
                  button.borderColor,
                ),
              ),
          ],
        ),
      ],
    );
  }
}
