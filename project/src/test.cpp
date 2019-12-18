#include "../include/test.hpp"


Test::Test(){}

Test::~Test(){}

vector<pair<string, string>> Test::generateTestCase(){
  string begin_date, end_date;
  for(int i = 0; i < this->caseNum; ++i){
    std::ostringstream oss;
    int begin = rand()%12+1;
    int end = rand()%12+1;
    begin_date = "2017-";
  }
}

bool Test::testAirQualityById(){

}

bool Test::testAirQualityByLoc(){}

bool Test::testInactiveSensors(){}

bool Test::testSimilarSensors(){}
