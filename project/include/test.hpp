//! \file     test.hpp
//! \authors  XIE Yuxuan
//! \date     18 December 2019

#include "standard.hpp"
#include "airSystem.hpp"


class Test{
public:
  AirSystem test;

  int caseNum = 10;

  Test();

  ~Test();

  void readFiles();

  vector<pair<string, string>> generateTestdate();

  vector<int> generateTestID();

  bool testAirQualityById();

  bool testAirQualityByLoc();

  bool testInactiveSensors();

  bool testSimilarSensors();

};
