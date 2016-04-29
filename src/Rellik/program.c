#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>

static int run_rellik()
{
	SDL_Window *window = NULL;
	window = SDL_CreateWindow("Rellik", 100, 100, 1280, 720, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		printf("failed to create window");
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("failed to create renderer");
		SDL_DestroyWindow(window);		
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);

	SDL_Event event;
	bool end = false;
	while (!end)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_WINDOWEVENT_CLOSE:
			case SDL_QUIT:
				end = true;
				break;

			default:
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	return 0;
}

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL_Init failed");
		exit(EXIT_FAILURE);
	}

	if (run_rellik() != 0)
	{
		printf("run_rellik failed");
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
		
	SDL_Quit();
	exit(EXIT_SUCCESS);
}