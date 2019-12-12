#include "../include/airSystem.hpp"
#include <fstream>

int main(){

  airSystem test;

  test.parseSensor("./data/Sensors.csv");

  test.parseAttribute("./data/AttributeType.csv");


  return 0;

}
