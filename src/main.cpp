#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "main.h"
#include "GlobalConfig.h"
#include "Screen.h"
#include "Background.h"
#include "L08.Geometry.h"
#include "L10.ColorKey.h"
#include "L11.Sprite.h"
#include "L12.ColorModulation.h"
#include "L14.AnimatedSprites.h"
#include "L16.TTFonts.h"
#include "L22.Timing.h"
#include "L24.FrameRate.h"
#include "L26.Motion.h"

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

    AnimatedSprites* animatedSprites = AnimatedSprites::create(config, screen);
    if(!animatedSprites->createSurface())
    {
        printf("Error %d\n", __LINE__);
        return 1;
    }

    TTFonts* ttFonts = TTFonts::create(config, screen);
    if(!ttFonts->createSurface())
    {
        printf("Error %d\n", __LINE__);
	return 1;
    }

    Timing* timing = Timing::create(config, screen);
    if(!timing->createSurface())
    {
        printf("Error %d\n", __LINE__);
	return 1;
    }

    FrameRate* frameRate = FrameRate::create(config, screen);
    if(!frameRate->createSurface())
    {
        printf("Error %d\n", __LINE__);
	return 1;
    }

    Motion* motion = Motion::create(config, screen);
    if(!motion->createSurface())
    {
        printf("Error %d\n", __LINE__);
	return 1;
    }

    bool quit = false;
    SDL_Event e;
    while( !quit )
    {
        screen->begin();
        while( SDL_PollEvent( &e ) != 0 )
	{
            if( e.type == SDL_QUIT )
	    {
                quit = true;
	    }
            colormodulation->handleEvent(&e);
	    motion->handleEvent(&e);
	}

	screen->clear();

	background->update();
	geometry->update();
	colorkey->update();
	sprite->update();
        colormodulation->update();
	animatedSprites->update();
	ttFonts->update();
	timing->update();
	frameRate->update();
	motion->update();

	screen->update();
	screen->end();
    }

    delete background;
    delete geometry;
    delete colorkey;
    delete sprite;
    delete colormodulation;
    delete animatedSprites;
    delete ttFonts;
    delete timing;
    delete frameRate;
    delete motion;
    delete screen;
    delete config;
    SDL_Quit();
    return 0;
}

#endif
