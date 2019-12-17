#include "sensor.hpp"
#include <fstream>
//! \file     system.hpp
//! \authors
//! \date     8 December 2019



class AirSystem{
private:
  // Map id to sensor
  unordered_map<string, Sensor*> container;

  // Map id to attribute
  unordered_map<string, Attribute> attributes;

  int getChoice(int, int);

  void getAirQualityById();

  void getAirQualityByLocation();

  void getInactiveSensors();

  void getSimilarSensors();

public:

  AirSystem();

  ~AirSystem();

  void parseSensor(string);

  void parseAttribute(string);

  void parseData(string);

  void menu();

};
