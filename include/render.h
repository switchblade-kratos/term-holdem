#ifndef RENDER_H
#define RENDER_H

#include<stdbool.h>

extern bool use_color;

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

void print_help(void);
void print_version(const char *version);
void draw_card(int row, int col, const char *rank, const char *suit, bool selected);
void draw_hidden_card(int row, int col, bool selected);
void draw_opp_cards_left(void);
void draw_opp_cards_right(void);
#endif
