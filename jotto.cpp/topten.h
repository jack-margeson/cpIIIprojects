#ifndef _TOPTEN_H
#define _TOPTEN_H

#include <string.h>
#include <iostream>
#include <fstream>

class topten {
  public:
    // constructors 
    topten();
    topten(std::string filename);

    // member functions
    void openFile(std::string filename);
    void saveFile(std::string filename);
    void newScore(std::string name, int score, std::string filename);
    std::string toString();
  private:
    // data
    std::string names[10];
    int scores[10];
};
// default constructor
topten::topten(){
  for (int i = 0; i <= 9; i++){
    names[i] = "JACK";
    scores[i] = 25;
  }
}
// fill constructor 
topten::topten(std::string filename){
  topten::openFile(filename);
}
// openFile
void topten::openFile(std::string filename){
  std::string line;
  int lc = 1, i = 0, j = 0;
  std::ifstream myfile(filename);
  if (myfile.is_open()){
    while (getline (myfile,line)){
      if (lc % 2 == 0){
        scores[j] = stoi(line);
        j++;
      } else {
        names[i] = line;
        i++;
      }
      lc++;
    }
  myfile.close();
  }
}
// saveFile
void topten::saveFile(std::string filename){
  std::string line;

  std::ofstream myfile(filename);
  if (myfile.is_open()){
    for (int i = 0; i <= 9; i++) {
      myfile << names[i] << std::endl;
      myfile << scores[i] << std::endl;
    }
  }
  myfile.close();
}
// newScore
void topten::newScore(std::string name, int score, std::string filename){
  // checks high score validity
  int replace = -1;
  for (int i = 0; i <=9; i++){
    if (score >= scores[i]){
      replace = i;
    }
  }
  // change high score table
  if (replace != -1){
    for (int i = 9; i > replace; i--){
      names[i] = names[i-1];
      scores[i] = scores[i-1];
    }
    names[replace] = name;
    scores[replace] = score;
  }
  // saves high score table
  topten::saveFile(filename);
}
// toString
std::string topten::toString(){
  std::string tstring;
  tstring = "------------\nHIGH SCORES\n";
  for (int i = 0; i <= 9; i++){
    tstring = tstring + names[i] + "     " + std::to_string(scores[i]) + "\n";
  }
  tstring = tstring + "------------\n\n";
  return(tstring);
}
#endif