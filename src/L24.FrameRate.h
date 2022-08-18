#ifndef __L24_FRAMERATE_H__
#define __L24_FRAMERATE_H__

#include "Base.h"

class FrameRate : public Base
{
public:
 ~FrameRate();
static FrameRate* create(GlobalConfig* config, Screen* screen)
{
    return new FrameRate(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
FrameRate(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
std::string _txt;
SDL_Color _txtColor;
uint32_t _startTime;
void updateString(std::string msg);
int _countFrames;
};

#endif
