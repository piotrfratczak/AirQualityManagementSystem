#include "sensor.hpp"
#include <fstream>
//! \file     system.hpp
//! \authors
//! \date     8 December 2019



class AirSystem{
public:
    /*
     * Map id to sensor
     */
    unordered_map<string, Sensor*> container;

    unordered_map<string, Attribute> attr;

public:

  AirSystem();

  ~AirSystem();

  void parseSensor(string);

  void parseAttribute(string);

  void parseData(string);

  void menu();
};
