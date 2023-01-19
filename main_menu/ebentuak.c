#include "ebentuak.h"
#include "graphics.h"
#include "audio.h"
#include "../game02/game02.h"
#include "../game02/game02.c"


#include <SDL.h>

POSIZIOA saguPos;
SDL_Event event;

POSIZIOA saguarenPosizioa() { return saguPos; }

int ebentuaJasoGertatuBada(void) {
	int ret = 0;
	if (SDL_PollEvent(&event))
	{
		/* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				ret = TECLA_LEFT;
				//actualizaPlayer(-15);
				break;
			case SDLK_RIGHT:
				ret = TECLA_RIGHT;
				//actualizaPlayer(15);
				break;
			case SDLK_DOWN:
				ret = TECLA_DOWN;
				break;
			default:
				ret = event.key.keysym.sym;
				break;
			}
			break;
		case SDL_QUIT:
			ret = GERTAERA_IRTEN;
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				ret = SAGU_BOTOIA_EZKERRA;
				break;
			case SDL_BUTTON_RIGHT:
				ret = SAGU_BOTOIA_ESKUMA;
				break;
			default:
				ret = event.button.button;
				break;
			}
			break;
		case SDL_MOUSEMOTION:
			//ALDAGIA OROKOR BATEN EZARRIK ODUGU X ETA Y GERO FUNZTIO BATEKIN IRAKURTZEKO AZKEN EBENTUAREN POSIZIOA
			saguPos.x = event.motion.x;
			saguPos.y = event.motion.y;
			ret = SAGU_MUGIMENDUA;
			break;
		default:
			break;
		}
	}
	return ret;
}
SDL_Window* window = NULL;
int processEvents(void)
{
	SDL_Event event;
	int done = 0;



	arratoiaPosAurkitu();
	//check events
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = 1;
			}
		}
		break;
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = 1;
				break;
			}
		}
		break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (pantailaZenb == 0)
			{
				if (mouse_x > 170 && mouse_y > 60 && mouse_y < 120 && mouse_x < 460)
				{
					jokoaAurkeztu();
					jokatu();

				}
				if (mouse_x > 170 && mouse_y > 240 && mouse_y < 300 && mouse_x < 400)
				{
					done = 1;
				}
				if (mouse_x > 60 && mouse_y > 120 && mouse_y < 180 && mouse_x < 400)
				{
					playSound(0);

					pantailaZenb = 1;
					
				}
			}
			if (pantailaZenb == 1)
			{
				if (mouse_x > 0 && mouse_y > 400 && mouse_y < 450 && mouse_x < 100)
				{
					playSound(0);
					pantailaZenb = 0;
				}
			}
			break;
		}
		case SDL_QUIT: {
			//quit out of the game
			done = 1;
			break;
		}
		}
	}


	return done;
}
void arratoiaPosAurkitu()
{
	SDL_PumpEvents();
	SDL_GetMouseState(&mouse_x, &mouse_y);
}
void eventLoop()
{
	int done = 0;
	while (!done)
	{
		arratoiaPosAurkitu();
		//Check for events
		done = processEvents();

		//render display
		doRender();

		menuOptionSound = 0;

		//don't burn up the CPU
		SDL_Delay(10);
	}
}
