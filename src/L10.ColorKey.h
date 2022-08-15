#ifndef __L10_COLORKEY_H__
#define __L10_COLORKEY_H__

#include "Base.h"

class ColorKey : public Base
{
public:
 ~ColorKey();
static ColorKey* create(GlobalConfig* config, Screen* screen)
{
    return new ColorKey(config, screen);
} 
virtual void update();

protected:
virtual bool createSWSurface();
virtual bool createHWSurface();
private:
ColorKey(GlobalConfig* config, Screen* screen);
SDL_Texture* _texture;
int _x;
int _y;
int _width;
int _height;
};

#endif
