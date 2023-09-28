#include "Sprite.h"

Sprite::Sprite():
_xCoord(0),
_yCoord(0),
_width(0),
_height(0),
_sourceRect{_xCoord, _yCoord, _width, _height},
_destinationRect{_xCoord, _yCoord, _width, _height}
//init the texture here too
{
}

Sprite::~Sprite()
{
}

void Sprite::setDestination()
{
    _destinationRect.x = _xCoord; //where it's being drawn to
    _destinationRect.y = _yCoord;
    _destinationRect.w = _width;
    _destinationRect.h = _height;
}


SDL_Texture *Sprite::getTexture()
{
    return _texture.getTexture();
}

void Sprite::setTexture(SDL_Renderer * renderer, const char* filePath)
{
    _texture.setTexture(renderer,filePath);
}
