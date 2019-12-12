#include "../include/airSystem.hpp"
#include <fstream>

int main(){

  airSystem test;

  test.parseSensor("./data/Sensors.csv");


  return 0;

}
