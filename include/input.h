#ifndef INPUT_H
#define INPUT_H

typedef enum {
    KEY_NONE,
    KEY_QUIT,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN
} Key;

Key read_key(void);

#endif
