#ifndef __BASE_CPP__
#define __BASE_CPP__

#include "Base.h"

Base::~Base()
{
}

Base::Base(GlobalConfig* config, Screen* screen)
{
    _config = config;
    _screen = screen;
}

bool Base::createSurface()
{
    bool result = false;
    if(_config->use_sw_render)
    {
        result = createSWSurface();
    }
    else
    {
        result = createHWSurface();
    }
    return result;
}
#endif
