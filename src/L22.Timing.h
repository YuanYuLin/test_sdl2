#ifndef __L22_TIMING_H__
#define __L22_TIMING_H__

#include "Base.h"

class Timing : public Base
{
public:
 ~Timing();
static Timing* create(GlobalConfig* config, Screen* screen)
{
    return new Timing(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
Timing(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
int _frame;
std::string _txt;
SDL_Color _txtColor;
uint32_t _startTime;
void updateString(std::string msg);
};

#endif
