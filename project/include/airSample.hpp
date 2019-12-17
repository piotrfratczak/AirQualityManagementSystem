#include "attribute.hpp"
#include <unordered_map>

//! \file     airSample.hpp
//! \authors
//! \date     8 December 2019



class AirSample{

private:

  int getQualityByNO2PM10(double value);

public:

  // map attribute id to value
  unordered_map<string, double> container;

  AirSample();

  ~AirSample();

  string getAirQuality();
};
