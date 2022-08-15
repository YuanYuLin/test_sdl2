#ifndef __L12_COLORMODULATION_H__
#define __L12_COLORMODULATION_H__

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
void setColorsMap(uint8_t num);

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
uint8_t _red;
uint8_t _green;
uint8_t _blue;
uint8_t _alpha;
};

#endif
