#ifndef __GLOBALCONFIG_CPP__
#define __GLOBALCONFIG_CPP__

#include "GlobalConfig.h"

GlobalConfig::~GlobalConfig()
{
    printf("Destructor %s\n", __func__);
}

GlobalConfig::GlobalConfig()
{
    screen_width = 1280;
    screen_height = 720;
    use_sw_render = false;
    title = "TEST GAME";
}

#endif
