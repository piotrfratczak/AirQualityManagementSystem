#include "../include/sensor.hpp"

sensor::sensor(){}

sensor::~sensor(){}


sensor::sensor(string id, double latitude, double longitude, string description) :
    id(id), latitude(latitude), longitude(longitude), description(description){}
