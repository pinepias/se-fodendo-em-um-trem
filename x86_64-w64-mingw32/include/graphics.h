#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <map>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;

namespace
{
    const int WIDTH = 768;
    const int HEIGHT = 516;
    const char *title = "Se Fodendo Em Um Trem";
}

class Graphics
{
    public:
        Graphics();
        ~Graphics();

        SDL_Surface *loadImage(const char *path);
        SDL_Renderer *getRenderer();

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;

        std::map<const char *, SDL_Surface *> _textures;
};

#endif