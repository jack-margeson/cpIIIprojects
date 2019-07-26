/* crazy8s.cpp
A game of crazy 8s, written for HCPIII.
Jack Margeson, 04/07/2018 */
// cout << "\033[2J\033[1;1H";

// compiler directives 
#include <iostream>
#include <iomanip>
#include "randgen.h"
#include "string.h"
using namespace std;

// structure declaration
struct card{
  int s; // suit of the card, 1-4 (alt + 3 heart, 4 diamond, 5 club, 6 spade)
  int v; // value of the card, 1-13
};

struct deck{
  card card[53]; // array of cards (containing s and v)
};

struct player{
  deck hand; // deck of 52 cards that could be in your hand
  string name; // name of player
};

struct highscore{
  int score;
  player player;
};

// function prototypes
void fillDeck(deck &deck); // fills a deck with 52 cards (in order)
void shuffleDeck(deck &deck, int &shuffle); // shuffles a deck
int crazy8s(player &player1, player &player2, deck deck); // plays the crazy 8 game
int checkValid(card cplayer, card cpile);
// function prototypes - printing
void printDeck(deck deck); // prints the content of a deck
void printPlayerHand(player player, int cc); // prints the hand of a player
void printCard(card card); // prints a single card
void printMenu(int cc); // prints menu of game options

