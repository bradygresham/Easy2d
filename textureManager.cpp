#include "textureManager.h"

textureManager::textureManager()
{

}

textureManager::~textureManager()
{
    std::map<const char*, SDL_Texture*>::iterator mit;
    
    for (mit = textureMap.begin(); mit != textureMap.end(); mit++)
    {
        SDL_DestroyTexture(mit->second); 
    }
}

SDL_Texture *textureManager::getTexture(const char *filePath)
{
    //use filePath as key to search for texture
    auto mit = textureMap.find(filePath); 
    //include error checking so we don't set computer on fire
    if (mit == textureMap.end())
    {
        SDL_Texture* newTexture = IMG_LoadTexture(nullptr, filePath);
        if (newTexture == nullptr){
            SDL_DestroyTexture(newTexture);
            return nullptr;
        }
        textureMap.insert(std::make_pair(filePath, newTexture));
        return newTexture;
    }
    //if returns nullptr then we add the filePath to the map with the image stored as the texture
    return mit->second;
}

