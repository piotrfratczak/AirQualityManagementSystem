#include "../include/attribute.hpp"


Attribute::Attribute(){}

Attribute::~Attribute(){}

Attribute::Attribute(string id, string unit, string description) :
    id(id), unit(unit), description(description){}


Attribute::Attribute(vector<string> line_split){
  Attribute(line_split[0], line_split[1], line_split[2]);
}


