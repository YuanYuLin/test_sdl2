#ifndef __GLOBAL_CONFIG_H__
#define __GLOBAL_CONFIG_H__

#include <stdio.h>
#include <stdint.h>
#include <string>

class GlobalConfig
{
public:
    uint16_t screen_width;
    uint16_t screen_height;
    bool use_sw_render;
    uint8_t fps;
    std::string title;
    GlobalConfig();
    ~GlobalConfig();
};
#endif
