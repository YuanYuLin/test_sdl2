#ifndef __L24_FRAMERATE_CPP__
#define __L24_FRAMERATE_CPP__

#include "L24.FrameRate.h"

FrameRate::~FrameRate()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

FrameRate::FrameRate(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
    _countFrames = 0;
    _txt = "  ";
    _txtColor = { 255, 0, 0, 255 };
}

bool FrameRate::createHWSurface()
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

bool FrameRate::createSWSurface()
{
    return true;
}

void FrameRate::updateString(std::string msg)
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

void FrameRate::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        SDL_Rect renderQuad = { 10, 10, 200, 20 };
	float avgFPS = _countFrames / ((SDL_GetTicks() - _startTime) / 1000.0f);
	updateString("FPS: " + std::to_string(avgFPS));
	SDL_RenderCopy( _screen->getRenderer(), _texture, NULL, &renderQuad );
	++_countFrames;
    }
}
#endif
