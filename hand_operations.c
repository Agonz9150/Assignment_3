/*=======================================================================
hand_operations.c

Needed for function prototypes and constants
======================================================================*/

#include "deck_hands.h"

/*===============================================================
int *deck 
     deck to draw cards from
int number_of_players 
      number of players to deal to
int draw_input
      number of cards to give to each player
const int TOTAL_INDEX(draw_input*number_of_players)
      number of total cards to deal
int players_hand[TOTAL_INDEX]
       used to store player's hands
int initialize_index (set to start index)
       used to initialize the drawn_cards array
int player counter (set to start_counter)
       used to keep track of players dealt
int draw_counter (set to start_counter)
       used to keep track of cards dealt per person
int deck_counter (set to start_counter)
       used to move through the deck


This fuction Creates the player hand and initializes the values to 0.

Ex) 2 players 2 cards

Players_hand = {0,0 (||) 0,0} ( the (||) is not actually in the array,
                                it represents the seperator between each
                                person.

Next the function starts dealing cards to each player doing the following:


loop  for every card that needs to be dealt to each person
        for every person
           take card from deck and add it to player hand

ex) deck - (2, 3, 4, 5 ......)
   before loop - players_hand = {0,0 (||) 0,0}
   after loop -  players_hand = {2,4 (||) 3,5}

the program then request for the print_hand function



====================================================================*/
void Deal_hand( int *deck , int number_of_players, int draw_input)
{
   const int TOTAL_INDEX = draw_input * number_of_players;
   int players_hand[TOTAL_INDEX];
   int initialize_index = START_INDEX;
   for (initialize_index ; initialize_index < TOTAL_INDEX ;
        initialize_index++)
   {
      players_hand[initialize_index] = EMPTY_VALUE;
   }

   int player_counter = START_COUNT;
   int draw_counter = START_COUNT;
   int deck_counter = START_COUNT;
   for(draw_counter; draw_counter < draw_input; draw_counter++)
   {
      for ( player_counter;
            player_counter < number_of_players;
            player_counter++)
      {
         players_hand[(player_counter * draw_input) + draw_counter] = 
         *(deck + deck_counter);

         *(deck + deck_counter) = EMPTY_VALUE;
         deck_counter++;
      }
      player_counter = START_COUNT;
   }
  Print_hand(players_hand,number_of_players,draw_input);
}
