/*=================================================================
deck_operations.c


Needed for functions and constants
=================================================================*/
#include "deck_hands.h"

/* ================================================================
Int current_suit ( set to Diamond)
      used to start looping through suits
int current_array ( set to start_index)
      used to keep track of the deck index
static int deck (size MAX_DECK_SIZE, init to 0)
      used to store the deck


This function creates a fresh sorted deck and returns the pointer for
the deck. The deck array is created of size MAX_DECK_SIZE
and set to zero. Next, two loops fill up the deck, inputing values
as follows:

Loop through suit:
      Loop through all card values:
           put current suit and current value into current deck index
           increment deck index

Values of the deck are stored as followed:
     each value is an int representing the sum of the value and 
     the suit according to their values as defined in deck_hands.h
       ex. 110 = Ten of Diamond

Returns the pointer for the deck array.
==================================================================*/

DECK Create_deck()
{
   int current_suit = DIAMOND;
   int current_array = START_INDEX;
   DECK new_deck;
   for ( current_suit; current_suit <= SPADE;
         current_suit = current_suit + SUIT_IDENTIFIER)
   {
      int current_card = TWO;
      for(current_card; current_card <= ACE; current_card++)
      {
         new_deck.deck[current_array].suit = current_suit;
	 new_deck.deck[current_array].suit_str =
         CARD_SUIT_ARRAY[current_suit / SUIT_IDENTIFIER];

         new_deck.deck[current_array].value = current_card;
         new_deck.deck[current_array].value_str =
         CARD_VAL_ARRAY[current_card];

         printf(" %d %s %d %s \n",new_deck.deck[current_array].suit,new_deck.deck[current_array].suit_str,new_deck.deck[current_array].value,new_deck.deck[current_array].value_str);
         current_array++;
      }
   }

   return new_deck;
}

/* ===========================================================================
int *deck(Argument)
      pointer referencing deck to be shuffled
int value_holder (set to empty_value)
     used to hold values during shuffle
int current_shuffle_location ( set to start_index)
     used to keep track of deck index
int random_value (set to empty_value)
     used to store a randomly generated value

This function takes in a pointer for a deck array and shuffles
it according to Durstenfeld's version of the Fisher-Yates shuffle
   https://en.wikipedia.org/wiki/Fisher-Yates_shuffle#The_modern_algorithim


the function starts by seeding the random number generator. Next, the
function initializes the required variables and starts the shuffle loop.
Shuffle loop:
    for each card in deck:
         select a random index
         put the current index's value into value_holder
         take the value in the randomly selected index and put it in the 
             current index
         set the value of the random index by the value saved in step 2


=============================================================================*/
DECK Shuffle_deck ( DECK playing_deck)
{
   CARD value_holder = {EMPTY_VALUE,EMPTY_VALUE,NULL,NULL};
   int current_shuffle_location = START_INDEX;
   int random_value = EMPTY_VALUE;
   for ( current_shuffle_location;
         current_shuffle_location < MAX_DECK_SIZE;
         current_shuffle_location++)
   {
      random_value = rand() % MAX_DECK_SIZE;
      value_holder = playing_deck.deck[current_shuffle_location];
      playing_deck.deck[current_shuffle_location] =
      playing_deck.deck[random_value];
      playing_deck.deck[random_value] = value_holder;
   }
   return playing_deck;
}



