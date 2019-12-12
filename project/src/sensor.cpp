#include "../include/sensor.hpp"

sensor::sensor(){}

sensor::~sensor(){}


sensor::sensor(string id, double latitude, double longitude, string description) :
    id(id), latitude(latitude), longitude(longitude), description(description){}

sensor::sensor(vector<string> line_split){
  sensor(line_split[0],stod(line_split[1]),stod(line_split[2]),line_split[3]);
}
