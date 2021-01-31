//
// Created by mongo on 11/4/2020.
//

#include "player.h"

//DEFAULT CONSTRUCTOR
Player::Player() {
    myName = "Player";
}


/* ADDS CARD TO THE HAND
input parms - input is a Card
output parms - no return, just adds a card to the hand
*/
void Player::addCard(Card c) {
    myHand.push_back(c);
}

/* ADDS CARD TO THE FRONT OF THE HAND
input parms - input is a Card
output parms - no return, just adds a card to the FRONT OF THE hand
*/
void Player::addToFront(Card c) {
    myHand.insert(myHand.begin(), c);   //inserts c at the beginning of the card deck
}


/* SHOWS THE CURRENT STATE OF THE PLAYERS HAND
input parms - no input
output parms - no return, just shows the players hand
*/
string Player::showHand() const {

    //MAYBE USE RANGE-BASED FOR LOOP, change later if you want
//    for(auto i = 0; i < myHand.size(); i++){
//        cout << myHand.at(i) << " ";
//    }

    string result = "";
    string space = " ";

    for(Card playerCard : myHand){
        result = result + playerCard.toString() + space;
    }

    return result;
}

/* SHOWS THE CURRENT STATE OF THE PLAYERS BOOK
input parms - no input
output parms - no return, just shows the PLAYERS BOOKS
*/
string Player::showBooks() const {

//    for(auto i = 0; i < myBook.size(); i++){
//        cout << myBook.at(i) << " ";
//    }

    string result = "";
    string space = " ";

    for(Card playerBook : myBook){
        result = result + playerBook.toString() + space;
    }

    return result;
    //cout << endl;
}

// GET SIZE OF the book
int Player::getBookSize() const {
    return myBook.size();
}

//GETS THE SIZE OF HAND
int Player::getHandSize() const {
    return myHand.size();
}

/* books two cards
input parms - 2 cards
output parms - no return, just books two cards
*/
void Player::bookCards(Card c1, Card c2) {

    myBook.push_back(c1);
    myBook.push_back(c2);
}


/* checks the original hand to see if there are any books
input parms - no input
output parms - no return, just checks the original hand to see if there are any books
*/
void Player::checkBefore(){

    for(auto i = myHand.begin(); i != myHand.end(); i++){
        for(auto j = i + 1; j < myHand.end(); j++){
            if(*i == *j){
                //push the books
                myBook.push_back(*i);
                myBook.push_back(*j);
                myHand.erase(j);
                myHand.erase(i);
                //why is this happening check this tmrw idk
                j--;
                i--;
                break;
            }
        }
    }
}



/* removes a card from the hand
input parms - input is a card
output parms - no return, just removes specific card from the hand
*/Card Player::removeCardFromHand(Card c) {

    Card find;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(*i == c){
            find = *i;  //set the  DESIRED card to the FIND object
            myHand.erase(i);    //erase the position of where the card is
            break;
        }
    }
    return find;
}

/* checks the hand to see if card is there
input parms - input is a card
output parms - returns true if card is in hand, false otherwise
*/
//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const {

    int flag = 0;
    for(auto i = myHand.begin(); i != myHand.end(); i++){
        if(*i == c){
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        return true;
    }

    else{
        return false;
    }
}

/* chooses card from the hand
input parms - no input
output parms - returns a card from the hand (the top one)
*/
//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const {


    int random = 0; // to randomize the cards ya know
    int count = 0;
    Card choose;
    string output;

    for(auto i = myHand.begin(); i != myHand.end(); i++){

        if(count == random){
            choose = *i;
            break;
        }
        count++;
    }
    return choose;
}

/* checks the hand to see if there are any books
input parms - input is a card
output parms - returns true if there is a book in the hand with the card given, false otherwise
*/
//checks for book when drawing card (when "GO FISH" happens)
bool Player::checkForBook(Card c) {

    int flag = 0;
    for(auto i = myHand.begin(); i != myHand.end(); i++){

        //IF CARD HAS A PAIR IN THE HAND
        if(c == *i){
            bookCards(c, *i);   //want to book the cards ASAP
            myHand.erase(i);
            flag = 1;
            break;
        }
    }

    if(flag == 1){
        return true;
    }

    else{
        return false;
    }
}