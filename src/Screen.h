#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>
#include <sys/types.h>
#include <SDL.h>
#include <SDL_image.h>

class Screen
{
public:
    static Screen* create()
    {
        return new Screen(1280, 720);
    }

    bool createSurface();
    SDL_Surface* getSurface();
protected:
private:
    Screen(uint16_t width, uint16_t height);
    uint16_t _width;
    uint16_t _height;
    SDL_Window* _window;
    SDL_Surface* _screenSurface;
};

#endif
