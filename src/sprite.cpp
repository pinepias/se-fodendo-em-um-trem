#include <SDL2/SDL.h>
#include <stdio.h>

#include "sprite.h"
#include "graphics.h"

Sprite::Sprite(Graphics &graphics, const char *filePath, int framesX, int framesY, float timeX, float timeY)
{
    this->_texture = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

    if (this->_texture == NULL)
    {
        printf("Error to load texture!");
        return;
    }
    else
    {
        this->_frameCount.x = framesX;
        this->_frameCount.y = framesY;

        this->_timeX = timeX;
        this->_timeY = timeY;

        SDL_QueryTexture(this->_texture, NULL, NULL, &this->_size.x, &this->_size.y);

    }
}

void Sprite::start(Graphics &graphics)
{
    this->_currentFrameX = this->_currentFrameX +(1 / this->_timeX);
    this->_frame.x = (int)(this->_currentFrameX) % this->_frameCount.x;

    SDL_Rect src = {
        ((this->_size.x / this->_frameCount.x) * this->_frame.x), 0, 
        (this->_size.x / this->_frameCount.x), (this->_size.y / this->_frameCount.y)
    };

    SDL_Rect dest = {
        100, 100, 
        (this->_size.x / this->_frameCount.x), (this->_size.y / this->_frameCount.y)
    };

    SDL_RenderCopy(graphics.getRenderer(), this->_texture, &src, &dest);
}