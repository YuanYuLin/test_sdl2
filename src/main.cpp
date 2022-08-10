#ifndef __MAIN_CPP__
#define __MAIN_CPP__

#include "main.h"
#include "Screen.h"

int main(int argc, char** argv)
{
    Screen* screen = Screen::create();

    if(!screen->createScreenSurface())
    {
        return 1;
    }


    return 0;
}

#endif
