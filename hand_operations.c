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
void Deal_hand( DECK playing_deck , CARD players_hand[],int draw_input,
                int number_of_players)
{

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
         playing_deck.deck[deck_counter];

         deck_counter++;
      }
      player_counter = START_COUNT;
   }
}

void Sort_hand(CARD players_hand[], int draw_input, int number_of_players)
{
   int card_counter = START_COUNT;
   int player_counter = START_COUNT;
   CARD card_store = {EMPTY_VALUE,EMPTY_VALUE,NULL,NULL};
   for(player_counter; player_counter < number_of_players; player_counter++)
   {
      for (card_counter; card_counter < draw_input; card_counter++)
      {
         while(players_hand[(player_counter * draw_input) + card_counter].value
         < players_hand[(player_counter * draw_input) + card_counter 
         - 1].value && card_counter != START_COUNT)
         {
            card_store = 
            players_hand[(player_counter * draw_input) + card_counter];
            
            players_hand[(player_counter * draw_input) + card_counter] = 
            players_hand[(player_counter * draw_input) + card_counter - 1];

            players_hand[(player_counter * draw_input) + card_counter - 1] =
            card_store;
            card_counter--;
         }
      }
    card_counter = START_COUNT;

   }
}

void Rank_hand(CARD *players_hand, int draw_input, int number_of_players,
              int *player_rank)
{
   int card_counter = START_COUNT_ONE;
   int player_counter = START_COUNT;
   for (player_counter; player_counter < number_of_players; player_counter++)
   {
      int rank_array[] = {TRUE,TRUE,FALSE,FALSE,FALSE,FALSE};
      int *rank_array_ptr = rank_array;
      int pair_counter = START_COUNT_ONE;
      int compare_val = EMPTY_VALUE;
      int compare_suit = EMPTY_VALUE;
      for(card_counter; card_counter < draw_input; card_counter++)
      {
         compare_val = (*(players_hand + (draw_input * player_counter) + 
         card_counter)).value  - (*(players_hand + (draw_input * 
         player_counter) + card_counter - DECREASE)).value;
        
         compare_suit = (*(players_hand + (draw_input * player_counter) +
         card_counter)).suit - (*(players_hand + (draw_input *
         player_counter) + card_counter - DECREASE)).suit;

         if (compare_suit != EMPTY_VALUE)
         {
            *(rank_array_ptr + FLUSH_LOCATION) = FALSE;
         }
         if (compare_val != FOLLOWING_VALUE)
         {
            if((*(players_hand + (draw_input * player_counter) +
               card_counter)).value != ACE || (*(players_hand + (draw_input *
               player_counter) + card_counter - DECREASE)).value != FIVE)
            {

               *(rank_array_ptr) = FALSE;
            }
         }
         if (compare_val == EMPTY_VALUE)
         {
            pair_counter++;
         }
         if (compare_val != EMPTY_VALUE && pair_counter != START_COUNT_ONE)
         {
            if (pair_counter == PAIR_VAL)
            {
               if (*(rank_array_ptr + PAIR_LOCATION) == TRUE)
               {
                  *(rank_array_ptr + TWO_PAIR_LOCATION) = TRUE;
               }
               else
               {
                  *(rank_array_ptr + PAIR_LOCATION) = TRUE;
               }
               pair_counter = START_COUNT_ONE;
            }

            if (pair_counter == THREE_KIND_VAL)
            {
               *(rank_array_ptr + THREE_KIND_LOCATION) = TRUE;
               pair_counter == START_COUNT_ONE;
            }
            if (pair_counter == FOUR_KIND_VAL)
            {
               *(rank_array_ptr + FOUR_KIND_LOCATION) = TRUE;
               pair_counter == START_COUNT_ONE;
            }
         }
      }
      if ( *(rank_array_ptr + PAIR_LOCATION) == TRUE &&
           pair_counter == PAIR_VAL)
      {
         *(rank_array_ptr + TWO_PAIR_LOCATION) = TRUE;
      }
      else if (pair_counter > START_COUNT_ONE)
      {
         *(rank_array_ptr + pair_counter) = TRUE;
      }
      *(player_rank + player_counter) = Solve_rank(rank_array_ptr);
      card_counter = START_COUNT_ONE;
      pair_counter = START_COUNT_ONE;
      
   }
}

int Solve_rank( int *rank_array)
{
   if( *(rank_array) == TRUE  && *(rank_array + FLUSH_LOCATION) == TRUE)
   {
      return STRAIGHT_FLUSH;
   }
   if(*(rank_array + FOUR_KIND_LOCATION) == TRUE)
   {
   return FOUR_OF_A_KIND;
   }
   if(*(rank_array + PAIR_LOCATION) == TRUE && 
      *(rank_array + THREE_KIND_LOCATION) == TRUE)
   {
      return FULL_HOUSE;
   }
   if(*(rank_array + FLUSH_LOCATION) == TRUE)
   {
      return FLUSH;
   }
   if(*(rank_array) == TRUE)
   {
      return STRAIGHT;
   }
   if(*(rank_array + THREE_KIND_LOCATION) == TRUE)
   {
      return THREE_OF_A_KIND;
   }
   if(*(rank_array + TWO_PAIR_LOCATION) == TRUE)
   {
      return TWO_PAIR;
   }
   if(*(rank_array + PAIR_LOCATION) == TRUE)
   {
      return PAIR;
   }
   return HIGH_CARD;
}
