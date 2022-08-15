#ifndef __L08_GEOMETRY_CPP__
#define __L08_GEOMETRY_CPP__

#include "L08.Geometry.h"

Geometry::~Geometry()
{
    printf("Destructor %s\n", __func__);
}

Geometry::Geometry(GlobalConfig* config, Screen* screen):
	Base(config, screen)
{
}

bool Geometry::createSWSurface()
{
    return true;
}
bool Geometry::createHWSurface()
{
    return true;
}

void Geometry::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
				//Render red filled quad
        SDL_Rect fillRect = { _config->screen_width / 4, _config->screen_height / 4, _config->screen_width / 2, _config->screen_height / 2 };
        SDL_SetRenderDrawColor( _screen->getRenderer(), 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderFillRect( _screen->getRenderer(), &fillRect );

        //Render green outlined quad
        SDL_Rect outlineRect = { _config->screen_width / 6, _config->screen_height / 6, _config->screen_width * 2 / 3, _config->screen_height * 2 / 3 };
        SDL_SetRenderDrawColor( _screen->getRenderer(), 0x00, 0xFF, 0x00, 0xFF );		
        SDL_RenderDrawRect( _screen->getRenderer(), &outlineRect );
				
        //Draw blue horizontal line
        SDL_SetRenderDrawColor( _screen->getRenderer(), 0x00, 0x00, 0xFF, 0xFF );		
        SDL_RenderDrawLine( _screen->getRenderer(), 0, _config->screen_height / 2, _config->screen_width, _config->screen_height / 2 );

        //Draw vertical line of yellow dots
        SDL_SetRenderDrawColor( _screen->getRenderer(), 0xFF, 0xFF, 0x00, 0xFF );
        for( int i = 0; i < _config->screen_height; i += 4 )
        {
            SDL_RenderDrawPoint( _screen->getRenderer(), _config->screen_width / 2, i );
        }
    }
}

#endif
