#include "../include/airSystem.hpp"


  airSystem::airSystem(){}

  airSystem::~airSystem(){}

  void airSystem::parseSensor(string filename){
    //relative path is based on the path of makefile.
    ifstream file(filename);
    string line;
    if(!file.is_open()){
      cout << "There is no such file!" << endl;
      exit(-1);
    }
    getline(file,line);
    while(getline(file,line)){
      string temp = line;
      std::size_t left = temp.find_first_of('"');
      temp=temp.substr(left+1);
      line=temp;
      vector<string> line_split;
      for(int i = 0; i < 4; ++i){
        std::size_t right = line.find_first_of(';');
        temp = line.substr(0, right);
        line = line.substr(right+1);
        line_split.push_back(temp);
      }
      sensor* temp_s = new sensor(line_split[0],stod(line_split[1]),stod(line_split[2]),line_split[3]);
      this->container.emplace(line_split[0], *temp_s);
    }
  }
