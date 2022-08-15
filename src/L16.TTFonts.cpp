#ifndef __L16_TTFONTS_CPP__
#define __L16_TTFONTS_CPP__

#include "L16.TTFonts.h"

TTFonts::~TTFonts()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

TTFonts::TTFonts(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
    _frame = 0;
    _txt = "Help";
    _txtColor = { 0, 0, 0 };
}

bool TTFonts::createHWSurface()
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
    return true;
}

bool TTFonts::createSWSurface()
{
    return true;
}

void TTFonts::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        SDL_Rect renderQuad = { 200, 200, 100, 50 };
	SDL_RenderCopy( _screen->getRenderer(), _texture, NULL, &renderQuad );
    }
}
#endif
