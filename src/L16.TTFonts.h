#ifndef __L16_TTFONTS_H__
#define __L16_TTFONTS_H__

#include "Base.h"

class TTFonts : public Base
{
public:
 ~TTFonts();
static TTFonts* create(GlobalConfig* config, Screen* screen)
{
    return new TTFonts(config, screen);
}
virtual void update();

protected:
virtual bool createHWSurface();
virtual bool createSWSurface();
private:
TTFonts(GlobalConfig* config, Screen* screen);
void updateSprite(int x, int y, SDL_Rect* sprite);
bool createSprites();
SDL_Texture* _texture;
int _width;
int _height;
SDL_Rect _spriteClips[4];
int _frame;
std::string _txt;
SDL_Color _txtColor;
};

#endif
