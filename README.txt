Name: Arya Amin
UT EID: aa82356
Class ID: #16010
Date: 11/13/2020

********************
PROGRAM DESCRIPTION:
********************

For this project, the program will simulate one game of GO FISH between two different players. At the
start of the game, the deck will be shuffled and 7 cards will be dealt to each player. If a player already
has a book at the beginning of the round, they will book it before the game begins. Player 1 will always go first
and the players will continue to alternate turns until all of the books (a pair of cards with the same rank)
are formed. At the end of the game, there should be 26 books in total formed between the two players. The player
with the most books at the end will win the game!

********************
MORE SPECIFIC RULES:
********************

1) If a Player 1 asks for a card and Player 2 has a card with that same rank, Player 1 will get to have another
turn after he/she has booked the cards. However, if Player 1 books the cards and has no more cards in his/her
hand, Player 1 will have to draw a card from the deck and then Player 2 will get a turn (you'll probably
see this towards the end of the output log).

2) If one Player asks for a card and the other Player does not have this card, the player whose turn it was will
have to pick a card from the top of the deck. Then the other player will have their turn.

3) Also, something to note is that if a Player has no more cards and there is still some cards in the deck,
the player will have the card added in the background and then the other player will begin their turn.
Nothing will be printed out.



********************************
MORE NOTES ABOUT SOME FUNCTIONS:
********************************

1) My Deck will always be sorted like this (As,Ah,Ad,Ac,2s,2h,2d,2c ... up until the Kings) at the
beginning before it is shuffled.

2) Also when each Player chooses what card to ask for, they always will choose the card from the top/beginning
of their hand.


***********************************
Instructions on how to run program:
***********************************

1) Unzip the file
2) Type in make
3) Run ./gofish
4) Once the program starts, it will simulate ONE GAME of GO FISH. The program will show each players turns until
all of the books have been formed.