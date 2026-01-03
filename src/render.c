#include <stdbool.h>
#include <string.h>

#include "render.h"
#include "term.h"
#include <stdio.h>

#ifdef _WIN32
bool use_color = false;
#else
   bool use_color = true;
#endif


void print_help()
{
    printf("\n%sterm-holdem%s - Terminal Texas Hold'em poker\n",RED, RESET);

    printf(
        "a CLI for playing a terminal-based Texas Hold'em with your own computer\n\n"
        "Usage:\n"
        "  term-holdem [options]\n\n"
        "Options:\n"
        "  -h, --help        Show this help message\n"
        "  -v, --version     Show version information\n"
    );
}

void print_version(const char *version)
{
    printf("term-holdem %s\n", version);
}


void draw_card(int row, int col, Cards card, bool selected, bool shown)
{
    const char *hl_on  = selected ? "\033[48;5;238m" : "";
    const char *hl_off = selected ? "\033[49m" : "";
    const char *color = (!strcmp(card.suit, HEART) || !strcmp(card.suit, DIAMOND)) ? RED : GREEN;

    if(shown)
    {
        term_move(row, col);
        printf("%s┌──────────┐%s", hl_on, hl_off);
        term_move(row+1, col);
        printf("%s│ %-8s │%s", hl_on, card.rank, hl_off);
        term_move(row+2, col);
        printf("%s│          │%s", hl_on, hl_off);
        term_move(row+3, col);
        printf("%s│          │%s", hl_on, hl_off);
        term_move(row+4, col);
        printf("%s│    %s%s%s%s     │%s", hl_on, color, card.suit, RESET, hl_on, hl_off);
        term_move(row+5, col);
        printf("%s│          │%s", hl_on, hl_off);
        term_move(row+6, col);
        printf("%s│          │%s", hl_on, hl_off);
        term_move(row+7, col);
        printf("%s│ %8s │%s", hl_on, card.rank, hl_off);
        term_move(row+8, col);
        printf("%s└──────────┘%s", hl_on, hl_off);
    }
    else
    {
        term_move(row, col);
        printf("%s┌──────────┐%s", hl_on, hl_off);
        term_move(row+1, col);
        printf("%s│  *    ─┐ │%s", hl_on, hl_off);
        term_move(row+2, col);
        printf("%s│   \\      │%s", hl_on, hl_off);
        term_move(row+3, col);
        printf("%s│    \\     │%s", hl_on, hl_off);
        term_move(row+4, col);
        printf("%s│     \\    │%s", hl_on, hl_off);
        term_move(row+5, col);
        printf("%s│      \\   │%s", hl_on, hl_off);
        term_move(row+6, col);
        printf("%s│       \\  │%s", hl_on, hl_off);
        term_move(row+7, col);
        printf("%s│ └─     * │%s", hl_on, hl_off);
        term_move(row+8, col);
        printf("%s└──────────┘%s", hl_on, hl_off);
    }
}

void draw_opp_cards_left(int row, int col)
{

    term_move(row, col);
    printf("          ╱│\n");
    term_move(row + 1, col);
    printf("         ╱ │\n");
    term_move(row + 2, col);
    printf("        ╱  │\n");
    term_move(row + 3, col);
    printf("   ╱│  ╱   │\n");
    term_move(row + 4, col);
    printf("  ╱ │  │   │\n");
    term_move(row + 5, col);
    printf(" ╱  │  │   │\n");
    term_move(row + 6, col);
    printf("╱   │  │   │\n");
    term_move(row + 7, col);
    printf("│   │  │   │\n");
    term_move(row + 8, col);
    printf("│   │  │   │\n");
    term_move(row + 9, col);
    printf("│   │  │  ╱ \n");
    term_move(row + 10, col);
    printf("│   │  │ ╱ \n");
    term_move(row + 11, col);
    printf("│   │  │╱ \n");
    term_move(row + 12, col);
    printf("│  ╱ \n");
    term_move(row + 13, col);
    printf("│ ╱ \n");
    term_move(row + 14, col);
    printf("│╱ \n");
}

void draw_opp_cards_right(int row,int col)
{

    term_move(row, col);
    printf("│╲        \n");
    term_move(row+1, col);
    printf("│ ╲       \n");
    term_move(row+2, col);
    printf("│  ╲      \n");
    term_move(row+3, col);
    printf("│   │  │╲  \n");
    term_move(row+4, col);
    printf("│   │  │ ╲ \n");
    term_move(row+5, col);
    printf("│   │  │  ╲\n");
    term_move(row+6, col);
    printf("│   │  │   │\n");
    term_move(row+7, col);
    printf("│   │  │   │\n");
    term_move(row+8, col);
    printf("│   │  │   │\n");
    term_move(row+9, col);
    printf(" ╲  │  │   │\n");
    term_move(row+10, col);
    printf("  ╲ │  │   │\n");
    term_move(row+11, col);
    printf("   ╲│  │   │\n");
    term_move(row+12, col);
    printf("        ╲  │\n");
    term_move(row+13, col);
    printf("         ╲ │\n");
    term_move(row+14, col);
    printf("          ╲│\n");
}

void draw2cards(int row, int col, Cards cards[])
{
    draw_card(row, col, cards[0], false, true);
    draw_card(row, col + 15, cards[1], false, true);    
}

void draw_table(int row, int col, int pot)
{
    int row_start_1 = row + OPP1_CARD_ROW;
    int col_start_1 = col + OPP1_CARD_COL + CARD_WIDTH + 1;
    term_move(row_start_1, col_start_1);
    printf("──────────────────────────────────────────────────────────────────────────────────────────");
    
    int row_start_2 = row + PLAYER_CARD_ROW + 2;
    int col_start_2 = col + 1;
    term_move(row_start_2, col_start_2);
    printf("────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");

    char pot_val[10];
    snprintf(pot_val, 10, "%d", pot);
    char str[24] = "Pot : ";
    strcat(str, pot_val);
    term_move(row + OPP1_CARD_ROW + 12, col + (UI_WIDTH - strlen(str))/2);
    printf("%s",str);
}

void draw_screen(int row, int col,Cards community[], Cards opp1[], Cards opp2[], Cards player[], bool opp1_hidden, bool opp2_hidden, int num_of_hidden_community)
{
    term_clear();
    
    draw_table(row, col, 1000);
    draw_opp_cards_left(row + OPP1_CARD_ROW, col + OPP1_CARD_COL);
    draw_opp_cards_right(row + OPP2_CARD_ROW, col + OPP2_CARD_COL);
    draw_card(row + 2, col + 25, community[0], false, num_of_hidden_community < 5);
    draw_card(row + 2, col + 40, community[1], false, num_of_hidden_community < 4);
    draw_card(row + 2, col + 55, community[2], false, num_of_hidden_community < 3);
    draw_card(row + 2, col + 70, community[3], false, num_of_hidden_community < 2);
    draw_card(row + 2, col + 85, community[4], false, num_of_hidden_community < 1);
    draw2cards(row + PLAYER_CARD_ROW, col + PLAYER_CARD_COL, player);
}