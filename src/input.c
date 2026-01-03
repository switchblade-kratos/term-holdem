#include "input.h"

#ifndef _WIN32
#include <unistd.h>
#else
#include <conio.h>
#endif

#include <sys/select.h>
#include <unistd.h>

Key read_key(void)
{
#ifndef _WIN32
    fd_set fds;
    struct timeval tv;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    /* 50ms timeout */
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    int r = select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
    if (r <= 0)
        return KEY_NONE;   /* no input, return immediately */

    char c;
    if (read(STDIN_FILENO, &c, 1) != 1)
        return KEY_NONE;

    if (c == 'q')
        return KEY_QUIT;

    if (c == '\033')
    {
        char seq[2];

        /* Use non-blocking reads for escape sequence */
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return KEY_NONE;
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return KEY_NONE;

        if (seq[1] == 'A') return KEY_UP;
        if (seq[1] == 'B') return KEY_DOWN;
        if (seq[1] == 'C') return KEY_RIGHT;
        if (seq[1] == 'D') return KEY_LEFT;
    }
#else
    if (_kbhit())
    {
        int c = _getch();
        if (c == 'q') return KEY_QUIT;
    }
#endif

    return KEY_NONE;
}

