// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides myfile and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

void turn(int turn);

ofstream myfile;

int main() {

    //How do you do myfile stuff idk brooooooo
    myfile.open ("gofish_results.txt");

    cout << "Done writing result to gofish_results.txt" << endl;

    int numCards = 7;   //7 cards for two player game
    Card playerOne;
    Card playerTwo;

    Player p1("Jamal");   //players
    Player p2("Ricky");


    //WE SHOULD PROB GET RID OF THE SHUFFLE PRINTING LOL WHEN GAME ACTUALLY STARTS
    Deck d;  //create a deck of cards
    myfile << "Deck has been created!" << endl;

    //PLAYER ONE ALWAYS WILL GO FIRST
    //SHUFFLE THE DECK
    d.shuffle();
    myfile << "Deck has been shuffled!" << endl;
    myfile << endl;
    //myfile << d.size() << endl;
    myfile << endl;

    //DEAL HANDS TO PLAYERS
    dealHand(d, p1, numCards);  //deal hand to player1
    dealHand(d, p2, numCards);  //deal hand to player2


    myfile << p1.getName() << " has: ";
    myfile << p1.showHand() << endl;
    myfile << p2.getName() << " has: ";
    myfile << p2.showHand() << endl;

    myfile << endl;
    myfile << "CHECK IF THERE ARE BOOKS BEFORE GAME STARTS!" << endl;
    p1.checkBefore();
    p2.checkBefore();

    myfile << p1.getName() << " has: ";
    myfile << p1.showHand() << endl;
    myfile << p2.getName() << " has: ";
    myfile << p2.showHand() << endl;

    //GOTTA FIGURE OUT WHEN TO START DEALING CARDS
    //USER WILL PICK UP CARDS IF THEY HAVE NO MORE REMAINING ORRR
    //IF THE OTHER PLAYER SAYS GO FISHHHHHH
    //WHEN IS THE GAME SUPPOSED TO END
    myfile << endl;
    myfile << "GAME STARTS!" << endl;
    //game end when all 26 books have been formed
    //keep going until size is zero and all books have been completed
    //WELL FIX THE TURNS LATER LETS JUST MAKE SURE THIS SHIT WORKS LMAO


    //****************************************************************************************************
    //****************************************************************************************************
    //GAME STARTS **********************************************************************************888
    //IMPORTANT VARIABLES FOR THE MAIN WHILE LOOP
    int sum = 0;    //for the total amount of books
    //ALSO PLAYER 1 ALWAYS WILL GO FIRST
    int turn = 1;   //make 1 if player1 turn, make 2 if player2 turn
    int size = d.size();

    while(sum != 26){
    //****************************************************************************************************
    //PLAYER 1 TURN LETS GOOOO
    //****************************************************************************************************
    if (turn == 1) {

        //THIS IS IF PLAYER HAS NO MORE CARDS AND THE DECK IS NOT EMPTY.
        //EVEN IF PLAYER BOOKED ON LAST TURN, IF THEY HAVE NO CARDS THEY HAVE TO DRAW
        //CANNOT GO AGAIN
        if((p1.getHandSize() == 0) && (size != 0)){
            playerOne = d.dealCard();
            p1.addCard(playerOne);
            turn = 2;
            continue;
        }

        //IF PLAYER HAS NO CARDS AND DECK IS EMPTY, THEN JUST GO TO NEXT PLAYER
        if((p1.getHandSize() == 0) && (size == 0)){
            turn = 2;
            continue;
        }


        playerOne = p1.chooseCardFromHand();    //returns particular card selected from user hand
        myfile << endl;
        myfile << p1.getName() << " asks - Do you have a " << playerOne.rankString(playerOne.getRank()) << "?" << endl;


        //CHECK IF PLAYER 2 has the card that PLAYER 1 ASKED FOR
        if (p2.cardInHand(playerOne) == true) {
            myfile << p2.getName() << " says - I have a " << playerOne.rankString(playerOne.getRank()) << "!" << endl;
            playerTwo = p2.removeCardFromHand(playerOne);   //returns card that was removed from p2 hand
            p1.bookCards(playerOne, playerTwo);  //put the two cards in the book
            p1.removeCardFromHand(playerOne);
            myfile << p1.getName() << " books the " << playerOne.rankString(playerOne.getRank()) << "!" << endl;

            //PRINT OUT STATUS OF HANDS/BOOKS
            myfile << endl;
            myfile << p1.getName() << " has: ";
            myfile << p1.showHand() << endl;
            myfile << p2.getName() << " has: ";
            myfile << p2.showHand() << endl;

            myfile << p1.getName() << "'s Books: ";
            myfile << p1.showBooks() << endl;
            myfile << p2.getName() << "'s Books: ";
            myfile << p2.showBooks() << endl;
            myfile << "-------------------------------------------------------" << endl;

            size = d.size();
            if((p2.getHandSize() == 0) && (size != 0)){
                playerTwo = d.dealCard();
                p2.addCard(playerTwo);
            }
            sum = (p1.getBookSize() / 2) + (p2.getBookSize() / 2);  //ALWAYS CHECK SUM BEFORE PROCEEDING
            continue;
        }

        //IF PLAYER 2 DOES NOT HAVE THE CARD THAT PLAYER 1 NEEDS
        else {
            myfile << p2.getName() << " says - Go Fish! " << endl;    //player2 says GO FISH
            playerOne = d.dealCard();   //player1 picks card from top of the deck
            myfile << p1.getName() << " draws " << playerOne.toString() << endl;

            //checks if a book was formed from choosing this NEW CARD
            if(p1.checkForBook(playerOne) == true){
                myfile << p1.getName() << " books the " << playerOne.rankString(playerOne.getRank()) << "!" << endl;
            }

            else{
                p1.addToFront(playerOne);  //add only if it cannot be booked
            }

            size = d.size();

            if((p1.getHandSize() == 0) && (size != 0)){
                playerOne = d.dealCard();
                p1.addCard(playerOne);
            }

            //PRINT OUT THE STATUS OF THE HAND/BOOKS
            myfile << endl;
            myfile << p1.getName() << " has: ";
            myfile << p1.showHand() << endl;
            myfile << p2.getName() << " has: ";
            myfile << p2.showHand() << endl;

            myfile << p1.getName() << "'s Books: ";
            myfile << p1.showBooks() << endl;
            myfile << p2.getName() << "'s Books: ";
            myfile << p2.showBooks() << endl;
            myfile << "-------------------------------------------------------" << endl;

            turn = 2;   //change turn to PLAYER TWO
            size = d.size();
            sum = (p1.getBookSize() / 2) + (p2.getBookSize() / 2);  //ALWAYS CHECK SUM BEFORE PROCEEDING
            continue;   //to go to the next iteration or TURN
        }
    }

    if(turn == 2){

        if((p2.getHandSize() == 0) && (size != 0)){
            playerTwo = d.dealCard();
            p2.addCard(playerTwo);
            turn = 1;
            continue;
        }

        //IF PLAYER HAS NO CARDS AND DECK IS EMPTY, THEN JUST GO TO NEXT PLAYER
        if((p2.getHandSize() == 0) && (size == 0)){
            turn = 1;
            continue;
        }

        playerTwo = p2.chooseCardFromHand();
        myfile << endl;
        myfile << p2.getName() << " asks - Do you have a " << playerTwo.rankString(playerTwo.getRank()) << "?" << endl;

        //CHECK IF PLAYER 1 has the card that PLAYER 2 ASKED FOR
        if(p1.cardInHand(playerTwo) ==  true){
            myfile << p1.getName() << " says - I have a " << playerTwo.rankString(playerTwo.getRank()) << "!" << endl;
            playerOne = p1.removeCardFromHand(playerTwo);   //returns card that was removed from p2 hand
            p2.bookCards(playerOne, playerTwo);  //put the two cards in the book
            p2.removeCardFromHand(playerTwo);

            myfile << p2.getName() << " books the " << playerTwo.rankString(playerTwo.getRank()) << "!" << endl;
            myfile << endl;
            myfile << p1.getName() << " has: ";
            myfile << p1.showHand() << endl;
            myfile << p2.getName() << " has: ";
            myfile << p2.showHand() << endl;

            myfile << p1.getName() << "'s Books: ";
            myfile << p1.showBooks() << endl ;
            myfile << p2.getName() << "'s Books: ";
            myfile << p2.showBooks() << endl;
            myfile << "-------------------------------------------------------" << endl;

            size = d.size();
            if((p1.getHandSize() == 0) && (size != 0)){
                playerOne = d.dealCard();
                p1.addCard(playerOne);
            }

            sum = (p1.getBookSize() / 2) + (p2.getBookSize() / 2);  //ALWAYS CHECK SUM BEFORE PROCEEDING
            continue;
        }


        else{
            myfile << p1.getName() << " says - Go Fish! " << endl;    //player2 says GO FISH
            playerTwo = d.dealCard();   //player1 picks card from top of the deck
            myfile << p2.getName() << " draws " << playerTwo.toString() << endl;

            //checks if a book was formed from choosing this NEW CARD
            if(p2.checkForBook(playerTwo) == true){
                myfile << p2.getName() << " books the " << playerTwo.rankString(playerTwo.getRank()) << "!" << endl;
            }

            else{
                p2.addToFront(playerTwo);  //add only if it cannot be booked
            }

            size = d.size();
            if((p2.getHandSize() == 0) && (size != 0)){
                playerTwo = d.dealCard();
                p2.addCard(playerTwo);
            }

            myfile << endl;
            myfile << p1.getName() << " has: ";
            myfile << p1.showHand() << endl;
            myfile << p2.getName() << " has: ";
            myfile << p2.showHand() << endl;

            myfile << p1.getName() << "'s Books: ";
            myfile << p1.showBooks() << endl;
            myfile << p2.getName() << "'s Books: ";
            myfile << p2.showBooks() << endl;
            myfile << "-------------------------------------------------------" << endl;

            turn = 1;   //change turn to PLAYER TWO
            size = d.size();
            sum = (p1.getBookSize() / 2) + (p2.getBookSize() / 2);  //ALWAYS CHECK SUM BEFORE PROCEEDING
            continue;   //to go to the next iteration or TURN
        }
    }
}

    myfile << "RESULTS: " << endl;
    myfile << endl;
    myfile << p1.getName() << "'s Books: ";
    myfile << p1.showBooks() << endl;
    myfile << p1.getName() << " has " << p1.getBookSize() / 2 << " books!" << endl;

    myfile << p2.getName() << "'s Books: ";
    myfile << p2.showBooks() << endl;
    myfile << p2.getName() << " has " << p2.getBookSize() / 2 << " books!" << endl;

    myfile << endl;

    if((p1.getBookSize() / 2) > (p2.getBookSize() / 2)){
        myfile << p1.getName() << " wins the game!" << endl;
    }

    else if((p1.getBookSize() / 2) == (p2.getBookSize() / 2)){
        myfile << "TIE GAME!" << endl;
    }

    else{
        myfile << p2.getName() << " wins the game!" << endl;
    }

    myfile.close();
    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards){


    int flag = 0;

   for (int i = 0; i < numCards; i++) {
       if(d.size() == 0){
           flag = 1;
           break;
       }
       p.addCard(d.dealCard());
   }

   if(flag == 1){
       myfile << "No more cards left in Deck!" << endl;
   }
}