#include "../include/test.hpp"


Test::Test(){}

Test::~Test(){}

void Test::readFiles(){
  test.parseSensor("./data/Sensors.csv");
  test.parseAttribute("./data/AttributeType.csv");
  test.parseData("./data/data_10sensors_1year.csv");
}

vector<pair<string, string>> Test::generateTestdate(){
  vector<pair<string, string>> ans;
  vector<int> bound({12,31});
  for(int i = 0; i < this->caseNum; ++i){
    string begin_date = "2017", end_date = "2017";
    for(int j = 0; j < bound.size(); ++j){
      std::ostringstream oss;
      int begin = rand()%bound[j]+1;
      int end = rand()%bound[j]+1;
      while(end < begin){
        end = rand()%bound[j]+1;
      }
      oss << setw(2) << setfill('0') << to_string(begin);
      begin_date += "-" + oss.str();
      oss.str("");
      oss.clear();
      oss << setw(2) << setfill('0') << to_string(end);
      end_date += "-" + oss.str();
    }
    cout << "begin = " << begin_date << "\t end =" << end_date << endl;
    ans.push_back(make_pair(begin_date,end_date));
  }
  return ans;
}

vector<int> Test::generateTestID(){
  vector<int> ans;
  int size = this->test.size();
  for(int i = 0; i < this->caseNum; ++i){
    ans.push_back(rand()%size);
  }
  return ans;
}

bool Test::testAirQualityById(){
  auto test_date = this->generateTestdate();
  auto test_id = this->generateTestID();
  for(int i = 0; i < this->caseNum; ++i){
    this->test.getAirQualityById(test_id[i], test_date[i]);
  }
  return true;
}

bool Test::testAirQualityByLoc(){
  auto test_id = this->generateTestID();
  auto test_date = this->generateTestdate();
  for(int i = 0; i < this->caseNum; ++i){
    this->test.getAirQualityByLocation(test_id[i], test_date[i]);
  }
  return true;
}

bool Test::testInactiveSensors(){
  auto test_date = this->generateTestdate();
  for(int i = 0; i < this->caseNum; ++i){
    this->test.getInactiveSensors(test_date[i]);
  }
  return true;
}

bool Test::testSimilarSensors(){
  auto test_date = this->generateTestdate();
  for(int i = 0; i < this->caseNum; ++i){
    this->test.getSimilarSensors(test_date[i]);
  }
  return true;
}
