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
void Print_deck(int *deck, int shuffled)
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
      Print_card(*(deck + print_counter));
      cards_printed++;
      if (cards_printed % CARDS_PER_LINE == FULL_LINE)
      {
         printf("\n");
      }
   }
   printf("\n\n\n\n");
 
}

void Print_card(int card)

{
   int card_value = card % SUIT_IDENTIFIER;
   int suit_index = (card - card_value) / SUIT_IDENTIFIER;
   printf("[%s of %s] ", CARD_VAL_ARRAY[card_value],
          CARD_SUIT_ARRAY[suit_index]);




}


void Print_hand ( int *hand , int players, int drawn_cards)
{
   int card_counter = START_COUNT;
   int player_counter = START_COUNT;
   int card_printed = START_COUNT;
   for( player_counter; player_counter < players; player_counter++)
   {
      printf("Player %d hand \n_________________________________________"
           "_______________________________________\n", player_counter + 1);
      for(card_counter; card_counter < drawn_cards; card_counter++)
      {
         card_printed++;
         Print_card(*(hand + (drawn_cards * player_counter) + card_counter));
         if(card_printed % CARDS_PER_LINE == FULL_LINE)
         {
            printf("\n");
          }
      }
      printf("\n\n\n\n");
      card_counter = START_COUNT;
      card_printed = START_COUNT;
   }

}

