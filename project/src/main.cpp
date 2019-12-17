#include "../include/airSystem.hpp"

int main(){

  AirSystem test;

  test.parseSensor("./data/Sensors.csv");

  test.parseAttribute("./data/AttributeType.csv");

  test.parseData("./data/data_10sensors_1year.csv");

//  test.menu();

  return 0;
}
