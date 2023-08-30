#include <SDL2/SDL.h>
class Window{
    public:
    Window();
    ~Window();

    void init_window();
    void init_window(const char* title, int x, int y, int w, int h, Uint32 window_flags);

    SDL_Window* getWindow();
    int get_width(){return _windowWidth;}
    int get_height(){return _windowHeight;}
    
    private:
    SDL_Window* _window;
    int _windowWidth, _windowHeight;
};