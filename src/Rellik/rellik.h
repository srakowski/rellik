#ifndef _RELLIK_H_
#define _RELLIK_H_

#include "gametime.h"

typedef struct rellik Rellik;

Rellik *rellik_Create();

void rellik_Destroy(Rellik *self);

void rellik_Initialize(Rellik *self);

void rellik_Update(Rellik *self, GameTime gameTime);

void rellik_Render(Rellik *self);

#endif
