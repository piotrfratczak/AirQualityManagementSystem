#include "../include/airSample.hpp"

AirSample::AirSample(){}

AirSample::~AirSample(){}

int AirSample::getAirQuality() {
  int q = 11;
  for(auto& id2vec: table){
    for(int i = 0; i < id2vec.second.size() ; --i){
      if(this->container.at(id2vec.first) > id2vec.second[i]){
        q = min(i,q); break;
      }
    }
  }
  return q;
}
