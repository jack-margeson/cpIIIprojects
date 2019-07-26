/* deck.cpp
Generates and shuffles a deck of cards.
Jack Margeson, 03/21/2018 */
// cout << "\033[2J\033[1;1H";

// compiler directives 
#include <iostream>
#include <iomanip>
#include "randgen.h"
using namespace std;

// structure declaration
struct card{
  int s; // suit of the card, 1-4 (alt + 3 heart, 4 diamond, 5 club, 6 spade)
  int v; // value of the card, 1-13
};

struct deck{
  card card[52]; // array of cards (containing s and v)
};

// function prototypes
void fillDeck(deck &deck); // fills a deck with 52 cards (in order)
void shuffleDeck(deck &deck); // shuffles a deck 
void printDeck(deck &deck); // prints the content of a deck

// main program
int main(){
  // variable declarations and init 
  char ans;
  deck deck;

  do { // run again loop
    fillDeck(deck);
    shuffleDeck(deck);
    printDeck(deck);
    cout << "Run again? (y/n): "; cin >> ans;
  } while (ans == 'y' || ans == 'Y'); 
}

void fillDeck(deck &deck){ // fills a deck with 52 cards (in order)
  int k = 1; // card counter
  for (int i = 1; i <= 4; i++){ // suit loop
    for (int j = 1; j <= 13; j++){ // value loop
      deck.card[k].s = i;
      deck.card[k].v = j;
      ++k;
    }
  }
}

void shuffleDeck(deck &deck){ // shuffles a deck 
  card temp;
  RandGen r;
  int random, random2;
  for (int i = 1; i <= 300; i++){ // i = iterations of shuffle
    random = r.RandInt(1,52);
    random2 = r.RandInt(1,52);
    temp = deck.card[random];
    deck.card[random] = deck.card[random2];
    deck.card[random2] = temp;
  }
}

void printDeck(deck &deck){ // prints the content of a deck
  for (int i = 1; i <= 52; i++){
    switch(deck.card[i].s){ // prints suit
      case 1: cout << "♥" << " "; break;
      case 2: cout << "♦" << " "; break;
      case 3: cout << "♣" << " "; break;
      case 4: cout << "♠" << " "; break;
    }
    switch(deck.card[i].v) { // prints face values
      case 1: cout << "A" << endl; break;
      case 11: cout << "J" << endl; break;
      case 12: cout << "Q" << endl; break;
      case 13: cout << "K" << endl; break;
      default: cout << deck.card[i].v << endl; break;
    }
  }
}