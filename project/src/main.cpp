#include "../include/airSystem.hpp"
#include <fstream>

int main(){

  airSystem test;

  //relative path is based on the path od makefile.
  ifstream file("./data/data_10sensors_1year.csv");

  string line;

  if(!file.is_open()){
    cout << "There is no such file!" << endl;
    exit(-1);
  }

  while(getline(file,line)){

  }

  return 0;

}
