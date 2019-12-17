#include "../include/sensor.hpp"


Sensor::Sensor(string id, double latitude, double longitude, string description) :
    id(id), latitude(latitude), longitude(longitude), description(description){}

Sensor::Sensor(vector<string> line_split){
  Sensor(line_split[0], stod(line_split[1]), stod(line_split[2]), line_split[3]);
}

Sensor::~Sensor(){}

void Sensor::addSample(string time, string id_chem, double value){
  if(this->container.find(time) == this->container.end()){
    AirSample* samp = new AirSample();
    this->container.emplace(time, *samp);
  }
  this->container.at(time).container.emplace(id_chem,value);
}

int Sensor::getFrequency(const string& time_begin, const string& time_end) {
  int count = 0;
  for(auto const& sample : container){
    if(sample.first >= time_begin && sample.first <= time_end) {
      ++count;
    }else if(count > 0) {
      break;
    }
  }
  return count;
}