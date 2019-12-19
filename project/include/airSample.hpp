#include "attribute.hpp"

//! \file     airSample.hpp
//! \authors
//! \date     8 December 2019




class AirSample{

private:

public:
  // map attribute id to value
  unordered_map<string, double> container;

  AirSample();

  ~AirSample();

  const int getAirQuality() const;
};
