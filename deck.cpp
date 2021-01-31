//
// Created by mongo on 11/4/2020.
//
#include "deck.h"

//MAIN CONSTRUCTOR
// pristine, sorted deck
Deck::Deck() {

    myIndex = 0;    //INITIALIZE THE INDEX TO ZERO SO WE CAN INCREMENT IT IN DEAL CARD

    //need a counter to get all of the values up until 13
    //i think we have to make a card object every time we want to add something to it
    int count = 0;
    for(int i = 1; i <= 13; i++) {

        Card::Suit suit;
        //cast to int to ITERATE PROPERLY
        for (auto j = (int) Card::Suit::spades; j <= Card::Suit::clubs; j++) {

            //set each number to four different suits
            if(j == 0){
                suit = Card::spades;
            }

            if(j == 1){
                suit = Card::hearts;
            }

            if(j == 2){
                suit = Card::diamonds;
            }

            if(j == 3){
                suit = Card::clubs;
            }

            Card temp(i,suit);  //make a new object every time
            myCards[count] = temp;
            count++;    //increment count
        }
    }
}

/* SHUFFLES THE DECK
input parms - no input parameter
output parms - shuffles the deck in a random order
*/
void Deck::shuffle() {
    myIndex = 0;
    srand((unsigned int) time(nullptr));
    int random; // to randomize the cards ya know
    int count = 0;
    Card temporary;

    while(count < 52){
        random = rand() % 52;
        temporary = myCards[random];

        myCards[random] = myCards[count];
        myCards[count] = temporary;
        count++;    //increment the counter
    }

//    //ASK ABOUT THIS I MEAN IT PRINTS SO I THINK WE GOOD
//    for(int i = 0; i < 52; i++){
//        cout << myCards[i] << " ";
//    }
}


/* DEALS CARD TO THE PLAYER
input parms - no input parameter
output parms - returns the next CARD in the deck and increases the index for the next DEAL
*/
Card Deck::dealCard() {

    int temp;
    temp = myIndex;
    myIndex++;
    return myCards[temp];
}

/* SHOWS THE SIZE OF THE DECK
input parms - no input parameter
output parms - returns the size of the DECK
*/
int Deck::size() const {
    return (SIZE - myIndex);
}