#include <stdio.h>
#include <stdbool.h>
#include "ui.h"


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