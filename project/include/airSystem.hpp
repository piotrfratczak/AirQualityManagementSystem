#include "sensor.hpp"
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

  vector<vector<string>> parseFile(string);

  pair<string, string> getInputTime();

  int getInputId();

  int chooseLoc();


public:

  AirSystem();

  ~AirSystem();

  void parseSensor(string);

  void parseAttribute(string);

  void parseData(string);

  int size();

  void menu();

  void getAirQualityById(int, pair<string, string>);

  void getAirQualityByLocation(int sensorID);

  void getInactiveSensors(pair<string, string>);

  void getSimilarSensors(pair<string, string>);

};
