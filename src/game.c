#include <stdio.h>
#include "game.h"
#include "term.h"
#include "render.h"
#include "input.h"



void game_start()
{
    term_init();
    term_clear();

    int selected = 1;

    while(1)
    {
        term_clear();
        draw_opp_cards_left();
        draw_opp_cards_right();
        draw_card(2, 25, "K", HEART, selected == 1);
        draw_hidden_card(2, 40, selected == 2);
        draw_card(2, 55, "2", CLUBS, selected == 3);
        draw_card(2, 70, "A", DIAMOND, selected == 4);
        draw_card(2, 85, "9", SPADES, selected == 5);

        fflush(stdout);

        Key k = read_key();
        if (k == KEY_QUIT)
            break;
        if (k == KEY_LEFT && selected > 1)
            selected--;
        if (k == KEY_RIGHT && selected < 5)
            selected++;
    }

    term_restore();
    term_clear();
}