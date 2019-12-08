#include "attribute.hpp"
#include "airSample.hpp"

//! \file     sensor.hpp
//! \authors
//! \date     8 December 2019

class sensor{
public:
  double latitude;
  double longitude;
  string description;
  unordered_map<string, airSample> container;

  sensor();

  ~sensor();
};
