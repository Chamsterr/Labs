import 'package:lab_04_05_06_part1_v2/widgets/service_button_data.dart';

abstract class ServiceButtonEvent {}

class LoadServiceButtons extends ServiceButtonEvent {
  final List<ServiceButtonData> buttons;

  LoadServiceButtons({required this.buttons});
}

class AddServiceButton extends ServiceButtonEvent {
  final ServiceButtonData button;

  AddServiceButton({required this.button});
}
