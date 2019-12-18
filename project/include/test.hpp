#include "standard.hpp"
#include "airSystem.hpp"

class Test{
public:
  AirSystem test;

  int caseNum = 10;

  Test();

  ~Test();

  vector<pair<string, string>> generateTestCase();

  bool testAirQualityById();

  bool testAirQualityByLoc();

  bool testInactiveSensors();

  bool testSimilarSensors();

};
