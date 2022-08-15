#ifndef __L11_SPRITE_H__
#define __L11_SPRITE_H__

#include "Base.h"

class Sprite : public Base
{
public:
 ~Sprite();
static Sprite* create(GlobalConfig* config, Screen* screen)
{
    return new Sprite(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
Sprite(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
};

#endif
