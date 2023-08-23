#include "Texture.h"
#include "ResourceManager.h"
#include "Error.h"
#include <iostream>
Texture::Texture()
{
    _texture = NULL;
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}




//this function is not working properly
void Texture::setTexture(SDL_Renderer* renderer, const char * filePath)
{
    _texture = ResourceManager::getTextureFromCache(renderer, filePath);
    if (_texture == NULL)
    {
        std::cout << "\n\nERROR:" << SDL_GetError();
    }
}

SDL_Texture *Texture::getTexture()
{
    return _texture;
}