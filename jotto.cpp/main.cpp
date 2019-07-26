/* jotto.cpp
Generates 5 letter words, plays a game of Jotto.
Jack Margeson, 04/2019, 6th bell */
// cout << "\033[2J\033[1;1H";

// inclusions and namespace
#include <iostream>
#include <algorithm>
#include <word.h>
#include <topten.h>
using namespace std;

// main program
int main(){
  // declaration and init 
  char ans; // used for looping
  bool isGame = true; // game state
  string word; // random word 
  string guess; // user's guess
  int jots; // jots counter
  int guesses; // guess counter
  string name; // player's name

  do { // run again loop
    cout << "\033[2J\033[1;1H";
    // high score 
    class topten t("topten.txt");
    cout << t.toString();
    // generate random word
    class word w; // construct word
    word = w.getWord(); // get word
    cout << word << endl; // show word
    guesses = 0;
    isGame = true;
    do { // game loop
      cout << "Enter your guess (5 letters): "; cin >> guess;
      if (guess == "0") {
        cout << "\nGame ended... the word was " << word << "." << endl;
        cout << "You gave up after " << guesses << " guesses." << endl;
        isGame = false;
      } else if (guess.length() != 5){ // if guess is not valid
        cout << "Your guess is invalid." << endl;
      } else { // if guess is valid
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
        jots = w.checkJots(guess);
        guesses++;
        if (jots == 5 && word == guess){ // game win
          cout << "\nGreat job! You won. The word was " << word << "." << endl;
          cout << "It took you " << guesses << " guess(es). Nice!" << endl;
          cout << "What's your name?: "; cin >> name;
          t.newScore(name, guesses, "topten.txt");
          isGame = false;
        } else { // guess not correct
          cout << "\nNot quite. You got " << jots << " jot(s)." << endl;
        }
      }
    } while (isGame);
    cout << "Run again? (y/n): "; cin >> ans;
  } while(ans == 'Y' || ans == 'y');
  cout << "\033[2J\033[1;1H";
  return 0;
}

