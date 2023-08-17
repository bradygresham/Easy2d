#include "Texture.h"
#include "ResourceManager.h"
#include "Error.h"
Texture::Texture()
{
    _texture = NULL;
}

Texture::~Texture()
{
    SDL_DestroyTexture(_texture);
}

void Texture::setTexture(const char * filePath)
{
    _texture = ResourceManager::getTextureFromCache(filePath);
    if (_texture == NULL)
    {
        errorAndFilePath("Error from Texture.cpp \n Texture not initialized:", filePath);
    }
}

SDL_Texture *Texture::getTexture()
{
    return _texture;
}
