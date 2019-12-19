#include "../include/airSystem.hpp"

int main(){

  AirSystem test;

  test.parseSensor("./data/Sensors.csv");

  test.parseAttribute("./data/AttributeType.csv");

  test.parseData("./data/data_10sensors_1year.csv");

  while(1){
    test.menu();
  }

  return 0;
}
