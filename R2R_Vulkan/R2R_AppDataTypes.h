#pragma once

#include "../R2R_SDL/Window.h"
#include "../R2R_SDL/Renderer.h"
#include "../R2R_SDL/Camera2D.h"
#include "../R2R_Resource_Management/InputManager.h"

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
};

struct Vulkan_Application{
    //maybe make these arrays??
    Window window;
    R2R::Instance instance;
    R2R::PhysicalDevice physicalDevice;
    R2R::LogicalDevice logicalDevice;
    Camera2D camera2d;
    InputManager inputmanager;
};
//add validation layers
        //add physical and logical devices
        //queues
        //heaps
        //application
        //command pool
        //descriptor pool