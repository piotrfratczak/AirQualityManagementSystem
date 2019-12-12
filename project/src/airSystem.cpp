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
      string id;
      int latitude;
      int longitude;
      string description;
      for(int i = 0; i < 4; ++i){
        std::size_t right = line.find_first_of(';');
        temp = line.substr(0, right);
        line = line.substr(right+1);
        switch(i){
          case 0:
            id = temp;
            break;
          case 1:
            latitude = std::stod(temp);
            break;
          case 2:
            longitude = std::stod(temp);
            break;
          case 3:
            description = temp;
            break;
          default:
            break;
        }
      }
      sensor* temp_s = new sensor(id,latitude,longitude,description);
      this->container.emplace(id, *temp_s);
    }
  }
