#include <stdbool.h>
#include "keyboard.h"

static KeyboardState g_kb_state;

void keyboard_UpdateKeyState(Key key, bool is_down)
{
	g_kb_state.key_states[key] = is_down;
}

KeyboardState keyboard_GetState()
{
	return g_kb_state;
}

bool keyboardState_IsDown(KeyboardState *self, Key key)
{
	return self->key_states[key];
}