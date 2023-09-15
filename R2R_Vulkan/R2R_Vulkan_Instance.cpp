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

    std::vector<char *> Instance::wanted_and_available_extensions()
    {
        std::vector<char *> wanted_and_available;

        const char * instanceExtensionsWanted[ ] =
		{
			"VK_KHR_surface",
			"VK_EXT_debug_report"
		};

        uint32_t numExtensionsWanted = sizeof(instanceExtensionsWanted) / sizeof(char *);

        uint32_t numExtensionsAvailable;
		vkEnumerateInstanceExtensionProperties( (char *)nullptr, &numExtensionsAvailable, (VkExtensionProperties *)nullptr );
		VkExtensionProperties* InstanceExtensions = new VkExtensionProperties[ numExtensionsAvailable ];
		VkResult result = vkEnumerateInstanceExtensionProperties( (char *)nullptr, &numExtensionsAvailable, InstanceExtensions );
		if( result != VK_SUCCESS )
		{
            std::cout << "Result: " << result << "\n";
			error("Extensions not init");
		}

        wanted_and_available.clear( );
		for( uint32_t wanted = 0; wanted < numExtensionsWanted; wanted++ )
		{
			for( uint32_t available = 0; available < numExtensionsAvailable; available++ )
			{
				if( strcmp( instanceExtensionsWanted[wanted], InstanceExtensions[available].extensionName ) == 0 )
				{
					wanted_and_available.push_back( InstanceExtensions[available].extensionName );
					break;
				}
			}
		}
        return wanted_and_available;
    }

    std::vector<char *> Instance::wanted_and_available_extensions(const char *instanceExtensionsWanted[])
    {
        uint32_t numExtensionsWanted = sizeof(instanceExtensionsWanted) / sizeof(char *);
    }

    void Instance::init_instance(SDL_Window* window)
    {
        if (!checkValidationLayerSupport()){
            error("validation layers requested, but not available!\n");
            throw std::runtime_error("");
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
        std::vector<char *> extensions = wanted_and_available_extensions();
        _createInfo.enabledExtensionCount = (uint32_t)extensions.size();
        _createInfo.ppEnabledExtensionNames = extensions.data();
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