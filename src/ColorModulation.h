#ifndef __COLORMODULATION_H__
#define __COLORMODULATION_H__

#include "Base.h"

class ColorModulation : public Base
{
public:
 ~ColorModulation();
static ColorModulation* create(GlobalConfig* config, Screen* screen)
{
    return new ColorModulation(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
ColorModulation(GlobalConfig* config, Screen* screen);
SDL_Texture* _texture;
int _x;
int _y;
int _width;
int _height;
};

#endif
