#include "../include/test.hpp"


int main(){
  Test test;

  test.readFiles();

  cout << "------------------- Test Quality by ID -----------------" << endl << endl;
  test.testAirQualityById();

  cout << "------------------- Test Quality by Loc -----------------" << endl << endl;
  test.testAirQualityByLoc();

  cout << "----------------- Test Inactive sensors -----------------" << endl << endl;
  test.testInactiveSensors();

  cout << "----------------- Test Similar sensors -----------------" << endl << endl;
  test.testSimilarSensors();
  return 0;
}
