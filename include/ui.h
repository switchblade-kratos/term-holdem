#ifndef UI_H
#define UI_H

#include<stdbool.h>

extern bool use_color;

/* ANSI colors (portable) */
#define RED    (use_color ? "\033[31m" : "")
#define GREEN  (use_color ? "\033[32m" : "")
#define YELLOW (use_color ? "\033[33m" : "")
#define RESET  (use_color ? "\033[0m"  : "")

void print_help(void);
void print_version(const char *version);

#endif