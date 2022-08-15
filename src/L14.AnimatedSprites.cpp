#ifndef __L14_ANIMATEDSPRITES_CPP__
#define __L14_ANIMATEDSPRITES_CPP__

#include "L14.AnimatedSprites.h"

#define IMAGE_PATH GLOBAL_IMAGE_DIR "images/foos.png"

AnimatedSprites::~AnimatedSprites()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

AnimatedSprites::AnimatedSprites(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
    _frame = 0;
}

bool AnimatedSprites::createHWSurface()
{
    SDL_Renderer* renderer = _screen->getRenderer();
    SDL_Surface* loadedSurface = IMG_Load( IMAGE_PATH );

    if(!loadedSurface)
    {
        return false;
    }
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    _texture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    if( !_texture )
    {
        return false;
    }

    _width = loadedSurface->w;
    _height = loadedSurface->h;
    SDL_FreeSurface( loadedSurface );

    createSprites();
    return true;
}

bool AnimatedSprites::createSWSurface()
{
    return true;
}

bool AnimatedSprites::createSprites()
{
    _spriteClips[ 0 ].x = 0;
    _spriteClips[ 0 ].y = 0;
    _spriteClips[ 0 ].w = 64;
    _spriteClips[ 0 ].h = 205;

    //Set top right sprite
    _spriteClips[ 1 ].x = 64;
    _spriteClips[ 1 ].y = 0;
    _spriteClips[ 1 ].w = 64;
    _spriteClips[ 1 ].h = 205;

    //Set bottom left sprite
    _spriteClips[ 2 ].x = 128;
    _spriteClips[ 2 ].y = 0;
    _spriteClips[ 2 ].w = 64;
    _spriteClips[ 2 ].h = 205;

    //Set bottom right sprite
    _spriteClips[ 3 ].x = 192;
    _spriteClips[ 3 ].y = 0;
    _spriteClips[ 3 ].w = 64;
    _spriteClips[ 3 ].h = 205;
    return true;
}

void AnimatedSprites::updateSprite(int x, int y, SDL_Rect* sprite)
{
        SDL_Rect renderQuad = { x, y, sprite->w, sprite->h };
        //SDL_Rect renderQuad = { x, y, _width, _height };
        //renderQuad.w = sprite->w;
        //renderQuad.h = sprite->h;
        SDL_RenderCopy( _screen->getRenderer(), _texture, sprite, &renderQuad );
}

void AnimatedSprites::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        int frame = 16;
        SDL_Rect* currentClip = &_spriteClips[ _frame / (frame / 4) ];
        updateSprite(150, 150, currentClip);
	_frame = (_frame + 1) % frame;
    }
}

#endif
