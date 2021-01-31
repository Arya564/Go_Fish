// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>



#include "deck.h"
using namespace std;


class Player
{
  public:
    Player();

    Player(string name) {
       myName = name;
    }

    string getName() const {
       return myName;
    }

    void addCard(Card c);  //adds a card to the hand
    void addToFront(Card c);    //adds a card to the front of the hand
    void bookCards(Card c1, Card c2);   //books cards and puts then in the player "Book"

    bool checkForBook(Card c);    //checks for book when drawing card (when "GO FISH" happens)



    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const;

    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const;

    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c);

    string showHand() const;    //CHANGING THIS FUNCTION TO VOID
    string showBooks() const;   //CHANGING THIS FUNCTION TO VOID

    // checks if there are any books in either players hand before the game starts
    void checkBefore();

    int getHandSize() const;
    int getBookSize() const;


  private:
    //TWO VECTORS OF TYPE CARD OBJECTS
    vector <Card> myHand;
    vector <Card> myBook;
    string myName;

};


#endif
