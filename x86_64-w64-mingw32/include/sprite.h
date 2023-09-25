#ifndef _SPRITE_H_
#define _SPRITE_H_

class Graphics;

struct SDL_Texture;
struct SDL_Point;

class Sprite
{
    public:
        Sprite(Graphics &graphics, const char *filePath, int framesX, int framesY, float timeX, float timeY);
        void start(Graphics &graphics);
    private:
        SDL_Texture *_texture;

        float _currentFrameX, _currentFrameY;
        float _timeX, _timeY;
        SDL_Point _frame;
        SDL_Point _frameCount;
        SDL_Point _size;
};

#endif