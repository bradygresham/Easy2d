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

    void init_instance(); //create info as well as app info
    void init_instance(VkInstanceCreateInfo create, VkApplicationInfo app);
    void init_instance(SDL_Window* window);
    VkInstance* getInstancePtr(); //return pointer to the instance

    bool checkValidationLayerSupport();

    private:
    VkInstance _instance;
    VkInstanceCreateInfo _createInfo;
    VkApplicationInfo _appInfo;
    const char** _sdlExtensions;
    unsigned int _sdlExtensionCount;

    const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
    };
};

}