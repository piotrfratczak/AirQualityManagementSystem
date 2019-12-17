#include "../include/airSystem.hpp"


AirSystem::AirSystem(){}

AirSystem::~AirSystem(){}


vector<vector<string>> AirSystem::parseFile(string filename){
  //relative path is based on the path of makefile.
  vector<vector<string>> ans;
  ifstream file(filename);
  string line;
  if(!file.is_open()){
    cout << "There is no such file!" << endl;
    exit(-1);
  }
  getline(file,line);
  while(getline(file,line)){
    int k = 0;
    for(int i = 0; i < line.size(); ++i)
      if(line[i] != 0) line[k++] = line[i];
    line = line.substr(0,k);
    string temp = line;
    std::size_t left = temp.find_first_of(34);
    temp=temp.substr(left+1);
    line=temp;
    vector<string> line_split;
    for(int i = 0; i < 4; ++i){
      std::size_t right = line.find_first_of(';');
      temp = line.substr(0, right);
      line = line.substr(right+1);
      line_split.push_back(temp);
    }
    ans.push_back(line_split);
  }
  return ans;
}

void AirSystem::parseSensor(string filename){
  //relative path is based on the path of makefile.
  auto ans = this->parseFile(filename);
  for(int i = 0; i < ans.size(); ++i){
    auto line_split = ans[0];
    Sensor* temp_s = new Sensor(line_split[0],stod(line_split[1]),stod(line_split[2]),line_split[3]);
    this->container.emplace(line_split[0], temp_s);
  }
}


void AirSystem::parseAttribute(string filename){
  //relative path is based on the path of makefile.
  auto ans = this->parseFile(filename);
  for(int i = 0; i < ans.size(); ++i){
    auto line_split = ans[0];
    Attribute* chem = new Attribute(line_split[0], line_split[1], line_split[2]);
    this->attributes.emplace(line_split[0], *chem);
  }
}

void AirSystem::parseData(string filename){
  cout << endl << "Fetching data..." << endl << endl;
  auto ans = this->parseFile(filename);
  for(int i = 0; i < ans.size(); ++i){
    auto line_split = ans[i];
    if(line_split[1].size() > 0)
      this->container.at(line_split[1])->addSample(line_split[0],line_split[2], stod(line_split[3]));
  }
}

void AirSystem::menu() {
  cout << "0. Quit"                               << endl
       << "1. Get air quality by sensor ID"       << endl
       << "2. Get air quality by location"        << endl
       << "3. Get inactive sensors"               << endl
       << "4. Get sensors with similar readings"  << endl;

  switch(getChoice(0, 4)){
    case 0:
      break;
    case 1:
      getAirQualityById();
      break;
    case 2:
      getAirQualityByLocation();
      break;
    case 3:
      getInactiveSensors();
      break;
    case 4:
      getSimilarSensors();
      break;
    default:
      exit(-1);
  }

}



int AirSystem::getChoice(int minChoice, int maxChoice){
  int choice;
//  while(1 != scanf_s("%d", &choice) || choice < minChoice || choice > maxChoice){
//    char c;
//    while ((c = char(getchar())) != '\n' && c != EOF);
//    cout << "There is no such option." << endl
//         << "Enter an integer between " << minChoice << " and " << maxChoice << "." << endl;
//  }
  return choice;
}

void AirSystem::getAirQualityById() {
  cout << "Input sensor's ID (0 - "
       << container.size()-1 << "): ";
  int sensorID = getChoice(0, container.size()-1);
  cout << endl << "Input date (format: yyy-mm-dd): ";
  //TODO: to be optimized
  string date;
  cin >> date;
  //string quality = container.at("Sensor" + sensorID)->getAirQuality(date);
  //cout << "Air quality on " << date << ": " << quality;

  string time_begin = date + "T00:00:00.0000000";
  cin >> date;
  string time_end = date + "T00:00:00.0000000";


  auto sen = this->container.at("Sensor" + to_string(sensorID))->container;
  int sum = 0, count = 0;
  for(auto it = sen.begin(); it != sen.end(); ++it){
    if(it->first >= time_begin && it->first <= time_end){
      sum += it->second.getAirQuality();
      count++;
    }
  }
  cout << "Air quality level is = " << sum/count << endl;
}

void AirSystem::getAirQualityByLocation() {}

void AirSystem::getInactiveSensors() {}

void AirSystem::getSimilarSensors() {}



