#include "../include/airSystem.hpp"
#include <fstream>

int main(){

  airSystem test;

  test.parseSensor("./data/Sensors.csv");

//  test.parseAttribute("./data/AttributeType.csv");

  for(auto& pair : test.container){
    cout << pair.first << "\tsize = " << pair.first.size() << endl;
    cout << &pair.second << endl;
  }

  test.parseData("./data/data_10sensors_1year.csv");

  return 0;

}
