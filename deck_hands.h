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
#define MAX_PLAYERS  10
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
#define CARDS_PER_HAND 5
#define PLAYER_INPUT  2
#define CARD_INPUT  1
#define START_COUNT_ONE 1
#define DECREASE 1
#define PAIR_LOCATION  2
#define FLUSH_LOCATION  1
#define THREE_KIND_LOCATION  3
#define FOUR_KIND_LOCATION 4
#define TWO_PAIR_LOCATION 5
#define PAIR_VAL 2
#define THREE_KIND_VAL 3
#define FOUR_KIND_VAL 4
#define FOLLOWING_VALUE 1
#define RANK_IDENTIFIER 1000
#define TEST_PLAYERS 9
#define TEST_CARDS 45

enum Card_Value {TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, 
                SEVEN = 7, EIGHT = 8, NINE = 9, TEN = 10, 
                JACK = 11, QUEEN = 12, KING = 13, ACE = 14};

enum Card_suit {DIAMOND = 100, CLUB = 200, HEART = 300, SPADE = 400};

enum Boolean {FALSE = 0, TRUE = 1};

enum Rank {HIGH_CARD = 1000, PAIR = 2000, TWO_PAIR = 3000, 
          THREE_OF_A_KIND = 4000, STRAIGHT = 5000, FLUSH = 6000, 
          FULL_HOUSE = 7000, FOUR_OF_A_KIND = 8000, STRAIGHT_FLUSH = 9000};

struct Card
{ 
   int suit;
   int value;
   const char *suit_str;
   const char *value_str;
};
typedef struct Card CARD;

struct Deck
{
   CARD deck[MAX_DECK_SIZE];
}; 
typedef struct Deck DECK;
static const char *RANK_NAME_ARRAY[] = {NULL,"High Card","One Pair",
                                       "Two Pair","Three of a Kind",
                                       "Straight","Flush","Full House",
                                       "Four of a Kind","Straight Flush"};


extern const char *CARD_VAL_ARRAY[];
extern const char *CARD_SUIT_ARRAY[];

void Print_deck(DECK,int);
void Print_hand(CARD[],int,int,int,int,int,int,int[*]);
DECK Create_deck();
DECK Shuffle_deck(DECK);
void Deal_hand(DECK,CARD[],int,int);
int Argument_check(int);
void Sample_hand(DECK,CARD[]);
int Cards_draw_check(char[*]);
int Player_check(char[*]);
int String_to_int(char[*]);
void Print_card(CARD);
int Total_card_check(int,int);
void Sort_hand(CARD[],int,int);
void Rank_hand(CARD[*],int,int,int[*]);
int Solve_rank(int[*]);
int Determine_win_val(int[*],int);
