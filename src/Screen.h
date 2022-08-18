#ifndef __SCREEN_H__
#define __SCREEN_H__

#include <stdio.h>
//#include <sys/types.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
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
    TTF_Font* getFont();
    void begin();
    void clear();
    void update();
    void end();
protected:
private:
    Screen(GlobalConfig* config);
    GlobalConfig* _config;
    SDL_Window* _window;
    SDL_Surface* _surface;
    SDL_Renderer* _renderer;
    TTF_Font *_font;
    uint32_t _fps_start_time;
};

#endif
