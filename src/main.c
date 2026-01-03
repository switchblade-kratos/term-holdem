/* term-holdem main entry point */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include<time.h>

#include "game.h"
#include "render.h"


// heart = '\u2665', diamond = '\u2666', clubs = '\u2663', spades = '\u2660';


#define VERSION "0.1.4"


int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (!strcmp(argv[i], "--no-color") || !strcmp(argv[i], "--no-colour"))
			{
				use_color = false;
				continue;
			}

        }
		for (int i = 1; i < argc; i++)
		{
			if (!strcmp(argv[i], "-v") || !strcmp(argv[i], "--version"))
            {
                print_version(VERSION);
                return 0;
            }
            else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
            {
                print_help();
                return 0;
            }
			else if (!strcmp(argv[i], "--no-color") || !strcmp(argv[i], "--no-colour"))
				continue;
            else
            {
                fprintf(stderr,
                        "term-holdem: unknown option '%s'\n"
                        "Try 'term-holdem --help' for more information.\n",
                        argv[i]);
                return 1;
            }
		}
    }

    /* No arguments → start the game (placeholder) */

    srand(time(NULL));

    game_start();
    return 0;
}
