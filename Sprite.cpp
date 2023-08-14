#include "Sprite.h"

Sprite::Sprite():
_xCoord(0),
_yCoord(0),
_width(0),
_height(0),
_sourceRect{_xCoord, _yCoord, _width, _height},
_destinationRect{_xCoord, _yCoord, _width, _height} //implement this in all classes later on
{
    
}


Sprite::~Sprite()
{
}

int Sprite::getX()
{
    return _xCoord;
}

int Sprite::getY()
{
    return _yCoord;
}

int Sprite::getW()
{
    return _width;
}

int Sprite::getH()
{
    return _height;
}

SDL_Rect Sprite::getSource()
{
    return _sourceRect;
}

SDL_Rect Sprite::getDestination()
{
    return _destinationRect;
}

void Sprite::setDestination()
{
    _destinationRect.x = _xCoord;
    _destinationRect.y = _yCoord;
    _destinationRect.w = _width;
    _destinationRect.h = _height;
}

SDL_RendererFlip Sprite::getFlip()
{
    return _flip;
}

SDL_Texture *Sprite::getTexture()
{
    return _texture;
}

void Sprite::setTexture()
{
    
}
