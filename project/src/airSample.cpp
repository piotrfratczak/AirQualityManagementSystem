#include "../include/airSample.hpp"

int AirSample::getQualityByNO2PM10(double value){
  if(value > 200.0){
    return 0;
  } else if(value >= 150.0){
    return 1;
  }
}

AirSample::AirSample(){}

AirSample::~AirSample(){}

int AirSample::getAirQuality() {
  return 0;
}
