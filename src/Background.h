#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "Base.h"

class Background : public Base
{
public:
~Background();
static Background* create(GlobalConfig* config, Screen* screen)
{
    return new Background(config, screen);
}
virtual void update();

protected:
virtual bool createSWSurface();
virtual bool createHWSurface();
private:
Background(GlobalConfig* config, Screen* screen);
SDL_Surface* _surface;
SDL_Texture* _texture;

};

#endif
