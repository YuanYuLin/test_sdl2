#ifndef __L14_ANIMATEDSPRITES_H__
#define __L14_ANIMATEDSPRITES_H__

#include "Base.h"

class AnimatedSprites : public Base
{
public:
 ~AnimatedSprites();
static AnimatedSprites* create(GlobalConfig* config, Screen* screen)
{
    return new AnimatedSprites(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
AnimatedSprites(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
int _frame;
};

#endif
