#include "../include/airSample.hpp"

AirSample::AirSample(){}

AirSample::~AirSample(){}

int AirSample::getAirQuality() {
  int quality = 11;
  for(auto& id2vec: table){
    for(int i = 0; i < id2vec.second.size() ; --i){
      if(this->container.at(id2vec.first) > id2vec.second[i]){
        quality = min(i, quality); break;
      }
    }
  }
  return quality;
}
