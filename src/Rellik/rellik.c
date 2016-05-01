#include <stdlib.h>
#include "core.h"
#include "input.h"
#include "rellik.h"

struct rellik {
	KeyboardState previousState;
	KeyboardState currentState;
};

Rellik *rellik_Create()
{
	Rellik *self = NULL;

	self = (Rellik *)calloc(1, sizeof(Rellik));
	if (self == NULL)
		wlog("failed to allocate memory for Rellik");

	return self;
}

void rellik_Destroy(Rellik *self)
{
	free(self);
}

void rellik_Initialize(Rellik *self)
{
}

void rellik_Update(Rellik *self, GameTime gameTime)
{
	self->previousState = self->currentState;
	self->currentState = keyboard_GetState();
	if (keyboardState_IsDown(&self->previousState, KEY_W) && !keyboardState_IsDown(&self->currentState, KEY_W))
		ilog("W was pressed");
}

void rellik_Render(Rellik *self)
{
}
