#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "term.h"
#include "render.h"
#include "input.h"

#define UI_WIDTH 119
#define UI_HEIGHT 30

void on_resize(int sig)
{
    (void)sig;
}

void initialiseCards(Cards cards[])
{

    int count = 1, symbol = 0;
    for (int i = 0; i < 52; i++)
    {
        cards[i].num = i + 1;
        if (count > 13)
        {
            count -= 13;
            symbol++;
        }
        cards[i].val = count;
        switch (symbol)
        {
        case 0:
            cards[i].suit = SPADES;
            break;
        case 1:
            cards[i].suit = DIAMOND;
            break;
        case 2:
            cards[i].suit = CLUBS;
            break;
        case 3:
            cards[i].suit = HEART;
            break;
        }
        switch (count)
        {
        case 1:
            cards[i].rank =  "A";
            break;
        case 2 :
            cards[i].rank = "2";
            break;
        case 3 :
            cards[i].rank = "3";
            break;
        case 4 :
            cards[i].rank = "4";
            break;
        case 5 :
            cards[i].rank = "5";
            break;
        case 6 :
            cards[i].rank = "6";
            break;
        case 7 :
            cards[i].rank = "7";
            break;
        case 8 :
            cards[i].rank = "8";
            break;
        case 9 :
            cards[i].rank = "9";
            break;
        case 10 :
            cards[i].rank = "10";
            break;
        case 11:
            cards[i].rank =  "J";
            break;
        case 12:
            cards[i].rank =  "Q";
            break;
        case 13:
            cards[i].rank =  "K";
            break;
        }
        cards[i].taken = false;
        count++;
    }
}

void assignCards(Cards player_cards[], Cards cards[], bool is_com)
{
    int i = 0;
    while (true)
    {
        if ((i == 2 && !is_com) || (i == 5))
            break;
        int num = (rand() % (52 - 1 + 1)) + 1;
        if (cards[num].taken)
            continue;
        player_cards[i].rank = cards[num].rank;
        player_cards[i].num = cards[num].num;
        player_cards[i].suit = cards[num].suit;
        player_cards[i].val = cards[num].val;
        cards[num].taken = true;
        i++;
    }
}



void game_start()
{
    term_init();
    term_clear();
    signal(SIGWINCH, on_resize);

    int rows, cols;
    
    get_term_size(&rows, &cols);

    Cards cards[52];
    Cards Community[5];
    Cards player[2], opp1[2], opp2[2];

    initialiseCards(cards);

    assignCards(Community, cards, true);
    assignCards(player, cards, false);
    assignCards(opp1, cards, false);
    assignCards(opp2, cards, false);


    int selected = 1;
    int row_buffer = (rows - 30)/2, col_buffer = (cols - 119)/2;

    if (row_buffer < 0) row_buffer = 0;
    if (col_buffer < 0) col_buffer = 0;
    while (1)
    {
        /* ALWAYS get current size */
        int new_rows, new_cols;
        get_term_size(&new_rows, &new_cols);

        if (new_rows != rows || new_cols != cols)
        {
            rows = new_rows;
            cols = new_cols;

            row_buffer = (rows - UI_HEIGHT) / 2;
            col_buffer = (cols - UI_WIDTH) / 2;

            if (row_buffer < 0) row_buffer = 0;
            if (col_buffer < 0) col_buffer = 0;

            term_clear();
        }

        /* ---- RENDER DECISION ---- */
        if (rows >= UI_HEIGHT && cols >= UI_WIDTH)
        {
            draw_screen(row_buffer, col_buffer,
                        Community, opp1, opp2, player,
                        true, true, 0);
        }
        else
        {
            handle_term_size(rows, cols);
        }

        fflush(stdout);

        Key k = read_key();
        if (k == KEY_QUIT)
            break;
    }


    term_restore();
    term_clear();
   
}