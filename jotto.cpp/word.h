#ifndef _WORD_H
#define _WORD_H

#include <string.h>
#include <randgen.h>
#include <fstream>

class word {
  public:
    // constructors 
    word();
    word(std::string word);

    // member functions
    // sets
    void setWord(std::string word);
    // gets
    std::string getWord();
    // finds
    int checkJots(std::string guess);
  private:
    // data
    std::string my_word;
};

// default constructor 
word::word() {
  // open file
  std::string line;
  std::string words[3037];
  int i = 0;
  std::ifstream myfile ("jotto.txt");
  if (myfile.is_open()){
    while (getline (myfile,line)){
      words[i] = line;
      i++;
    }
  myfile.close();
  }
  RandGen r; // randgen
  my_word = words[r.RandInt(0,3036)];
}
// fill constructor
word::word(std::string word){
  my_word = word;
}
// setWord
void word::setWord(std::string word){
  my_word = word;
}
// getWord
std::string word::getWord(){
  return my_word;
}
// checkJots
int word::checkJots(std::string guess){
  std::string word = word::getWord();
  int tempjots = 0;
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      // cout << mword[i] << endl;
      // cout << guess[j] << endl;
      if (guess[j] == word[i]){
        tempjots++;
        word.erase(i,1);
      }
      // cout << tempjots << endl;
    }
  }
  return tempjots;
}
#endif