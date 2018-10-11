/*==================================================================
Used to hold constants and function prototypes
==================================================================*/
#include "deck_hands.h"

/*=================================================================
String representations of enum values
===================================================================*/

char const *CARD_VAL_ARRAY[] = {NULL,NULL,"  Two","Three"," Four",
                              " Five","  Six","Seven","Eight",
                              " Nine","  Ten"," Jack","Queen",
                              " King","  Ace"};
char const *CARD_SUIT_ARRAY[] = {NULL,"Diamonds","Clubs   ","Hearts  ",
                                 "Spades  "};



/*=======================================================================
Main should accept 2 inputs representing DRAWN_CARDS and CURRENT_PLAYERS.

The program will first check if the inputs are correct.
  If not correct - terminates early
  If correct - proceeds
The following checks are made using functions -
   Is there enough inputs (3)?
   Is DRAWN_CARDS in range?
   Is CURRENT_PLAYERS in range?
   Is there enough cards?

After all checks pass, 

the program will generate a deck, 
print the deck to the screen,
shuffle the deck
print the shuffled deck to the screen
deal out to players
print out player hands

^ All using functions to do so.


========================================================================*/

int main(int argc, char *argv[])
{
   const int check = Argument_check(argc);
   if(check == FALSE)
   {
      return FINSHED;
   }
   const int CURRENT_PLAYERS = Player_check(argv[2]);
   const int DRAWN_CARDS = Cards_draw_check(argv[1]);
   if (CURRENT_PLAYERS == FALSE || DRAWN_CARDS == FALSE)
   {
      return FINSHED;
   }
   const int TOTAL_CARDS = Total_card_check(CURRENT_PLAYERS,DRAWN_CARDS);
   if (TOTAL_CARDS == FALSE)
   {
      return FINSHED;
   }

   int *deck = Create_deck();
   Print_deck(deck,UNSHUFFLED);
   Shuffle_deck(deck);
   Print_deck(deck,SHUFFLED);
   Deal_hand(deck,CURRENT_PLAYERS,DRAWN_CARDS);
   return FINSHED;
}
