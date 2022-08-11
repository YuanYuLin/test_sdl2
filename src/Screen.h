#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>
//#include <sys/types.h>
#include <SDL.h>
#include <SDL_image.h>
#include "GlobalConfig.h"

class Screen
{
public:
    ~Screen();
    static Screen* create(GlobalConfig* config)
    {
        return new Screen(config);
    }

    bool createSurface();
    SDL_Surface* getSurface();
    SDL_Renderer* getRenderer();
    void clear();
    void update();
protected:
private:
    Screen(GlobalConfig* config);
    GlobalConfig* _config;
    SDL_Window* _window;
    SDL_Surface* _surface;
    SDL_Renderer* _renderer;
};

#endif
