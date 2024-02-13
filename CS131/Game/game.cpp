#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

class Card {
  public:
    Card(int x, char y) {
        value = x;
        suit = y;
    }

    int getValue() {
      return value;
    }

    char getSuit() {
      return suit;
    }

  private:
    int value;
    char suit;
};

void displayCards(vector<Card> hand) {
  for (Card i : hand) {
    int value = i.getValue();
    string valueStr = "";

    if (value == 1 || value > 10) {
      switch (value) {
        case 1:
          valueStr = "A";
          break;
        case 11:
          valueStr = "J";
          break;
        case 12:
          valueStr = "Q";
          break;
        case 13:
          valueStr = "K";
          break;
      }
    } else {
        valueStr = to_string(value);
    }
  }

    cout << valueStr << " " << i.getSuit() << " | ";
}


void populateDeck(vector<Card> &hand) {
  for (int i = 1; i < 14; i++) {
    Card newCardH(i, 'H');
    Card newCardS(i, 'S');
    Card newCardD(i, 'D');
    Card newCardC(i, 'C');

    hand.push_back(newCardH);
    hand.push_back(newCardS);
    hand.push_back(newCardD);
    hand.push_back(newCardC);
  }
}

void shuffleDeck(vector<Card> &hand) {
  auto seed = random_device{}; 
  auto rand = default_random_engine{seed()};
  shuffle(begin(hand), end(hand), rand);
}

void dealCards(vector<Card> &hand, vector<Card> &deck, int amt) {
  for (int i =0; i < amt; i++) {
    hand.push_back(deck.back());
    deck.pop_back();
  }
}

int main() {
  bool quit = false;

  while (!quit) {
    vector <Card> deck;
    vector <Card> playerHand;
    vector <Card> dealerHand;

    populateDeck(deck);
    shuffleDeck(deck);

    dealCards(playerHand, deck, 2);
    dealCards(dealerHand, deck, 1);

    displayCards(playerHand);
    quit = true;
  }
}