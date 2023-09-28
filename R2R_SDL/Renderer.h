#include <SDL2/SDL.h>
#include <cstdint>
class Renderer{
    public:
    Renderer();
    ~Renderer();

    void init_renderer();
    void init_renderer( SDL_Window* targetWindow, Uint32 rendererFlags);

    SDL_Renderer* getRenderer();
    void setTarget(SDL_Texture* target);

    void copyTexturetoRenderer(SDL_Texture* Texture);
    void copyTexturetoRenderer(SDL_Texture* Texture, const SDL_Rect srcrect, const SDL_Rect dstrect, const double angle, const SDL_RendererFlip flip);

    private:
    SDL_Renderer* _renderer;


};