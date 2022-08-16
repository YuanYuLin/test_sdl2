#ifndef __L22_TIMING_CPP__
#define __L22_TIMING_CPP__

#include "L22.Timing.h"

Timing::~Timing()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

Timing::Timing(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
    _frame = 0;
    _txt = "Help";
    _txtColor = { 0, 0, 0, 255 };
}

bool Timing::createHWSurface()
{
    SDL_Renderer* renderer = _screen->getRenderer();
    SDL_Surface* loadedSurface = TTF_RenderText_Solid( _screen->getFont(), _txt.c_str(), _txtColor );
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
    _startTime = SDL_GetTicks();
    return true;
}

bool Timing::createSWSurface()
{
    return true;
}

void Timing::updateString(std::string msg)
{
    SDL_Renderer* renderer = _screen->getRenderer();
    SDL_Surface* loadedSurface = TTF_RenderText_Solid( _screen->getFont(), msg.c_str(), _txtColor );
    if(!loadedSurface)
    {
        return ;
    }
    _texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( !_texture )
    {
        return ;
    }
    SDL_FreeSurface( loadedSurface );
}

void Timing::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        SDL_Rect renderQuad = { 100, 300, 500, 50 };
	updateString("Milliseconds since start time: " + std::to_string(SDL_GetTicks() - _startTime));
	SDL_RenderCopy( _screen->getRenderer(), _texture, NULL, &renderQuad );
    }
}
#endif
