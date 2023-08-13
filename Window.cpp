#include "Window.h"
#include "Error.h"
Window::Window()
{
    _window = nullptr;
    _windowWidth = 1024;
    _windowHeight = 768;
}

Window::~Window()
{
    SDL_DestroyWindow(_window);
}

void Window::init_window()
{
    if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0){error("Fatal Error: Cannot initialize SDL Video");}

    }
    _window = SDL_CreateWindow("TITLE NOT INITIALIZED", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
    if (_window == nullptr){error("Window not created");}
}

void Window::init_window(const char *title, int x, int y, int w, int h, Uint32 window_flags)
{
    if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0){error("Fatal Error: Cannot initialize SDL Video");}

    }
    _window = SDL_CreateWindow(title, x, y, w, h, window_flags);
    if (_window == nullptr){error("Window not created");}
    else{_windowWidth = w; _windowHeight = h;}
}

SDL_Window* Window::getWindow()
{
    return _window;
}
