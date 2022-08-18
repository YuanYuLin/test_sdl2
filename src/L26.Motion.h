#ifndef __L26_MOTION_H__
#define __L26_MOTION_H__

#include "Base.h"

class Motion : public Base
{
public:
 ~Motion();
static Motion* create(GlobalConfig* config, Screen* screen)
{
    return new Motion(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
Motion(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
int _frame;
};

#endif
