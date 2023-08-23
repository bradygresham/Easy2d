#include<SDL2/SDL.h>

class Texture{

    public:
    Texture();
    ~Texture();

    void setTexture(SDL_Renderer* renderer, const char* filePath);
    SDL_Texture* getTexture();
    void outputTextureAddress();
    private:
    SDL_Texture* _texture;


};

