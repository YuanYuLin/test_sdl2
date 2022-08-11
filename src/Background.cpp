#ifndef __BACKGROUND_CPP__
#define __BACKGROUND_CPP__

#include "Background.h"

#define IMAGE_SW_PATH GLOBAL_IMAGE_DIR "images/background_sw.png"
#define IMAGE_HW_PATH GLOBAL_IMAGE_DIR "images/background_hw.png"

Background::~Background()
{
    printf("Destructor %s\n", __func__);
    SDL_FreeSurface( _surface );
    _surface = NULL;

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

Background::Background(GlobalConfig* config, Screen* screen):
Base(config, screen)
{
}

bool Background::createSWSurface()
{
    SDL_Surface* screenSurface = _screen->getSurface();
    SDL_Surface* loadedSurface = IMG_Load( IMAGE_SW_PATH );

    if(!loadedSurface)
    {
        return false;
    }

    _surface = SDL_ConvertSurface( loadedSurface, screenSurface->format, 0 );
    if( !_surface )
    {
        return false;
    }

    SDL_FreeSurface( loadedSurface );
    return true;
}

bool Background::createHWSurface()
{
    SDL_Renderer* renderer = _screen->getRenderer();
    SDL_Surface* loadedSurface = IMG_Load( IMAGE_HW_PATH );

    if(!loadedSurface)
    {
        return false;
    }
    _texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( !_texture )
    {
        return false;
    }

    SDL_FreeSurface( loadedSurface );
    return true;
}

void Background::update()
{
    if(_config->use_sw_render)
    {
        SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        SDL_RenderCopy( _screen->getRenderer(), _texture, NULL, NULL );
    }
}
#endif
