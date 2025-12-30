#include "term.h"
#include <stdio.h>

#ifndef _WIN32
#include <termios.h>
#include <unistd.h>
static struct termios orig;
#else
#include <windows.h>
#endif

void term_clear(void)
{
    printf("\033[2J\033[H");
    fflush(stdout);
}

void term_move(int row, int col)
{
    printf("\033[%d;%dH", row, col);
}

void term_init(void)
{
    #ifndef _WIN32
        tcgetattr(STDIN_FILENO, &orig);
        struct termios raw = orig;
        raw.c_lflag &= ~(ECHO | ICANON);
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
    #else
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode = 0;
        GetConsoleMode(hOut, &mode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, mode);
    #endif
    printf("\033[?25l");
    fflush(stdout);

}

void term_restore(void)
{
    #ifndef _WIN32
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);
    #endif
    printf("\033[?25h");
    fflush(stdout);
}
