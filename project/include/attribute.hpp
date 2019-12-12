#include <iostream>
#include <string>
#include <vector>

using namespace std;

//! \file     attribute.hpp
//! \authors
//! \date     8 December 2019


class attribute{
public:
  string id;
  string unit;
  string description;

  attribute(string, string, string);

  attribute(vector<string>);

  attribute();

  ~attribute();
};