// main program
int main(){
  // variable declarations and init 
  char ans; // question answering and looping
  int shuffle; // used for shuffle amount
  deck deck; // desk used for playing
  player player1, player2; // players for the game
  int win; // who won?

  do { // run again loop
    cout << "\033[2J\033[1;1H";
    cout << "How well would you like the deck shuffled?\n(0 for a unshuffled deck, 300 for very shuffled.): "; cin >> shuffle;
    fillDeck(deck);
    shuffleDeck(deck, shuffle);
    // printDeck(deck);
    win = crazy8s(player1, player2, deck);
    switch (win){
      case 1: cout << "Player 1 wins!" << endl; break;
      case 2: cout << "Player 2 wins!" << endl; break;
    }
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

void shuffleDeck(deck &deck, int &shuffle){ // shuffles a deck 
  card temp;
  RandGen r;
  int random, random2;
  for (int i = 1; i <= shuffle; i++){ // shuffle = iterations of shuffle
    random = r.RandInt(1,52);
    random2 = r.RandInt(1,52);
    temp = deck.card[random];
    deck.card[random] = deck.card[random2];
    deck.card[random2] = temp;
  }
}

int crazy8s(player &player1, player &player2, deck deck) { // crazy 8s game
  // crazy 8 declarations
  bool isGame = true; // game running
  bool isValidPlay = false; // play checker
  bool computerTurn = true; // cpu check
  int cc = 1, p1cc = 0, p2cc = 0, pilecc = 1; // used to count cards
  int computerTurnCount = 0;
  int cchoice; // choice from card menu
  struct deck pile; // played card pile
  int suit; // used for crazy 8

  // game set-up
  for (int i = 1; i <= 7; i++) { // init player 1 hand
    player1.hand.card[i] = deck.card[cc];
    ++cc;
    ++p1cc;
  }
  cout << cc << endl;
  for (int i = 1; i <= 7; i++) { // init player 2 hand 
    player2.hand.card[i] = deck.card[cc];
    ++cc;
    ++p2cc;
  }
  // first pile card
  pile.card[pilecc] = deck.card[cc];
  ++cc;
  cout << "\033[2J\033[1;1H";
  cout << "Dealing hands..." << endl;

  do { // while game is running...
    cout << "Your hand:" << endl; printPlayerHand(player1, p1cc);
    // cout << "Their hand:" << endl; printPlayerHand(player2, p2cc);
    cout << "Discard pile: "; printCard(pile.card[pilecc]); cout << endl;
    cout << "Opponent has: " << p2cc << endl;
    printMenu(p1cc); cin >> cchoice;
    cout << "\033[2J\033[1;1H";
    if (cchoice == 0){ // draw a card
      ++p1cc;
      player1.hand.card[p1cc] = deck.card[cc];
      ++cc;
      cout << "You draw a card. You drew "; printCard(player1.hand.card[p1cc]); cout << "!" << endl;
    } else { // play a card
      cout << "You selected to play: "; printCard(player1.hand.card[cchoice]); cout << endl;
      isValidPlay = checkValid(player1.hand.card[cchoice], pile.card[pilecc]);
      if (isValidPlay == 1) { // play is valid, card can be played
        ++pilecc;
        pile.card[pilecc] = player1.hand.card[cchoice];
        for (int i = cchoice; i <= p1cc; i++){ // remove card from player
          player1.hand.card[i] = player1.hand.card[i+1];
        }
        --p1cc; 
        if (p1cc == 0){isGame = false; return 1;}
      } else if (isValidPlay == 2) { // crazy 8
        ++pilecc;
        pile.card[pilecc] = player1.hand.card[cchoice];
        for (int i = cchoice; i <= p1cc; i++){ // remove card from player
          player1.hand.card[i] = player1.hand.card[i+1];
        }
        --p1cc; 
        if (p1cc == 0){isGame = false; return 1;}
      } else { // card cannot be played
        cout << "This card cannot be played." << endl;
      }
      
      // computer's turn
      computerTurnCount = 0;
      computerTurn = true;
      for (int i = 1; i <= p2cc;i++){
        isValidPlay = checkValid(player2.hand.card[i], pile.card[pilecc]);
        if (computerTurn && (isValidPlay == 1 || isValidPlay == 2)) {
          ++pilecc;
          pile.card[pilecc] = player2.hand.card[i];
          for (int j = i; j <= p1cc; j++){ // remove card from player
            player2.hand.card[j] = player2.hand.card[j+1];
          }
          --p2cc;
          computerTurn = false;
          if (p2cc == 0){isGame = false; return 2;}
        } else {
          ++computerTurnCount;
        }
      }
      if (computerTurnCount == p2cc) {
        ++p2cc;
        player2.hand.card[p2cc] = deck.card[cc];
        ++cc;
      } 
    }
  } while (isGame);
}

int checkValid(card cplayer, card cpile){ // checks validity of a play 
  if (cplayer.v == 8) {
    return 2;
  } else if (cplayer.v == cpile.v || cplayer.s == cpile.s){
    return 1;
  } else {
    return 0;
  }
}

void printDeck(deck deck){ // prints the content of a deck
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

void printPlayerHand(player player, int cc){ // prints players hand given player and cc
  for (int i = 1; i <= cc; i++){
    switch(player.hand.card[i].s){ // prints suit
      case 1: cout << "♥" << " "; break;
      case 2: cout << "♦" << " "; break;
      case 3: cout << "♣" << " "; break;
      case 4: cout << "♠" << " "; break;
    }
    switch(player.hand.card[i].v) { // prints face values
      case 1: cout << "A" << endl; break;
      case 11: cout << "J" << endl; break;
      case 12: cout << "Q" << endl; break;
      case 13: cout << "K" << endl; break;
      default: cout << player.hand.card[i].v << endl; break;
    }
  }
}

void printCard(card card){
  switch(card.s){ // prints suit
    case 1: cout << "♥" << " "; break;
    case 2: cout << "♦" << " "; break;
    case 3: cout << "♣" << " "; break;
    case 4: cout << "♠" << " "; break;
  }
  switch(card.v) { // prints face value
    case 1: cout << "A"; break;
    case 11: cout << "J"; break;
    case 12: cout << "Q"; break;
    case 13: cout << "K"; break;
    default: cout << card.v; break;
  }
}

void printMenu(int cc){
  cout << "\nWhat would you like to do?" << endl;
  cout << "0 - Draw card" << endl; 
  cout << "1-" << cc << " - Play card" << endl;
  cout << "Enter an option: ";
}
