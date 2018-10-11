/*==========================================================================
input_check.c

Required for constants and function prototypes
==========================================================================*/
#include "deck_hands.h"
/*=========================================================================
char *string
       used as the string to convert to int
int current_string_index (set to start index)
       used to keep track of the current string index
char current_char ( set to first value in string)
       used to hold the current char value
int converted value ( set to empty value)
       used to store converted int value
int ascii_value (set to current_char)
        holds the ascii value of the current char


This function has 2 goals- check if the string is an int, and what 
value the string is.

This function operates on the following loop: 
      for each char in string != '\0'
         check if char is int
            if no- return error
            if yes, do the folloeing calculation:
               ccalculated int = calculated int * 10 + (char - '0')
                       (see example)
return converted value

EX) "27"
     converted_value = 0
       char = '2'
       2 is an int
       0*10+2=2
        
       char = '7'
       7 is an int
       2*10+7 = 27
   return 27;



==========================================================================*/
int String_to_int ( char *string)
{
   int current_string_index = START_INDEX;
   char current_char = *string;
   int converted_value = EMPTY_VALUE;
   while(current_char != '\0')
   {
      int ascii_value = current_char;
      
      if (ascii_value > ASCII_9 || ascii_value < ASCII_0)
      {
         printf("You have entered an invalid type. \n");
         return STRING_ERROR;
      }
      
      converted_value = (converted_value * LEFT_SHIFT)
                        + (ascii_value - ASCII_0);
      current_string_index++;
      current_char = *(string + current_string_index);
   }
   return converted_value;

}


/*=======================================================================
char *draw_input
      function checks if this value is in range
int draw_amount (set to the result of the string_to_int of draw_input)
      value being checked

First the function checks if the input is an int using string_to_int. 
      If no - return false
Next the function checks if the value is within range
       If no - return false
If the value passes the check, the function returns the int that was checked.

========================================================================*/
int Cards_draw_check (char *draw_input)
{
   int draw_amount = String_to_int(draw_input);
   if (draw_amount == STRING_ERROR)
   {
      return FALSE;
   }
   if (draw_amount < DRAW_MIN || draw_amount > DRAW_MAX)
   {
      printf("Invalid number of cards. Requires a number from %d to %d.\n",
              DRAW_MIN,DRAW_MAX);
      return FALSE;
   }
   return draw_amount;
}
/*=========================================================================
char *player_input 
       function checks if this value is in range
int players
       value being checked

This function first checks if the input is an int using String to int
       if no - return error
Next the function checks if the input is in range
       if no- return false
If input passes both checks-
      return players

==========================================================================*/


int Player_check (char *player_input)
{
   int players = String_to_int(player_input);
   if(players == STRING_ERROR)
   {
      return FALSE;
   }
   if (players < MIN_PLAYERS || players > MAX_PLAYERS)
   {
      printf("Invalid number of players. Requires a number from %d"
             " to %d.\n",MIN_PLAYERS,MAX_PLAYERS);
      return FALSE;
   }
   return players;
}
/*=========================================================================
int argument 
      used to check value

This function checks if the int passed is equal to the needed arguments
if no - return false
if yes- return true

==========================================================================*/


int Argument_check (int argument)
{
   if(argument == NEEDED_ARGUMENTS)
   {
      return TRUE;
   }
   printf("Incorrect number of arguments inputed \n");
   return FALSE;
}
/*=========================================================================
int players 
    number used to check total cards
int cards
    number used to check total cards
int total cards ( set to cards * players)
     total number of cards


This function calculates the total number of cards needed to be given out.
total_cards = players * cards

if total_cards > max_deck_size
    return false
else 
     return true
=========================================================================*/

int Total_card_check(int players, int cards)
{ 
   int total_cards = players * cards;
   if(total_cards > MAX_DECK_SIZE)
   {
      printf("Too many players. Deck has %d, %d players and %d drawn cards\n"
             "require %d cards\n",MAX_DECK_SIZE,players,cards,total_cards);
      return FALSE;
   }
   return TRUE;
}
