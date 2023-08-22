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

void Texture::setTexture(SDL_Renderer* renderer, const char * filePath)
{
    SDL_SetRenderTarget(renderer, _texture);
    SDL_RenderCopy(renderer, ResourceManager::getTextureFromCache(renderer, filePath), NULL, NULL);
    //_texture = ResourceManager::getTextureFromCache(renderer, filePath);
    if (_texture == NULL)
    {
        //errorAndFilePath("Error from Texture.cpp \nTexture not initialized:", filePath);
    }
}

SDL_Texture *Texture::getTexture()
{
    return _texture;
}
