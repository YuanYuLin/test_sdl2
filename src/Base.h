#ifndef __BASE_H__
#define __BASE_H__

#include "GlobalConfig.h"
#include "Screen.h"

class Base
{
public:
~Base();
Base(GlobalConfig* config, Screen* screen);
bool createSurface();
virtual void update() = 0;

protected:
virtual bool createHWSurface() = 0;  
virtual bool createSWSurface() = 0;  
GlobalConfig* _config;
Screen* _screen;
private:
};
#endif
