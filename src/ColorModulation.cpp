#ifndef __COLORMODULATION_CPP__
#define __COLORMODULATION_CPP__

#include "ColorModulation.h"

#define IMAGE_PATH GLOBAL_IMAGE_DIR "/images/colors.png"

ColorModulation::~ColorModulation()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

ColorModulation::ColorModulation(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
}

bool ColorModulation::createSWSurface()
{
    return true;
}

bool ColorModulation::createHWSurface()
{
    SDL_Renderer* renderer = _screen->getRenderer();
    SDL_Surface* loadedSurface = IMG_Load( IMAGE_PATH );

    if(!loadedSurface)
    {
        return false;
    }
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    _texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( !_texture )
    {
        return false;
    }

    _width = loadedSurface->w;
    _height = loadedSurface->h;
    SDL_FreeSurface( loadedSurface );
    return true;
}

void ColorModulation::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        SDL_Rect renderQuad = { _x, _y, _width, _height };
        SDL_RenderCopy( _screen->getRenderer(), _texture, NULL, &renderQuad );
    }
}

#endif
