#include "../include/attribute.hpp"


attribute::attribute(){}

attribute::~attribute(){}

attribute::attribute(string id, string unit, string description) :
    id(id), unit(unit), description(description){}


attribute::attribute(vector<string> line_split){
  attribute(line_split[0], line_split[1], line_split[2]);
}


