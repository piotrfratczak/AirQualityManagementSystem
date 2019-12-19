//! \file     attribute.hpp
//! \authors
//! \date     8 December 2019

#include "standard.hpp"


class Attribute{
public:
  string id;
  string unit;
  string description;

  Attribute(string, string, string);

  Attribute(vector<string>);

  Attribute();

  ~Attribute();
};
