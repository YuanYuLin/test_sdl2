#ifndef __SCREEN_CPP__
#define __SCREEN_CPP__

#include "Screen.h"

Screen::~Screen()
{
    printf("Destructor %s\n", __func__);

    TTF_CloseFont( _font );
    _font = NULL;
    TTF_Quit();

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

    _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!_renderer)
    {
        return false;
    }
    SDL_SetRenderDrawColor( _renderer, 0xFF, 0xFF, 0xFF, 0xFF );

    if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) )
    {
        return false;
    }

    if( TTF_Init() < 0)
    {
        return false;
    }
    _font = TTF_OpenFont( "fonts/lazy.ttf", 28 );
    if(!_font)
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

TTF_Font* Screen::getFont()
{
    return _font;
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

void Screen::begin()
{
    _fps_start_time = SDL_GetTicks();
}

void Screen::end()
{
    float screen_tick_per_frame = 1000 / _config->fps;
    uint32_t difftime = SDL_GetTicks() - _fps_start_time;
    if(difftime < screen_tick_per_frame)
    {
        SDL_Delay(screen_tick_per_frame - difftime);
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
