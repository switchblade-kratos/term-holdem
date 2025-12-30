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

        draw_card(2, 5, "K", HEART, selected == 1);
        draw_card(2, 20, "A", SPADES, selected == 2);
        draw_card(2, 35, "2", CLUBS, selected == 3);
        draw_card(2, 50, "A", DIAMOND, selected == 4);
        draw_card(2, 65, "9", SPADES, selected == 5);

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