#include "airSample.hpp"
//! \file     sensor.hpp
//! \authors
//! \date     8 December 2019

class Sensor{
public:
  string id;
  double latitude;
  double longitude;
  string description;

  // map date to AirSample
  unordered_map<string, AirSample> container;

  Sensor(string, double, double, string);

  Sensor(vector<string>);

  ~Sensor();

  void addSample(string, string, double);

  int getFrequency(const string&, const string&);
};
