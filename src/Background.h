#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "Screen.h"

class Background
{
public:
static Background* create(Screen* screen)
{
    return new Background(screen);
}

protected:
Background(Screen* screen);
private:
Screen* _screen;
SDL_Surface* _surface;

};

#endif
