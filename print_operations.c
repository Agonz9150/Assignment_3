/*======================================================================
print_operations.c


used for function prototypes and constants
======================================================================*/
#include "deck_hands.h"
/*=====================================================================
int *deck
     the deck to be printed
int print_counter (set to start_count)
     keeps track of the next deck to be printed




======================================================================*/
void Print_deck(DECK deck, int shuffled)
{
   int print_counter = START_COUNT;
   int cards_printed = START_COUNT;
   if (shuffled == FALSE)
   {
      printf("Unshuffled deck \n");
   }
   else
   {
      printf("Shuffled deck \n");
   }
   printf("__________________________________________________"
           "______________________________\n");

   for (print_counter; print_counter < MAX_DECK_SIZE; print_counter++)
   {
      
      Print_card(deck.deck[print_counter]);
      cards_printed++;
      if (cards_printed % CARDS_PER_LINE == FULL_LINE)
      {
         printf("\n");
      }
   }
   printf("\n\n\n\n");
 
}

void Print_card(CARD card)

{
   printf("[%s of %s] ", card.value_str, card.suit_str);
}


void Print_hand ( CARD hand[] , int players, int drawn_cards, int sorted, 
                  int ranked, int win, int test, int * rank)
{
   if (test == TRUE)
   {
      printf("%s","Test Hands: \n");
   }

   else if(win == TRUE)
   {
      printf("%s","Player Hands: winner (s) \n");
   }
   else if(ranked == TRUE)
   {
      printf("%s","Player Hands: ranked \n");
   }
   else if(sorted == TRUE) 
   {
      printf("%s","Player Hands: sorted \n");
   }
   else
   {
      printf("%s","Player Hands: \n");
   }
   int card_counter = START_COUNT;
   int player_counter = START_COUNT;
   int card_printed = START_COUNT;
   int win_val = Determine_win_val(rank, players);
   for( player_counter; player_counter < players; player_counter++)
   {
      printf("Player %d hand :\n", player_counter + 1);
      for(card_counter; card_counter < drawn_cards; card_counter++)
      {
         card_printed++;
         int current_index = drawn_cards * player_counter + card_counter;
         Print_card(hand[current_index]);
         if(card_printed % CARDS_PER_LINE == FULL_LINE)
         {
            printf("\n");
          }
      }
      if (ranked == TRUE)
      {
         printf("%s",RANK_NAME_ARRAY[(*(rank + player_counter)) / 
                RANK_IDENTIFIER]);
      }
      if (win == TRUE)
      {

         if( *(rank + player_counter) == win_val)
         {
            printf("%s","  - WINNER");
         }
      }

      printf("\n\n");
      card_counter = START_COUNT;
      card_printed = START_COUNT;
    
   }
   printf("\n\n\n");
}

int Determine_win_val(int *rank, int players)
{
   int current_high = EMPTY_VALUE;
   int player_counter = START_COUNT;
   for (player_counter; player_counter < players; player_counter++)
   {
      if (*(rank + player_counter) > current_high)
      {
         current_high = *(rank + player_counter);
      }
   }
   return current_high;
}
