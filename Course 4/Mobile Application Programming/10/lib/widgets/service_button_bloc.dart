import 'package:flutter_bloc/flutter_bloc.dart';
import 'package:lab_04_05_06_part1_v2/widgets/service_button_data.dart';
import 'events.dart';
import 'state.dart';

class ServiceButtonBloc extends Bloc<ServiceButtonEvent, ServiceButtonState> {
  ServiceButtonBloc() : super(ServiceButtonInitial()) {
    on<LoadServiceButtons>((event, emit) {
      emit(ServiceButtonLoaded((state as ServiceButtonInitial).buttons));
    });

    on<AddServiceButton>((event, emit) {
      if (state is ServiceButtonLoaded) {
        final updatedButtons = List<ServiceButtonData>.from((state as ServiceButtonLoaded).buttons)
          ..add(event.button);
        emit(ServiceButtonLoaded(updatedButtons));
      }
    });
  }
}
