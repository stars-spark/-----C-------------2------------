/* Classifies a poker hand */

#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */

bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */

int hand[5][2];

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);


int main(void){
  for (;;) { 
    read_cards();
    analyze_hand();
    print_result();
  }
}


void read_cards(void){
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card, duplicate_card;
  int cards_read = 0;

  while (cards_read < NUM_CARDS) {
    bad_card = false;
  duplicate_card = false;
    printf("Enter a card: ");

    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }

    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }

    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;
    
  for(int i = 0; i < cards_read;i++)
    if(hand[i][0] == rank &&hand[i][1] == suit) duplicate_card = true;
    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (duplicate_card)
      printf("Duplicate card; ignored.\n");
    else {
      hand[cards_read][0] = rank;
      hand[cards_read][1] = suit;
      cards_read++;
    }
  }
}

void analyze_hand(void){
  int num_consec = 0;
  int rank, suit;

  straight = false;
  flush = true;
  four = false;
  three = false;
  pairs = 0;

  /* check for flush */
  for (int i = 0; i < NUM_CARDS; i++)
    if (hand[i][1] != hand[0][1])
      flush = false;

  /* check for straight */
  int min = hand[0][0];
  bool sr[5] = {false,false,false,false,false};
   for (int i = 0; i < NUM_CARDS; i++)
    if(min>hand[i][0]) min= hand[i][0];
  for (int i = 0; i < NUM_CARDS; i++)
    sr[hand[i][0] - min] = true;
  if (sr[0] ==true&&sr[1] ==true&&sr[2] ==true&&sr[3] ==true&&sr[4] ==true) {
    straight = true;
    return;
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  int rank_list[NUM_RANKS]={0};
  for(int i = 0;i<NUM_CARDS;i++) rank_list[hand[i][0]]++;
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (rank_list[rank] == 4) four = true;
    if (rank_list[rank] == 3) three = true;
    if (rank_list[rank] == 2) pairs++;
  }
}

void print_result(void){
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");

  printf("\n\n");
}
