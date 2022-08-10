#ifndef __BACKGROUND_CPP__
#define __BACKGROUND_CPP__

#include "Background.h"

Background::Background(Screen* screen)
{
    _screen = screen;
}

bool Background::createSurface()
{
    SDL_Surface* screenSurface = _screen->getSurface();
    SDL_Surface* loadedSurface = IMG_Load( _path.c_str() );

    if(!loadedSurface)
    {
        return false;
    }

    //Convert surface to screen format
    _surface = SDL_ConvertSurface( loadedSurface, screenSurface->format, 0 );
    if( !_surface )
    {
        return false;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    return true;
}

#endif
