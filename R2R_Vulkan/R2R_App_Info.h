#include "../Window.h"
#include "R2R_Vulkan_Instance.h"
#include "R2R_Vulkan_Device.h"
#include <vulkan/vulkan.h>

#define MAX_EXTENSIONS_SIZE 256
#define MAX_LAYER_SIZE 256

struct ExtensionsAndLayers{
    const char * instancExtensionsWanted[MAX_EXTENSIONS_SIZE]; //change sizes later
    const char * instanceLayersWanted[MAX_LAYER_SIZE];

    const char * deviceExtensionsWanted[MAX_EXTENSIONS_SIZE];
    const char * deviceLayersWanted[MAX_LAYER_SIZE];
};

struct InitInfo{
    WindowInfo winfo;
    VkInstanceCreateInfo create;
    VkApplicationInfo app;
    ExtensionsAndLayers eal;
};

struct Vulkan_Application{
    //maybe make these arrays??
    R2R::Instance instance;
    R2R::PhysicalDevice physicalDevice;
    R2R::LogicalDevice logicalDevice;

    Window _window;

};
//add validation layers
        //add physical and logical devices
        //queues
        //heaps
        //application
        //command pool
        //descriptor pool