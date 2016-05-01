#ifndef _INPUTSTATE_H_
#define _INPUTSTATE_H_

typedef struct inputState InputState;

InputState *inputState_Create();

void inputState_Destroy(InputState *self);

void inputState_Update(InputState *self);

#endif
