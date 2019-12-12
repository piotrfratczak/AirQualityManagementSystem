#include "../include/airSystem.hpp"
#include <fstream>

int main(){

  airSystem test;

  test.parseSensor("./data/Sensors.csv");

  test.parseAttribute("./data/AttributeType.csv");

  test.parseData("./data/data_10sensors_1year.csv");

  return 0;
}
