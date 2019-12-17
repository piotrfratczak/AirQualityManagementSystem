#include "standard.hpp"

//! \file     attribute.hpp
//! \authors
//! \date     8 December 2019


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
