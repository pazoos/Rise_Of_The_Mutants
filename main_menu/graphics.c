
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../game02/game02.h"

#define GRAPHICS

#include "SDL_ttf.h"

#include "irudiak.h"
#include "graphics.h"
#include "ebentuak.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer=NULL;
int colorR, colorG, colorB;

SDL_Renderer* getRenderer(void) { return gRenderer; }
void doRender()
{
  
    //Fonduan kolorea ezarri
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 250, 250);

    //Fondua marraztu
    SDL_RenderClear(gRenderer);
   
    //pantailaZenb aldagaiak ze pantailatan dagoen adierazten dau,0 menu printzipalerako, 1 nola jokatu atalerako eta 2 aukerak atalerako
    if (pantailaZenb == 0)
    {
        irudiBeltzakMarraztu();
        if (mouse_x > 170 && mouse_y > 60 && mouse_y < 120 && mouse_x < 460)
        {
            irudiGorriaMarraztu(4);
            
        }
        if (mouse_x > 60 && mouse_y > 120 && mouse_y < 180 && mouse_x < 500)
        {
            irudiGorriaMarraztu(5);
        }
        if (mouse_x > 120 && mouse_y > 180 && mouse_y < 240 && mouse_x < 460)
        {
            irudiGorriaMarraztu(6);
        }
        if (mouse_x > 170 && mouse_y > 240 && mouse_y < 300 && mouse_x < 400)
        {
            irudiGorriaMarraztu(7);
        }
    }
    if (pantailaZenb == 1)
    {
        nolaJokatuIrudiakMarraztu();
    }

    irudiakMugitu();

    pantailaBerriztu();
    pantailaGarbitu();

}
int sgHasieratu()
{
    int ret = 0;
    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("Rise of the MUtants", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
 
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    TTF_Init();
    atexit(TTF_Quit);
    return ret;
}


void sgItxi()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

void arkatzKoloreaEzarri(red, green, blue)
{
    colorR = red;
    colorG = green;
    colorB = blue;
}


void zuzenaMarraztu(x1, y1, x2, y2)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void puntuaMarraztu(x, y)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(gRenderer, x, y);
}

void zirkuluaMarraztu(x, y, r)
{

    int i, h;

    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    for (i = x - r; i <= x + r; i++)
    {
        h = (int)llround(sqrt((double)(r * r - (i - x) * (i - x))));
        SDL_RenderDrawLine(gRenderer, i, y + h, i, y - h);
    }
}



int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest)
{
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = pDest->w;
    src.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

void pantailaGarbitu()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
}


void pantailaBerriztu()
{
    SDL_RenderPresent(gRenderer);
}