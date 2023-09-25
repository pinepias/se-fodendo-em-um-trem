#include <SDL2/SDL.h>

#include <stdio.h>

#include "game.h"
#include "graphics.h"
#include "sprite.h"

Game::Game()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Error to init SDL2!\n");
        printf("Error: %s\n", SDL_GetError());
        return;
    }

    this->gameLoop();
}

void Game::gameLoop()
{
    Graphics graphics;
    SDL_Event event;

    graphics.loadImage("../res/gfx/o_primeiro_alberto_correndo_da_dor_de_ter_sido_descartado.png");

    Sprite meuAlberto(graphics, "../res/gfx/o_primeiro_alberto_correndo_da_dor_de_ter_sido_descartado.png", 5, 1, 4.0, 0);

    while (running)
    {
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: running = false; break;
            }
        }

        SDL_RenderClear(graphics.getRenderer());
        meuAlberto.start(graphics);
        SDL_RenderPresent(graphics.getRenderer());

        SDL_Delay(DELAY_TIME);
    }
}