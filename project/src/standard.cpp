#include "../include/standard.hpp"


unordered_map<string,vector<int>> table = {
  {"NO2", vector<int>({200,150,125,100,75,60,45,30,20,10,0})},
  {"O3", vector<int>({240,200,180,140,100,80,60,40,30,15,0})},
  {"PM10", vector<int>({200,150,125,100,75,60,45,30,20,10,0})},
  {"SO2", vector<int>({240,200,180,140,100,80,60,40,30,15,0})}
    };

vector<string> level = {"extremely bad", "very bad", "bad", "poor", "rather poor", "insufficient", "moderate", "acceptable", "quiet good", "good", "excellent"};

vector<int> months = {0, 31, 29, 31, 30, 30, 31, 31, 31, 30, 31, 30, 31};