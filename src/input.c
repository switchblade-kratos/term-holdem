#include "input.h"

#ifndef _WIN32
#include <unistd.h>
#else
#include <conio.h>
#endif

Key read_key(void)
{
#ifndef _WIN32
    char c;
    if (read(0, &c, 1) != 1)
        return KEY_NONE;

    if (c == 'q') return KEY_QUIT;

    if (c == '\033') {
        char seq[2];
        if (read(0, &seq[0], 1) != 1) return KEY_NONE;
        if (read(0, &seq[1], 1) != 1) return KEY_NONE;

        if (seq[1] == 'A') return KEY_UP;
        if (seq[1] == 'B') return KEY_DOWN;
        if (seq[1] == 'C') return KEY_RIGHT;
        if (seq[1] == 'D') return KEY_LEFT;
    }
#else
    int c = _getch();
    if (c == 'q') return KEY_QUIT;
#endif

    return KEY_NONE;
}
