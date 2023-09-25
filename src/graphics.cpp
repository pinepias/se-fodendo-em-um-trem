#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics.h"

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, title);
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->_window);
}

SDL_Surface *Graphics::loadImage(const char *path)
{
    if (this->_textures.count(path) == 0)
    {
        this->_textures[path] = IMG_Load(path);
    }

    return this->_textures[path];
}

SDL_Renderer *Graphics::getRenderer()
{
    return this->_renderer;
}