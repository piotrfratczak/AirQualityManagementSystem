#include "sensor.hpp"
#include <vector>
//! \file     system.hpp
//! \authors
//! \date     8 December 2019


class airSystem{
public:
  unordered_map<int, sensor> container;
  vector<attribute> attr;

  airSystem();

  ~airSystem();
};
