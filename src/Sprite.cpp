#ifndef __SPRITE_CPP__
#define __SPRITE_CPP__

#include "Sprite.h"

#define IMAGE_PATH GLOBAL_IMAGE_DIR "/images/dots.png"

Sprite::~Sprite()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

Sprite::Sprite(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
}

bool Sprite::createHWSurface()
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

bool Sprite::createSWSurface()
{
    return true;
}

bool Sprite::createSprites()
{
    _spriteClips[ 0 ].x =   0;
    _spriteClips[ 0 ].y =   0;
    _spriteClips[ 0 ].w = 100;
    _spriteClips[ 0 ].h = 100;

    //Set top right sprite
    _spriteClips[ 1 ].x = 100;
    _spriteClips[ 1 ].y =   0;
    _spriteClips[ 1 ].w = 100;
    _spriteClips[ 1 ].h = 100;
		
    //Set bottom left sprite
    _spriteClips[ 2 ].x =   0;
    _spriteClips[ 2 ].y = 100;
    _spriteClips[ 2 ].w = 100;
    _spriteClips[ 2 ].h = 100;

    //Set bottom right sprite
    _spriteClips[ 3 ].x = 100;
    _spriteClips[ 3 ].y = 100;
    _spriteClips[ 3 ].w = 100;
    _spriteClips[ 3 ].h = 100;
    return true;
}

void Sprite::updateSprite(int x, int y, SDL_Rect* sprite)
{
        //SDL_Rect renderQuad = { x, y, sprite->w, sprite->h };
        SDL_Rect renderQuad = { x, y, 40, 40 };
	//renderQuad.w = sprite->w;
	//renderQuad.h = sprite->h;
        SDL_RenderCopy( _screen->getRenderer(), _texture, sprite, &renderQuad );
}

void Sprite::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
	updateSprite(50, 0, &_spriteClips[0]);
	updateSprite(500, 0, &_spriteClips[1]);
	updateSprite(0, 500, &_spriteClips[2]);
	updateSprite(500, 500, &_spriteClips[3]);
    }
}

#endif
