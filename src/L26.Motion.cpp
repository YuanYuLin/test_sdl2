#ifndef __L26_MOTION_CPP__
#define __L26_MOTION_CPP__

#include "L26.Motion.h"

#define IMAGE_PATH GLOBAL_IMAGE_DIR "images/dots.png"

Motion::~Motion()
{
    printf("Destructor %s\n", __func__);

    SDL_DestroyTexture( _texture );
    _texture = NULL;
}

Motion::Motion(GlobalConfig* config, Screen* screen):
        Base(config, screen)
{
    _posX = 0;
    _posY = 0;
    _frame = 0;
}

bool Motion::createHWSurface()
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

bool Motion::createSWSurface()
{
    return true;
}

bool Motion::createSprites()
{
    _spriteClips[ 0 ].x = 0;
    _spriteClips[ 0 ].y = 0;
    _spriteClips[ 0 ].w = 100;
    _spriteClips[ 0 ].h = 100;

    //Set top right sprite
    _spriteClips[ 1 ].x = 100;
    _spriteClips[ 1 ].y = 0;
    _spriteClips[ 1 ].w = 100;
    _spriteClips[ 1 ].h = 100;

    //Set bottom left sprite
    _spriteClips[ 2 ].x = 0;
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

void Motion::updateSprite(int x, int y, SDL_Rect* sprite)
{
        SDL_Rect renderQuad = { x, y, sprite->w, sprite->h };
        //SDL_Rect renderQuad = { x, y, _width, _height };
        //renderQuad.w = sprite->w;
        //renderQuad.h = sprite->h;
        SDL_RenderCopy( _screen->getRenderer(), _texture, sprite, &renderQuad );
}

void Motion::update()
{
    if(_config->use_sw_render)
    {
        //SDL_BlitSurface( _surface, NULL, _screen->getSurface(), NULL );
    }
    else
    {
        int frame = 16;
        SDL_Rect* currentClip = &_spriteClips[ _frame / (frame / 4) ];
        updateSprite(_posX, _posY, currentClip);
	_frame = (_frame + 1) % frame;
    }
}

void Motion::handleEvent(SDL_Event *e)
{
    if( e->type == SDL_KEYDOWN )
    {
        switch( e->key.keysym.sym )
        {
            case SDLK_UP: _posY -= 1; break;
            case SDLK_DOWN: _posY += 1; break;
            case SDLK_LEFT: _posX -= 1; break;
            case SDLK_RIGHT: _posX += 1; break;
        }
    }
}

#endif
