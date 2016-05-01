#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <stdbool.h>

typedef enum {
	KEY_INVALID = 0,
	KEY_W,
	KEY_A,
	KEY_S,
	KEY_D
} Key;

void keyboard_UpdateKeyState(Key key, bool is_down);

typedef struct keyboardState {
	bool key_states[32];
} KeyboardState;

KeyboardState keyboard_GetState();

bool keyboardState_IsDown(KeyboardState *self, Key key);

#endif
