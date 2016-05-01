#include <stdlib.h>
#include <assert.h>
#include "core.h"
#include "input.h"
#include "inputstate.h"

struct inputState
{
	KeyboardState prevKBState;
	KeyboardState currentKBState;
};

InputState *inputState_Create()
{
	InputState *self = NULL;

	self = (InputState *)calloc(1, sizeof(InputState));
	if (self == NULL)
		wlog("failed to allocate memory for InputState");

	return self;
}

void inputState_Destroy(InputState *self)
{
	assert(self);
	free(self);
}

void inputState_Update(InputState *self)
{
	assert(self);
	self->prevKBState = self->currentKBState;
	self->currentKBState = keyboard_GetState();
}