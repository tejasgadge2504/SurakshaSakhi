class LocationData {
  final double accelX;
  final double accelY;
  final double accelZ;
  final double latitude;
  final double longitude;

  LocationData({
    required this.accelX,
    required this.accelY,
    required this.accelZ,
    required this.latitude,
    required this.longitude,
  });

  factory LocationData.fromJson(Map<String, dynamic> json) {
    return LocationData(
      accelX: json['accelX'],
      accelY: json['accelY'],
      accelZ: json['accelZ'],
      latitude: json['latitude'],
      longitude: json['longitude'],
    );
  }
}
