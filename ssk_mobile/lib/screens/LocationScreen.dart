import 'package:flutter/material.dart';
import '../services/api_service.dart';

class LocationScreen extends StatefulWidget {
  @override
  _LocationScreenState createState() => _LocationScreenState();
}

class _LocationScreenState extends State<LocationScreen> {
  late Future<Map<String, dynamic>> _locationData;

  @override
  void initState() {
    super.initState();
    _locationData = ApiService().fetchLocationData();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Location Data'),
      ),
      body: Center(
        child: FutureBuilder<Map<String, dynamic>>(
          future: _locationData,
          builder: (context, snapshot) {
            if (snapshot.connectionState == ConnectionState.waiting) {
              return CircularProgressIndicator();
            } else if (snapshot.hasError) {
              return Text('Error: ${snapshot.error}');
            } else if (snapshot.hasData) {
              final data = snapshot.data!;
              return Column(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Text('Acceleration X: ${data['accelX']}'),
                  Text('Acceleration Y: ${data['accelY']}'),
                  Text('Acceleration Z: ${data['accelZ']}'),
                  Text('Latitude: ${data['latitude']}'),
                  Text('Longitude: ${data['longitude']}'),
                ],
              );
            } else {
              return Text('No data');
            }
          },
        ),
      ),
    );
  }
}
