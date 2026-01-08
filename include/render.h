#ifndef RENDER_H
#define RENDER_H

#include<stdbool.h>

extern bool use_color;

typedef struct cards 
{
    char *rank;
    char *suit;

    int val;
    int num;
    bool taken;
}Cards;

/* ANSI colors (portable) */
#define RED    (use_color ? "\033[31m" : "")
#define GREEN  (use_color ? "\033[32m" : "")
#define YELLOW (use_color ? "\033[33m" : "")
#define RESET  (use_color ? "\033[39m"  : "")

// for diagonals
#define DIM   "\033[2m"
#define NORM  "\033[22m"


#define HEART "❤"
#define CLUBS "♣"
#define DIAMOND "♦"
#define SPADES "♠"

#define PLAYER_CARD_ROW 23
#define PLAYER_CARD_COL 46
#define OPP1_CARD_ROW 9
#define OPP1_CARD_COL 3
#define OPP2_CARD_ROW 9
#define OPP2_CARD_COL 107
#define CARD_WIDTH 12

#define UI_WIDTH 119
#define UI_HEIGHT 30

void print_help(void);
void print_version(const char *version);
void draw_card(int row, int col, Cards card, bool selected, bool shown);
void draw_opp_cards_left(int row, int col);
void draw_opp_cards_right(int row, int col);
void draw2cards(int row, int col, Cards cards[]);
void draw_screen(int row, int col,Cards community[], Cards opp1[], Cards opp2[], Cards player[], bool opp1_hidden, bool opp2_hidden, int num_of_hidden_community);
bool draw_quit_confirm(int row, int col);

#endif
