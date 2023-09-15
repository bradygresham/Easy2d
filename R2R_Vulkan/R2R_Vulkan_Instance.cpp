#include "R2R_Vulkan_Instance.h"
#include "../Error.h"
#include <stdexcept>
#include <vector>
#include <iostream>
namespace R2R{
    Instance::Instance()
    {
        _instance = nullptr;
    }

    Instance::Instance(const Instance &inst)
    {
        _instance = inst._instance;
    }

    Instance::~Instance()
    {
        vkDestroyInstance(_instance, nullptr);
    }

    void Instance::init_instance(SDL_Window* window)
    {
        uint32_t _sdlExtensionCount = 0;
        const char ** _sdlExtensions = NULL;
        if (!checkValidationLayerSupport()){
            error("validation layers requested, but not available!\n");
            throw std::runtime_error("");
        }
        if (!SDL_Vulkan_GetInstanceExtensions(window, &_sdlExtensionCount, NULL)){
            error("Could not init vulkan\n");
        }
        else{
            _sdlExtensions = (const char**)malloc(sizeof(const char*) * _sdlExtensionCount);
        }

        if (!SDL_Vulkan_GetInstanceExtensions(window, &_sdlExtensionCount, _sdlExtensions)) {
        // Handle error
        free(_sdlExtensions);
        error("Vulkan not initialized to window");
        }

        //default initialization
        //check that it worked
        
        VkInstanceCreateInfo _createInfo{}; 
        VkApplicationInfo _appInfo{};
        //app info
        _appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        _appInfo.pApplicationName = "R2R_Vulkan App: Application name not initialized";
        _appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        _appInfo.pEngineName = "No Engine";
        _appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        _appInfo.apiVersion = VK_API_VERSION_1_1; // version 1.1 needed for VK_KHR_surface_protected_capabilities extension

        //create info
        _createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        _createInfo.pApplicationInfo = &_appInfo;
        //
        bool enableValidationLayers = true;
        if (enableValidationLayers) {
            _createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
            _createInfo.ppEnabledLayerNames = validationLayers.data();
            } 
        else {
            _createInfo.enabledLayerCount = 0;
            }
        //enable all available extensions
        vkEnumerateInstanceExtensionProperties(NULL, &_sdlExtensionCount,NULL);
        std::vector<VkExtensionProperties> available_extensions(_sdlExtensionCount);
        vkEnumerateInstanceExtensionProperties(NULL, &_sdlExtensionCount, available_extensions.data());
        
        
        //enabling all extensions
        const char* enable[size(available_extensions)];
        
        for (int i = 0; i < size(available_extensions); i++){
            enable[i] = available_extensions[i].extensionName;
        }
        
        _createInfo.enabledExtensionCount = size(available_extensions);
        _createInfo.ppEnabledExtensionNames = enable;

        std::cout << "available extensions:\n";
        for (const auto& extension : available_extensions) {
            std::cout << '\t' << extension.extensionName << '\n';
        }
        
        std::cout << "\nENABLED_EXTENSIONS: \n";
        for (uint32_t i = 0; i < _createInfo.enabledExtensionCount; ++i) {
            std::cout << '\t' << _createInfo.ppEnabledExtensionNames[i] << '\n';
        }
        
        //create instance
        if (vkCreateInstance(&_createInfo, nullptr, &_instance) != VK_SUCCESS){
            error("Failure to create instance");
            throw std::runtime_error("");
        }
        
        //free memory
        free(_sdlExtensions);
    }

    void Instance::init_instance(VkInstanceCreateInfo create, VkApplicationInfo app)
    {
        VkInstanceCreateInfo _createInfo = {};
        VkApplicationInfo _appInfo = {};
        //pass in your own vk info
        _createInfo = create;
        _appInfo = app;

        _createInfo.pApplicationInfo = &_appInfo;
        //create instance
        
        if (vkCreateInstance(&_createInfo, nullptr, &_instance) != VK_SUCCESS){
            error("Failure to create instance");
            throw std::runtime_error("");
        }
    }

    VkInstance *Instance::getInstancePtr()
    {
        return &_instance;
    }
    
    bool Instance::checkValidationLayerSupport()
    {
        uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
    for (const char* layerName : validationLayers) {
        bool layerFound = false;
        for (const auto& layerProperties : availableLayers) {
        if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
        }
    }
    if (!layerFound) {
        return false;
    }
    }
    return true;
    }
}