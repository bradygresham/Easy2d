#include<SDL2/SDL.h>

class Texture{

    public:
    Texture();
    ~Texture();

    void setTexture(const char* filePath);
    SDL_Texture* getTexture();

    private:
    SDL_Texture* _texture;


};

