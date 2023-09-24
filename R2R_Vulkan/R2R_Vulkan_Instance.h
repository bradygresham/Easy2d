#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <vector>
namespace R2R{

class Instance{
    public:
    Instance();
    Instance(SDL_Window *window);
    Instance (const Instance & inst);
    ~Instance();

    
    static std::vector<char *> extensions_wanted_and_available();

    static std::vector<char*> layers_wanted_and_available();
    bool check_layer_availability(const char * instanceLayersWanted[ ]);
    //instance initializations
    //*******************
    void init_instance(const VkInstanceCreateInfo &create, const VkApplicationInfo &app);
    void init_instance(SDL_Window* window);
    //*******************
    VkInstance getInstance(); //return pointer to the instance
    


    private:
    VkInstance _instance;

};

}