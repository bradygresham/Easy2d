#include "Window.h"
#include "../R2R_Utils/Error.h"
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

void Window::init_window_info(const char *title, int x, int y, int w, int h, Uint32 window_flags)
{
    _info.title = title;
    _info.x = x;
    _info.y = y;
    _info.w = w;
    _info.h = h;
    _info.window_flags = window_flags;
}

void Window::init_window_info(const WindowInfo info)
{
    _info.title = info.title;
    _info.x = info.x;
    _info.y = info.y;
    _info.w = info.w;
    _info.h = info.h;
    _info.window_flags = info.window_flags;
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

void Window::init_window(const WindowInfo info)
{
    if (SDL_WasInit(SDL_INIT_VIDEO) == 0)
    {
        SDL_Init(SDL_INIT_VIDEO);
        if (SDL_WasInit(SDL_INIT_VIDEO) == 0){error("Fatal Error: Cannot initialize SDL Video");}

    }
    _info = info;
    _window = SDL_CreateWindow(_info.title, _info.x, _info.y, _info.w, _info.h, _info.window_flags);
    _windowWidth = _info.w; 
    _windowHeight = _info.h;
    
    if (_window == nullptr){error("Window not created");}
}

WindowInfo Window::getInfo()
{
    return _info;
}

SDL_Window *Window::getWindow()
{
    return _window;
}
