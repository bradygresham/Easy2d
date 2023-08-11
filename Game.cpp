#include "Game.h"

Game::Game()
{
    _window = nullptr;
    _renderer = nullptr;
    _texture = nullptr;
    _windowWidth = 1024;
    _windowHeight = 768;
    _gameState = gameState::PLAY;
    _pathToBackgroundImage = "sprite_images/desert_pngs/bg_desert.png";    
}

Game::~Game()
{
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyTexture(_texture);
    SDL_Quit();
}

void Game::run()
{
    init_systems();
    copyTexturetoRenderer(_texture); //delete this argument later this is just for testing purposes
    SDL_RenderPresent(_renderer); //delete this later, it is just for testing purposes
    game_loop();
    
}

void Game::init_systems()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    _window = SDL_CreateWindow("Gunslinger", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _windowWidth, _windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (_window == nullptr){error("Window not created");}
    _renderer = SDL_CreateRenderer(_window, -1, 0); //no need for accelerated rendering
    if (_renderer == nullptr){error("Renderer not created");}

}

void Game::init_systems(SDL_Window* Window, SDL_Renderer* Renderer, const char* title, int x, int y, int w, int h, Uint32 window_flags,  int index, Uint32 rendererFlags)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Window = SDL_CreateWindow(title, x, y, w, h, window_flags);
    if (Window == nullptr){error("Window not created");}
    Renderer = SDL_CreateRenderer(Window, index, rendererFlags); //no need for accelerated rendering
    if (Renderer == nullptr){error("Renderer not created");}

}

void Game::process_input()
{
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        switch (e.type){
            case SDL_QUIT: 
            _gameState = gameState::EXIT; 
            break;
            
        }
    }
}

void Game::game_loop()
{
    while (_gameState == gameState::PLAY){
        process_input();
    }
}

void Game::copyTexturetoRenderer(SDL_Texture* Texture) //create dedicated texture class later
{
    Texture = IMG_LoadTexture(_renderer, _pathToBackgroundImage);
    
    if (SDL_RenderCopy(_renderer, Texture, NULL, NULL) < 0)
    {
        error("Failure to render!");
    }
}


void error(std::string error_message)
{
    std::cout << error_message << std::endl << SDL_GetError() << std::endl;
    std::cout << "Press any key to exit..." << std::endl;
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
}
