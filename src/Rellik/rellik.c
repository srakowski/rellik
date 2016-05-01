#include <stdlib.h>
#include <assert.h>
#include "core.h"
#include "input.h"
#include "rellik.h"

struct rellik {
	InputState *input;
};

Rellik *rellik_Create()
{
	Rellik *self = NULL;

	self = (Rellik *)calloc(1, sizeof(Rellik));
	if (self == NULL)
	{
		wlog("failed to allocate memory for Rellik");
		return NULL;
	}

	self->input = inputState_Create();
	if (self->input == NULL)
	{
		wlog("inputState_Create returned null");
		free(self);
		return NULL;
	}

	return self;
}

void rellik_Destroy(Rellik *self)
{
	assert(self);
	free(self);
}

void rellik_Initialize(Rellik *self)
{
}

void rellik_Update(Rellik *self, GameTime gameTime)
{
	assert(self);
	inputState_Update(self->input);
}

void rellik_Render(Rellik *self)
{
}
