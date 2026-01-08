#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "term.h"
#include "render.h"
#include "input.h"



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

// int analyseHand(Cards player_cards[])
// {
//     int rank;

//     int ones = 0, twos = 0, threes = 0, fours = 0;
//     int numbers[5];
//     bool Num4OfKind = false, Num3OfKind = false, TwoPair = false, OnePair = false, straight = false, flush = false, royal = false, high_card = false;

//     for (int i = 0; i < 5; i++)
//         numbers[i] = player_cards[i].val;
//     int counts[13 + 1] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//     for (int i = 0; i < 5; i++)
//         counts[numbers[i]]++;

//     // Checking for number patterns
//     for (int i = 0; i <= 13; i++)
//     {
//         if (counts[i] == 1)
//             ones++;
//         else if (counts[i] == 2)
//             twos++;
//         else if (counts[i] == 3)
//             threes++;
//         else if (counts[i] == 4)
//             fours++;
//     }

//     // Checking the hand
//     if (threes)
//         Num3OfKind = true;
//     if (fours)
//         Num4OfKind = true;
//     if (twos)
//     {
//         if (twos == 2)
//             TwoPair = true;
//         else
//             OnePair = true;
//     }
//     if (ones == 5)
//     {
//         for (int i = 0; i <= 9; i++)
//         {
//             if ((counts[i] + counts[i + 1] + counts[i + 2] + counts[i + 3] + counts[i + 4]) == 5)
//             {
//                 straight = true;
//                 break;
//             }
//         }
//         if ((counts[1] + counts[10] + counts[11] + counts[12] + counts[13]) == 5)
//             royal = true;
//     }

//     int symbols[4] = {0, 0, 0, 0};
//     for (int i = 0; i < 5; i++)
//     {
//         if (player_cards[i].suit == SPADES) // Spade
//             symbols[0]++;
//         else if (player_cards[i].suit == HEART) // Heart
//             symbols[1]++;
//         else if (player_cards[i].suit == DIAMOND) // Diamond
//             symbols[2]++;
//         else // Clubs
//             symbols[3]++;
//     }
//     for (int i = 0; i < 4; i++)
//     {
//         if (symbols[i] == 5)
//         {
//             flush = true;
//             break;
//         }
//     }
//     if ((counts[11] + counts[12] + counts[13]) > 0)
//         high_card = true;

//     // Ranking the hand
//     if (royal && flush)
//         rank = 10;
//     else if (straight && flush)
//         rank = 9;
//     else if (Num4OfKind)
//         rank = 8;
//     else if (Num3OfKind && OnePair)
//         rank = 7;
//     else if (flush)
//         rank = 6;
//     else if (straight)
//         rank = 5;
//     else if (Num3OfKind)
//         rank = 4;
//     else if (TwoPair)
//         rank = 3;
//     else if (OnePair)
//         rank = 2;
//     else if (high_card)
//         rank = 1;
//     else
//         rank = 0;
//     return rank;
// }

// void displayRank(int player_rank, char *str)
// {
//     if (player_rank == 10)
//         strcpy(str, "Current hand : Royal Flush");
//     if (player_rank == 9)
//         strcpy(str, "Current hand : Straight Flush");
//     if (player_rank == 8)
//         strcpy(str, "Current hand : Four of a kind");
//     if (player_rank == 7)
//         strcpy(str, "Current hand : Full house");
//     if (player_rank == 6)
//         strcpy(str, "Current hand : Flush");
//     if (player_rank == 5)
//         strcpy(str, "Current hand : Straight");
//     if (player_rank == 4)
//         strcpy(str, "Current hand : Three of a kind");
//     if (player_rank == 3)
//         strcpy(str, "Current hand : Two Pairs");
//     if (player_rank == 2)
//         strcpy(str, "Current hand : One Pair");
//     if (player_rank == 1)
//         strcpy(str, "Current hand : High Card");
//     if (player_rank == 0)
//         strcpy(str, "Current hand : Shit Cards");
// }


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

        if (rows >= UI_HEIGHT && cols >= UI_WIDTH)
        {
            draw_screen(row_buffer, col_buffer, Community, opp1, opp2, player, true, true, 4);
        }
        else
        {
            handle_term_size(rows, cols);
        }

        fflush(stdout);

        Key k = read_key();
        if (k == KEY_QUIT)
            if(draw_quit_confirm(rows, cols))
                break;
    }


    term_restore();
    term_clear();
   
}