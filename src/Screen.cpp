#ifndef __SCREEN_CPP__
#define __SCREEN_CPP__

#include "Screen.h"

Screen::Screen(uint16_t width, uint16_t height)
{
    _width = width;
    _height = height;
}

bool Screen::createSurface()
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        return false;
    }

    _window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN );
    if(!_window)
    {
        return false;
    }

    if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
    {
        return false;
    }

    _screenSurface = SDL_GetWindowSurface( _window );

    return true;
}

SDL_Surface* Screen::getSurface()
{
    return _screenSurface;
}

#endif
