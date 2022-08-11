#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "main.h"
#include "GlobalConfig.h"
#include "Screen.h"
#include "Background.h"
#include "Geometry.h"
#include "ColorKey.h"
#include "Sprite.h"

int main(int argc, char** argv)
{
    GlobalConfig* config = new GlobalConfig();
    Screen* screen = Screen::create(config);
    if(!screen->createSurface())
    {
        return 1;
    }

    Background* background = Background::create(config, screen);
    if(!background->createSurface())
    {
        return 1;
    }

    Geometry* geometry = Geometry::create(config, screen);
    if(!geometry->createSurface())
    {
        return 1;
    }

    ColorKey* colorkey = ColorKey::create(config, screen);
    if(!colorkey->createSurface())
    {
        return 1;
    }

    Sprite* sprite = Sprite::create(config, screen);
    if(!sprite->createSurface())
    {
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
	{
            if( e.type == SDL_QUIT )
	    {
                quit = true;
	    }
	}

	screen->clear();

	background->update();
	geometry->update();
	colorkey->update();
	sprite->update();

	screen->update();
    }

    delete background;
    delete geometry;
    delete colorkey;
    delete sprite;
    delete screen;
    delete config;
    SDL_Quit();
    return 0;
}

#endif
