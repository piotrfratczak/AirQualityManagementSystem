#include "attribute.hpp"
#include <unordered_map>

//! \file     airSample.hpp
//! \authors
//! \date     8 December 2019



class AirSample{
public:
  /*
   * map id to value
   */
  unordered_map<string, double> container;

  AirSample();

  ~AirSample();
};
