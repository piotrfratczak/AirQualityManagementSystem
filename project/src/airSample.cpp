#include "../include/airSample.hpp"

AirSample::AirSample(){}

AirSample::~AirSample(){}

const int AirSample::getAirQuality() const {
  sss x;
  int quality = 11;
  float mean = 0, count = 0;
  for(auto& id2vec: table){
    for(int i = 0; i < id2vec.second.size() ; ++i){
      if(this->container.at(id2vec.first) > id2vec.second[i]){
//        quality = min(i, quality);
        mean += i;
        count++;
        break;
      }
    }
  }
  return mean/count;
}
