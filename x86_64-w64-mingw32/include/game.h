#ifndef _GAME_H_
#define _GAME_H_

namespace
{
    const int FPS = 60;
    const int DELAY_TIME = 1000 / FPS;
    bool running = true;
};


class Game
{
    public:
        Game();

        void gameLoop();

};

#endif 