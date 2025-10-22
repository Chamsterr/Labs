import 'package:flutter/material.dart';
import 'package:flutter_bloc/flutter_bloc.dart';
import 'service_button_bloc.dart';
import 'state.dart';
import 'second_page.dart';
import 'build_service_button.dart';
import 'events.dart';
import 'service_button_data.dart';

class ServiceButtons extends StatelessWidget {
  const ServiceButtons({super.key});

  @override
  Widget build(BuildContext context) {
    final TextEditingController titleController = TextEditingController();

    return Column(
      children: [
        TextField(
          controller: titleController,
          decoration: const InputDecoration(
            labelText: 'Название кнопки',
            border: OutlineInputBorder(),
          ),
        ),
        ElevatedButton(
          onPressed: () {
            final title = titleController.text;
            if (title.isNotEmpty) {
              final newButton = ServiceButtonData(
                title: title,
                icon: Icons.add,
                backgroundColor: Colors.white,
                textColor: Colors.blue,
                borderColor: Colors.grey,
                isNavigable: false,
              );

              context.read<ServiceButtonBloc>().add(AddServiceButton(button: newButton));
              titleController.clear();
            }
          },
          child: Text('Добавить кнопку'),
        ),
        const SizedBox(height: 22),
        BlocBuilder<ServiceButtonBloc, ServiceButtonState>(
          builder: (context, state) {
            return Column(
              children: [
                for (var button in state.buttons)
                  Column(
                    children: [
                      GestureDetector(
                        onTap: button.isNavigable
                            ? () {
                          Navigator.push(
                            context,
                            MaterialPageRoute(
                              builder: (context) => SecondPage(doctors: button.doctors!),
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
                      SizedBox(height: 20),
                    ],
                  ),
              ],
            );
          },
        )

      ],
    );
  }
}
