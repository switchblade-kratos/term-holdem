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


void draw_card(int row, int col, const char *rank, const char *suit, bool selected)
{
    const char *hl_on  = selected ? "\033[48;5;238m" : "";
    const char *hl_off = selected ? "\033[49m" : "";
    const char *color = (!strcmp(suit, HEART) || !strcmp(suit, DIAMOND)) ? RED : GREEN;



    term_move(row, col);
    printf("%s┌──────────┐%s", hl_on, hl_off);
    term_move(row+1, col);
    printf("%s│ %-8s │%s", hl_on, rank, hl_off);
    term_move(row+2, col);
    printf("%s│          │%s", hl_on, hl_off);
    term_move(row+3, col);
    printf("%s│          │%s", hl_on, hl_off);
    term_move(row+4, col);
    printf("%s│    %s%s%s%s     │%s", hl_on, color, suit, RESET, hl_on, hl_off);
    term_move(row+5, col);
    printf("%s│          │%s", hl_on, hl_off);
    term_move(row+6, col);
    printf("%s│          │%s", hl_on, hl_off);
    term_move(row+7, col);
    printf("%s│ %8s │%s", hl_on, rank, hl_off);
    term_move(row+8, col);
    printf("%s└──────────┘%s", hl_on, hl_off);

    fflush(stdout);
}

void draw_hidden_card(int row, int col, bool selected)
{
    const char *hl_on  = selected ? "\033[48;5;238m" : "";
    const char *hl_off = selected ? "\033[49m" : "";

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

    fflush(stdout);
}

void draw_opp_cards_left()
{
    term_move(7, 0);
    printf("          ╱│\n");
    printf("         ╱ │\n");
    printf("        ╱  │\n");
    printf("   ╱│  ╱   │\n");
    printf("  ╱ │  │   │\n");
    printf(" ╱  │  │   │\n");
    printf("╱   │  │   │\n");
    printf("│   │  │   │\n");
    printf("│   │  │   │\n");
    printf("│   │  │  ╱ \n");
    printf("│   │  │ ╱ \n");
    printf("│   │  │╱ \n");
    printf("│  ╱ \n");
    printf("│ ╱ \n");
    printf("│╱ \n");
}

void draw_opp_cards_right()
{
    int row = 7, col = 112;

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