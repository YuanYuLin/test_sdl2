#ifndef __SCREEN_CPP__
#define __SCREEN_CPP__

#include "Screen.h"

Screen::~Screen()
{
    printf("Destructor %s\n", __func__);
    SDL_FreeSurface( _surface );
    _surface = NULL;

    SDL_DestroyRenderer( _renderer );
    _renderer = NULL;

    SDL_DestroyWindow( _window );
    _window = NULL;
    IMG_Quit();
}

Screen::Screen(GlobalConfig* config)
{
    _config = config;
}

bool Screen::createSurface()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }

    _window = SDL_CreateWindow( _config->title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _config->screen_width, _config->screen_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL );
    if(!_window)
    {
        return false;
    }

    _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
    if(!_renderer)
    {
        return false;
    }
    SDL_SetRenderDrawColor( _renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
    {
        return false;
    }

    _surface = SDL_GetWindowSurface( _window );

    return true;
}

SDL_Surface* Screen::getSurface()
{
    return _surface;
}

SDL_Renderer* Screen::getRenderer()
{
    return _renderer;
}

void Screen::clear()
{
    if(_config->use_sw_render)
    {
    }
    else
    {
        SDL_RenderClear( _renderer );
    }
}

void Screen::update()
{
    if(_config->use_sw_render)
    {
        SDL_UpdateWindowSurface( _window );
    }
    else
    {
        SDL_RenderPresent( _renderer );
    }
}

#endif
