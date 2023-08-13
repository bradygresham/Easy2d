#include "Renderer.h"
#include "Error.h"
#include <SDL2/SDL_image.h>
Renderer::Renderer()
{
    _renderer = nullptr;
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(_renderer);
}

void Renderer::init_renderer()
{
    _renderer = SDL_CreateRenderer(NULL, -1, 0);  //need to make rendererclass
    if (_renderer == nullptr){error("Renderer not created");}
}

void Renderer::init_renderer(SDL_Window *targetWindow, Uint32 rendererFlags)
{
    _renderer = SDL_CreateRenderer(targetWindow, -1, rendererFlags);  //need to make rendererclass
    if (_renderer == nullptr){error("Renderer not created");}
}

SDL_Renderer *Renderer::getRenderer()
{
    return _renderer;
}

void Renderer::copyTexturetoRenderer(SDL_Texture *Texture)
{
    if (SDL_RenderCopy(_renderer, Texture, NULL, NULL) < 0)
    {
        error("Failure to render!");
    }
}

void Renderer::copyTexturetoRenderer(SDL_Texture *Texture, const SDL_Rect srcrect, const SDL_Rect dstrect, const double angle, const SDL_RendererFlip flip) // create dedicated texture class later
{
    /*SDL_RenderCopyEx(SDL_Renderer * renderer,
                   SDL_Texture * texture,
                   const SDL_Rect * srcrect,
                   const SDL_Rect * dstrect,
                   const double angle,
                   const SDL_Point *center,
                   const SDL_RendererFlip flip);*/
    if (SDL_RenderCopyEx(_renderer, Texture, &srcrect, &dstrect, angle, NULL, flip) < 0)
    {
        error("Failure to render!");
    }
}

void Renderer::setTarget(SDL_Texture* target)
{
    SDL_SetRenderTarget(_renderer, target);
}
