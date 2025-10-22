class Guitar {
  final int? id;
  final String name;
  final int strings;

  Guitar({this.id, required this.name, required this.strings});

  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'name': name,
      'strings': strings,
    };
  }

  factory Guitar.fromMap(Map<String, dynamic> map) {
    return Guitar(
      id: map['id'],
      name: map['name'],
      strings: map['strings'],
    );
  }

  Map<String, dynamic> toJson() => {
    'id': id,
    'name': name,
    'strings': strings,
  };

  factory Guitar.fromJson(Map<String, dynamic> json) {
    return Guitar(
      id: json['id'],
      name: json['name'],
      strings: json['strings'],
    );
  }
}
