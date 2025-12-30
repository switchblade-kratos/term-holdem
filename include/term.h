#ifndef TERM_H
#define TERM_H

void term_init(void);
void term_restore(void);
void term_clear(void);
void term_move(int row, int col);

#endif