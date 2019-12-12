#include "sensor.hpp"
#include <fstream>
//! \file     system.hpp
//! \authors
//! \date     8 December 2019


class airSystem{
public:
  /*
   * Map id to sensor
   */
  unordered_map<string, sensor> container;

  vector<attribute> attr;

  airSystem();

  ~airSystem();

  void parseSensor(string);

  void parseAttribute(string);


  void parseData(string);
};
