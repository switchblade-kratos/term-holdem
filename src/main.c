/* term-holdem main entry point */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool use_color = true;

#ifdef _WIN32
	use_color = false;
#endif

/* ANSI colors (portable) */
#define RED    (use_color ? "\033[31m" : "")
#define GREEN  (use_color ? "\033[32m" : "")
#define YELLOW (use_color ? "\033[33m" : "")
#define RESET  (use_color ? "\033[0m"  : "")

#define VERSION "0.1.0"

void print_help(void)
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

void print_version(void)
{
    printf("term-holdem %s\n", VERSION);
}

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
                print_version();
                return 0;
            }
            else if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
            {
                print_help();
                return 0;
            }
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
    printf("Starting term-holdem...\n");
    return 0;
}
