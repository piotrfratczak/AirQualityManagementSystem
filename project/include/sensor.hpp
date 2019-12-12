#include "airSample.hpp"

//! \file     sensor.hpp
//! \authors
//! \date     8 December 2019

class sensor{
public:
  string id;
  double latitude;
  double longitude;
  string description;
  /*
   * map time to airSample
   */
  unordered_map<string, airSample> container;

  sensor(string, double, double, string);

  sensor();

  ~sensor();

};
