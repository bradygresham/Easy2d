#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <vector>
namespace R2R{

class Instance{
    public:
    Instance();
    Instance (const Instance & inst);
    ~Instance();

    
    std::vector<char *> wanted_and_available_extensions();
    std::vector<char *> wanted_and_available_extensions(const char * instanceExtensionsWanted[ ]); //pass in your own stuff

    //instance initializations
    //*******************
    void init_instance(VkInstanceCreateInfo create, VkApplicationInfo app);
    void init_instance(SDL_Window* window);
    //*******************
    VkInstance* getInstancePtr(); //return pointer to the instance

    bool checkValidationLayerSupport();

    private:
    VkInstance _instance;


    

    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };
};

}