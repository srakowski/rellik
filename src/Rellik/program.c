#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <GL\GLU.h>
#include "logging.h"

static int run_rellik()
{
	return 0;
}

//static int run_rellik()
//{
//	GLenum error = GL_NO_ERROR;
//	SDL_Window *window = NULL;
//	window = SDL_CreateWindow("Rellik", 100, 100, 1280, 720, SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
//	if (window == NULL)
//	{
//		printf("failed to create window");
//		return 1;
//	}
//
//	SDL_GLContext context;
//	context = SDL_GL_CreateContext(window);
//	if (context == NULL) 
//	{
//		printf("failed to create context");
//		SDL_DestroyWindow(window);
//		return 1;
//	}
//
//	if (SDL_GL_SetSwapInterval(1) < 0)
//		printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
//
//
//	glEnable(GL_DEPTH_TEST);
//	//glDisable(GL_CULL_FACE);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	error = glGetError();
//	if (error != GL_NO_ERROR)
//	{
//		printf("fail");
//		return 1;
//	}
//
//	//glOrtho(-1.920, 1.920, -1.080, 1.080, 0, 100);
//	gluPerspective(45.0f, 1920.0f / 1080.0f, 0.01f, 100);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();	
//
//	error = glGetError();
//	if (error != GL_NO_ERROR)
//	{
//		printf("fail");
//		return 1;
//	}
//
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	error = glGetError();
//	if (error != GL_NO_ERROR)
//	{
//		printf("fail");
//		return 1;
//	}
//	//SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//	//if (renderer == NULL)
//	//{
//	//	printf("failed to create renderer");
//	//	SDL_DestroyWindow(window);		
//	//	return 1;
//	//}
//
//	//SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
//
//	struct vector3 pos;
//	vector3_Init(&pos, 0.0f, 0.0f, 0.0f);
//
//	SDL_Event event;
//	bool end = false;
//	float z = 0.0f;
//	float x = 0.0f;
//	while (!end)
//	{
//		glMatrixMode(GL_MODELVIEW);
//
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		while (SDL_PollEvent(&event))
//		{
//			switch (event.type)
//			{
//			case SDL_WINDOWEVENT_CLOSE:
//			case SDL_QUIT:
//				end = true;
//				break;
//
//			case SDL_KEYDOWN:
//			{
//				SDL_KeyboardEvent *key = &event.key;
//				/*printf("Scancode: 0x%02X", key->keysym.scancode);*/
//				if (key->keysym.scancode == SDL_SCANCODE_W)
//				{
//					pos.z += 1.0f;
//				}
//
//				if (key->keysym.scancode == SDL_SCANCODE_S)
//				{
//					pos.z -= 1.0f;
//				}
//
//				if (key->keysym.scancode == SDL_SCANCODE_A)
//				{
//					pos.x += 1.0f;
//				}
//
//				if (key->keysym.scancode == SDL_SCANCODE_D)
//				{
//					pos.x -= 1.0f;
//				}
//			}
//	//else if (event.type == SDL_KEYDOWN)
//	//{
//	//	//Handle keypress with current mouse position
//	//	int x = 0, y = 0;
//	//	SDL_GetMouseState(&x, &y);
//	//	handleKeys(event.key.keysym.unicode, x, y);
//	//}
//
//			default:
//				break;
//			}
//		}
//
//
//
//		//glMatrixMode(GL_MODELVIEW);
//		//glLoadIdentity();
//		//glTranslatef(pos.x, 0, pos.z);
//		//glRotatef(10, 0, 0, 1);
//		//x -= 0.01f;
//		glLoadIdentity();
//		glTranslatef(0.0f, 0.0f, -10.0f);	// Translate Into The Screen 7.0 Units
//		glRotatef(pos.x, 0.0f, 1.0f, 0.0f);	// Rotate The cube around the Y axis
//		//glRotatef(pos.x, 1.0f, 1.0f, 1.0f);
//
//		
//		//glBegin(GL_QUADS);
//		//	glVertex3f(-0.5f, -0.5f, -10.0f);
//		//	glVertex3f(0.5f, -0.5f, -10.0f);
//		//	glVertex3f(0.5f, 0.5f, -10.0f);
//		//	glVertex3f(-0.5f, 0.5f, -10.0f);
//		//glEnd();
//
//		glBegin(GL_QUADS);		// Draw The Cube Using quads
//								/* Cube Top */
//		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
//		glVertex3f(-1.0f, 1.0f, 1.0f);
//		glVertex3f(-1.0f, 1.0f, -1.0f);
//		glVertex3f(1.0f, 1.0f, -1.0f);
//		glVertex3f(1.0f, 1.0f, 1.0f);
//
//
//		/* Cube Bottom */
//		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
//		glVertex3f(-1.0f, -1.0f, 1.0f);
//		glVertex3f(-1.0f, -1.0f, -1.0f);
//		glVertex3f(1.0f, -1.0f, -1.0f);
//		glVertex3f(1.0f, -1.0f, 1.0f);
//
//		/* Cube Front */
//		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
//		glVertex3f(-1.0f, 1.0f, 1.0f);
//		glVertex3f(1.0f, 1.0f, 1.0f);
//		glVertex3f(1.0f, -1.0f, 1.0f);
//		glVertex3f(-1.0f, -1.0f, 1.0f);
//
//		/* Cube Back */
//		glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
//		glVertex3f(-1.0f, 1.0f, -1.0f);
//		glVertex3f(1.0f, 1.0f, -1.0f);
//		glVertex3f(1.0f, -1.0f, -1.0f);
//		glVertex3f(-1.0f, -1.0f, -1.0f);
//
//		///* Cube Left Side */
//		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
//		glVertex3f(-1.0f, 1.0f, -1.0f);
//		glVertex3f(-1.0f, 1.0f, 1.0f);
//		glVertex3f(-1.0f, -1.0f, 1.0f);
//		glVertex3f(-1.0f, -1.0f, -1.0f);
//
//		///* Cube Right Side */
//		glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
//		glVertex3f(1.0f, 1.0f, -1.0f);
//		glVertex3f(1.0f, 1.0f, 1.0f);
//		glVertex3f(1.0f, -1.0f, 1.0f);
//		glVertex3f(1.0f, -1.0f, -1.0f);
//
//		glEnd();			// End Drawing The Cube
//
//		SDL_GL_SwapWindow(window);
//		//SDL_RenderClear(renderer);
//		//SDL_RenderPresent(renderer);
//
//	}
//
//	SDL_DestroyWindow(window);
//	return 0;
//}

int main(int argc, char **argv)
{
	ilog("Hello World %d", 23);	

	dlog("this is a debug message");

	flog("its a trap!");

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Init failed");
		exit(EXIT_FAILURE);
	}

    //SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
    //SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
    //SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
    //SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
    //SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	if (run_rellik() != 0)
	{
		printf("run_rellik failed");
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
		
	SDL_Quit();
	exit(EXIT_SUCCESS);
}