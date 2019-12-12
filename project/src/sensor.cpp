#include "../include/sensor.hpp"

sensor::sensor(){}

sensor::~sensor(){}


sensor::sensor(string id, double latitude, double longitude, string description) :
    id(id), latitude(latitude), longitude(longitude), description(description){}

sensor::sensor(vector<string> line_split){
  sensor(line_split[0],stod(line_split[1]),stod(line_split[2]),line_split[3]);
}


void sensor::addSample(string time, string id_chem, double value){
  if(this->container.find(time) == this->container.end()){
    airSample* samp = new airSample();
    this->container.emplace(time, *samp);
  }
  this->container.at(time).container.emplace(id_chem,value);
}
