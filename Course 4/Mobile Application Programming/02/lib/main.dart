import 'dart:async';
import 'dart:convert';

abstract class Playable {
  void play();
}

abstract class Instrument {
  String name;

  Instrument(this.name);

  void tune();

  void play() {
    print('$name is playing');
  }
}

class Guitar extends Instrument implements Playable {
  static int totalGuitars = 0;

  Guitar(String name) : super(name) {
    totalGuitars++;
  }

  Guitar.electric() : super('Electric Guitar') {
    totalGuitars++;
  }

  String get guitarName => name;
  set guitarName(String newName) {
    name = newName;
  }

  @override
  void tune() {
    print('$name is being tuned override');
  }

  @override
  void play() {
    print('$name is playing override');
  }

  static void showTotalGuitars() {
    print('Total guitars: $totalGuitars');
  }

  void perform({required String song}) {
    print('$name is performing $song');
  }

  void adjustVolume([int level = 5]) {
    print('$name volume set to $level');
  }

  void applyEffect(void Function() effect) {
    effect();
  }

  void changeStrings([int? numberOfStrings]) {
    if (numberOfStrings != null) {
      print('$name now has $numberOfStrings strings');
    } else {
      print('$name strings changed');
    }
  }
}

void main() {
  List<Guitar> guitars = [
    Guitar('Acoustic Guitar'),
    Guitar.electric(),
    Guitar('Bass Guitar')
  ];

  guitars[1].perform(song: "Lapidacija");

  guitars.add(Guitar('Classical Guitar'));
  print(guitars.last.name);

  for (var guitar in guitars) {
    if (guitar.name == 'Bass Guitar') continue;
    guitar.play();
    if (guitar.name == 'Electric Guitar') break;
    print("Good");
  }


  Set<String> guitarTypes = {'Acoustic', 'Electric', 'Bass'};
  if (guitarTypes.contains('Electric')) {
    print('Set contains Electric');
  }
  guitarTypes.add('Classical');
  print(guitarTypes);


  Map<String, Guitar> guitarMap = {
    'Acoustic': Guitar('Acoustic Guitar'),
    'Electric': Guitar.electric(),
    'Bass': Guitar('Bass Guitar')
  };
  print(guitarMap['Electric']?.name);
  guitarMap['Classical'] = Guitar('Classical Guitar');
  guitarMap.forEach((key, guitar) {
    print('$key: ${guitar.name}');
  });


  try {
    guitars[10].play();
  } catch (e) {
    print('Exception caught: $e');
  }

  //-------------------------
  lab3();
}

//------------------------
mixin Musical {
  bool canPlayPiano = false;
  bool canCompose = false;

  void entertainMe() {
    if (canPlayPiano) {
      print('Playing piano');
    } else {
      print('Whistle');
    }
  }
}

class Performer {
  void perform() {
    print('Performing...');
  }
}

class Musician extends Performer with Musical {
  Musician() {
    canPlayPiano = true;
  }
}

class Person implements Comparable<Person> {
  String name = '';
  int age = 0;

  Person(this.name, this.age);

  @override
  int compareTo(Person other) {
    return age.compareTo(other.age);
  }

  Map<String, dynamic> toJson() => {
        'name': name,
        'age': age,
      };

   Person.fromJson(Map<String, dynamic> json) {
      name = json['name'];
      age = json['age'];
    }
}

class NumberIterator implements Iterator<int> {
  int _current = 0;
  final int _max;

  NumberIterator(this._max);

  @override
  bool moveNext() {
    _current++;
    return _current <= _max;
  }

  @override
  int get current => _current;
}

class NumberIterable extends Iterable<int> {
  final int max;

  NumberIterable(this.max);

  @override
  Iterator<int> get iterator => NumberIterator(max);
}

Future<int> fetchData() async {
  await Future.delayed(Duration(seconds: 2));
  return 5;
}

void lab3() async {
  print('----------------lab3-----------------------');
  var musician = Musician();
  musician.entertainMe();

  //----------------------------
  var numbers = NumberIterable(5);
  numbers.join("123");
  for (var number in numbers) {
    print(number);
  }

  //----------------------------

  //----------------------------
  var person = Person('Alice', 30);
  String jsonString = jsonEncode(person);
  print(jsonString);

  var decodedPerson = Person.fromJson(jsonDecode(jsonString));
  print(decodedPerson.name);
  //-----------------------------

  //-----------------------------
  int number = await fetchData();
  print(number);
  //-----------------------------

  StreamController<int> singleController = StreamController<int>();
  singleController.stream.listen((data) {
    print('Single subscription stream: $data');
  });

  //singleController.stream.listen((data) {
  //  print('Single subscription stream2: $data');
  //});

  singleController.add(1);
  singleController.add(2);
  singleController.close();

  Stream<int> broadcastStream(int max) {
    var controller = StreamController<int>.broadcast();

    Future(() async {
      for (int i = 1; i <= max; i++) {
        controller.add(i);
        await Future.delayed(Duration(seconds: 1));
      }
      await controller.close();
    });

    return controller.stream;
  }

  var stream = broadcastStream(5);

  stream.listen((value) {
    print('Listener 1: $value');
  });

  stream.listen((value) {
    print('Listener 2: $value');
  });
}
