#include <stdio.h>
/*==========================================================================
stdlib.h- used to access rand()
time.h -  used to seed srand()
==========================================================================*/
#include <stdlib.h>
#include <time.h>
#define TOTAL_SUITS  4
#define MAX_DECK_SIZE  52
#define SUIT_IDENTIFIER  100
#define MIN_PLAYERS  1
#define MAX_PLAYERS  13
#define DRAW_MIN  1
#define DRAW_MAX  13
#define START_INDEX 0
#define START_COUNT 0
#define STRING_ERROR -1
#define ASCII_0 48
#define ASCII_9 57
#define EMPTY_VALUE 0
#define FINSHED 0
#define UNSHUFFLED 0
#define SHUFFLED 1
#define CARDS_PER_LINE 4
#define FULL_LINE 0
#define NEEDED_ARGUMENTS 3
#define LEFT_SHIFT 10

enum Card_Value {TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, 
                SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, 
                JACK = 11, QUEEN = 12, KING = 13, ACE = 14};

enum Card_suit {DIAMOND = 100, CLUB = 200, HEART = 300, SPADE = 400};

enum Boolean {FALSE = 0, TRUE = 1};


extern const char *CARD_VAL_ARRAY[];
extern const char *CARD_SUIT_ARRAY[];

void Print_deck(int[*],int);
void Print_hand(int[*],int,int);
int *Create_deck();
void Shuffle_deck(int[*]);
void Deal_hand(int[*],int,int);
int Argument_check(int);
int Cards_draw_check(char[*]);
int Player_check(char[*]);
int String_to_int(char[*]);
void Print_card(int);
int Total_card_check(int,int);
