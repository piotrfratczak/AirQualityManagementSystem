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