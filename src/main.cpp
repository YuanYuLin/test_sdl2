#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "main.h"
#include "GlobalConfig.h"
#include "Screen.h"
#include "Background.h"
#include "Geometry.h"
#include "ColorKey.h"
#include "Sprite.h"
#include "ColorModulation.h"

int main(int argc, char** argv)
{
    GlobalConfig* config = new GlobalConfig();
    Screen* screen = Screen::create(config);
    if(!screen->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    Background* background = Background::create(config, screen);
    if(!background->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    Geometry* geometry = Geometry::create(config, screen);
    if(!geometry->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    ColorKey* colorkey = ColorKey::create(config, screen);
    if(!colorkey->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    Sprite* sprite = Sprite::create(config, screen);
    if(!sprite->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    ColorModulation* colormodulation = ColorModulation::create(config, screen);
    if(!colormodulation->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    bool quit = false;
    SDL_Event e;
    uint8_t colors = 0xFF;
    while( !quit )
    {
        colors = 0x00;
        while( SDL_PollEvent( &e ) != 0 )
	{
            if( e.type == SDL_QUIT )
	    {
                quit = true;
	    }
            else if(e.type == SDL_KEYDOWN)
            {
                switch( e.key.keysym.sym )
                {
                case SDLK_q:
                    colors |= (1 << 0);
                break;
                case SDLK_w:
                    colors |= (1 << 1);
                break;
                case SDLK_e:
                    colors |= (1 << 2);
                break;
                case SDLK_a:
                    colors |= (1 << 4);
                break;
                case SDLK_s:
                    colors |= (1 << 5);
                break;
                case SDLK_d:
                    colors |= (1 << 6);
                break;
                default:
                break;
                }
            }
	}

	screen->clear();

	background->update();
	geometry->update();
	colorkey->update();
	sprite->update();
        colormodulation->setColorsMap(colors);
        colormodulation->update();

	screen->update();
    }

    delete background;
    delete geometry;
    delete colorkey;
    delete sprite;
    delete colormodulation;
    delete screen;
    delete config;
    SDL_Quit();
    return 0;
}

#endif
