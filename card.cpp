//
// Created by mongo on 11/4/2020.
//

#include <string>
using namespace std;
#include "card.h"


// DEFAULT CONSTRUCTOR
Card::Card() {
    myRank = 1;
    mySuit = spades;    //ACE OF SPADES IS THE DEFAULT CONSTRUCTOR
}

// MAIN CARD CONSTRUCTOR
Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
}

/* CONVERTS A CARD TO A STRING, e.g., TO PRINT
input parms - no input parameter
output parms - returns string version of the card e.g. Ac 4h Js
*/

string Card::toString() const {

    string resultRank;
    string resultSuit;
    string result;  //we will concatenate these two strings together

    if(mySuit == spades){
        resultSuit = "s";
    }

    if(mySuit == clubs){
        resultSuit = "c";
    }

    if(mySuit == diamonds){
        resultSuit = "d";
    }

    if(mySuit == hearts){
        resultSuit = "h";
    }


    if(myRank == 1){
        resultRank = "A";
    }

    else if(myRank == 11){
        resultRank = "J";
    }

    else if(myRank == 12){
        resultRank = "Q";
    }

    else if(myRank == 13){
        resultRank = "K";
    }

    else{
        for(int i = 2; i <= 10; i++){
            if(myRank == i){
                resultRank = to_string(myRank);
                break;
            }
        }
    }

    result = resultRank + resultSuit;
    //WE CAN CONCATENATE THIS
    return result;
}



/* CHECKS TO SEE IF SUIT OF ONE CARD IS EQUAL TO THE SUIT OF ANOTHER CARD
input parms - input is a Card`
output parms - returns true if suit same as c, false otherwise
*/
bool Card::sameSuitAs(const Card &c) const {

    if(mySuit == c.mySuit){
        return true;
    }

    else{
        return false;
    }
}

/* GETS RANK OF CARD
input parms - no input
output parms - returns rank, 1..13
*/
int Card::getRank() const {
    return myRank;
}


/* ABBREVIATES THE SUIT TO JUST ONE LETTER
input parms - input is the suit of the card
output parms - return "s", "h",...
*/
string Card::suitString(Suit s) const {
    if(s == spades){
        return "s";
    }
    else if(s == hearts){
        return "h";
    }
    else if(s == diamonds){
        return "d";
    }
    else if(s == clubs){
        return "c";
    }

    else{
        return "-1";
    }
}

/* CONVERTING THE RANK OF THE CARD TO A STRING
input parms - input is the rank of the card
output parms - return "A", "2", ..."Q"
*/

string Card::rankString(int r) const {

    string result;

    if(r == 1){
        return "A";
    }

    else if(r == 11){
        return "J";
    }

    else if(r == 12){
        return "Q";
    }

    else if(r == 13){
        return "K";
    }

    //FOR NUMBERS BETWEEN 2 AND 10
    else{
        for(int i = 2; i <= 10; i++){
            if(r == i){
               result = to_string(r);
               break;
            }
        }
        return result;
    }
}


//SO WE ARE ABLE TO PRINT OUT THE CARDS
ostream& operator << (ostream& out, const Card& c){
    out <<  c.toString();
    return out;
}