#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

struct WindowInfo{
    const char* title;
    int x;
    int y;
    int w;
    int h;
    Uint32 window_flags;
};

class Window{
    public:
    Window();
    ~Window();

    void init_window_info(
    const char* title,
    int x,
    int y,
    int w,
    int h,
    Uint32 window_flags
    );
    void init_window_info(WindowInfo info);
    void init_window();
    void init_window(WindowInfo info);

    WindowInfo getInfo();
    SDL_Window* getWindow();
    int get_width(){return _windowWidth;}
    int get_height(){return _windowHeight;}
    
    private:
    SDL_Window* _window;
    WindowInfo _info;
    int _windowWidth, _windowHeight;

    
};