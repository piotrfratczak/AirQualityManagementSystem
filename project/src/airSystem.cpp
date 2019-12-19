#include "../include/airSystem.hpp"


AirSystem::AirSystem(){}

AirSystem::~AirSystem(){}

int AirSystem::size(){
  return this->container.size();
}

int AirSystem::getChoice(int minChoice, int maxChoice){
  int choice;
  while(1 != scanf("%d", &choice) || choice < minChoice || choice > maxChoice){
    char c;
    while ((c = char(getchar())) != '\n' && c != EOF);
    cout << "There is no such option." << endl
         << "Enter an integer between " << minChoice << " and " << maxChoice << "." << endl;
  }
  return choice;
}

pair<string, string> AirSystem::getInputTime(){
  string date_begin, date_end;
  cout << endl << "Input begin date (format: yyyy-mm-dd): " ;
  cin >> date_begin;
  cout << endl << "Input end date (format: yyyy-mm-dd): ";
  cin >> date_end;
  return make_pair(date_begin, date_end);
}

int AirSystem::getInputId(){
  cout << "Input sensor's ID (0 - " << container.size()-1 << "): ";
  int sensorID = getChoice(0, container.size()-1);
  return sensorID;
}

int AirSystem::chooseLoc(){
  cout << "Please choose one location :" << endl;
  cout << "Sensor ID \t\t latitude \t\t longitude " << endl;
  for(auto it = this->container.begin(); it != this->container.end(); ++it)
    cout << it->first << " \t " << it->second->latitude << "\t" << it->second->longitude << endl;
  return this->getInputId();
}

void AirSystem::getAirQualityById(int sensorID, pair<string, string> date) {
  //TODO: to be optimized
  string time_begin = date.first + "T00:00:00.0000000";
  string time_end = date.second + "T00:00:00.0000000";
  auto time2air = this->container.at("Sensor" + to_string(sensorID))->container;
  int sum = 0, count = 0;
  for(auto it = time2air.begin(); it != time2air.end(); ++it){
    if(it->first >= time_begin && it->first <= time_end){
      sum += it->second.getAirQuality();
      count++;
//      cout << "time = " << it->first << "\t count = " << count << "\t sum = " << sum << endl;
    }
  }
  cout << "Air quality level is: " << level[(int)(sum/count)] << endl;
}

void AirSystem::getAirQualityByLocation(int ID) {
  string sensorID = "Sensor" + to_string(ID);
  int sum = 0, count = 0;
  if(this->container.find(sensorID) != this->container.end()){
    auto time2air = this->container.at(sensorID)->container;
    for(auto it = time2air.begin(); it != time2air.end(); ++it){
      sum += it->second.getAirQuality();
      count++;
    }
  }
  else
    cout << "Can not find this id!" << endl;
  cout << "Air quality level is: " << level[(int)(sum/count)] << endl;
}

void AirSystem::getInactiveSensors(pair<string, string> date) {
  //TODO: to be optimized

  string time_begin = date.first + "T00:00:00.0000000";
  string time_end = date.second + "T00:00:00.0000000";
  int maxi = 0;
  for(auto const& x : container){
    int freq = x.second->getFrequency(time_begin, time_end);
    maxi = max(freq, maxi);
  }
  cout << "The following sensors were inactive: " << endl;
  for(auto const& x : container){
    int freq = x.second->getFrequency(time_begin, time_end);
    if(maxi > freq) cout << x.first << endl;
  }
}

void AirSystem::getSimilarSensors(pair<string, string> date) {
  //TODO: to be optimized
  string time_begin = date.first + "T00:00:00.0000000";
  string time_end = date.second + "T00:00:00.0000000";

  int size = container.size();
  int* readings = new int[size];
  bool* used = new bool[size];
  int i = 0;
  //sensor map
  for(auto const& x : container){
    int sum = 0, count = 0;
    //airSample map
    for(auto const& as :  x.second->container){
      if(as.first >= time_begin && as.first <= time_end){
        sum += as.second.getAirQuality();
        count++;
      }
    }
    readings[i] = int(sum/count);
    used[i] = false;
    ++i;
  }

  //TODO: make it robust
  for(i = 0; i < size-1; ++i){
    if(used[i]) continue;
    cout << endl << "Reading of sensor" << i << " were similar to :" << endl;
    for(int j = i+1; j < size; ++j){
      if(readings[i] == readings[j]){
        cout << "  sensor" << j << endl;
        used[j] = true;
      }
    }
  }

  delete[] readings;
  delete[] used;
}

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
  vector<vector<string>> ans = this->parseFile(filename);
  for(int i = 0; i < ans.size(); ++i){
    auto line_split = ans[i];
    Sensor* temp_s = new Sensor(line_split[0],stod(line_split[1]),stod(line_split[2]),line_split[3]);
    this->container.emplace(line_split[0], temp_s);
  }
}


void AirSystem::parseAttribute(string filename){
  //relative path is based on the path of makefile.
  vector<vector<string>> ans = this->parseFile(filename);
  for(int i = 0; i < ans.size(); ++i){
    auto line_split = ans[i];
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
    case 1:{
      int sensorID =  this->getInputId();
      auto date = this->getInputTime();
      this->getAirQualityById(sensorID, date);
      break;
    }
    case 2:{
      int id = this->chooseLoc();
      this->getAirQualityByLocation(id);
      break;
    }
    case 3:{
      auto date = this->getInputTime();
      getInactiveSensors(date);
      break;
    }
    case 4:{
      auto date = this->getInputTime();
      getSimilarSensors(date);
      break;
    }
    default:
      exit(-1);
  }
}
