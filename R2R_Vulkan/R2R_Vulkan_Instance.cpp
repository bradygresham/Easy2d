#include "R2R_Vulkan_Instance.h"
#include "../Error.h"

#include "R2R_Extension_Utils.h"
#include "R2R_Layer_Utils.h"

#include <stdexcept>
#include <vector>
#include <iostream>

namespace R2R{
    Instance::Instance()
    {
        _instance = NULL;
    }

    Instance::Instance(SDL_Window *window)
    {
        _instance = NULL;
        init_instance(window);
    }

    Instance::Instance(const Instance &inst)
    {
        _instance = inst._instance;
    }

    Instance::~Instance()
    {
        if (_instance != nullptr) {
            vkDestroyInstance(_instance, nullptr);
        }
    }

    std::vector<char *> Instance::extensions_wanted_and_available()
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

    

    std::vector<char *> Instance::layers_wanted_and_available()
    {
        std::vector<char *> wanted_and_available;
        const char * instanceLayersWanted[ ] =
		{
			"VK_LAYER_KHRONOS_validation"
		};

        uint32_t numLayersWanted = sizeof(instanceLayersWanted) / sizeof(char *);

        uint32_t numLayersAvailable;
		vkEnumerateInstanceLayerProperties( &numLayersAvailable, (VkLayerProperties *)nullptr  );
		VkLayerProperties* InstanceLayers = new VkLayerProperties[ numLayersAvailable ];
		VkResult result = vkEnumerateInstanceLayerProperties( &numLayersAvailable, InstanceLayers );
		if( result != VK_SUCCESS )
		{
            std::cout << "Result: " << result << "\n";
			error("Extensions not init");
		}
		for( uint32_t wanted = 0; wanted < numLayersWanted; wanted++ )
		{
			for( uint32_t available = 0; available < numLayersAvailable; available++ )
			{
				if( strcmp( instanceLayersWanted[wanted], InstanceLayers[available].layerName ) == 0 )
				{
					wanted_and_available.push_back( InstanceLayers[available].layerName );
					break;
				}
                else{
                    
                }
			}
		}
        return wanted_and_available;
    }

    void Instance::init_instance(SDL_Window* window)
    {
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
        std::vector<char *> extensions = extensions_wanted_and_available();
        _createInfo.enabledExtensionCount = (uint32_t)extensions.size();
        _createInfo.ppEnabledExtensionNames = extensions.data();
        //
        std::vector<char *> layers = layers_wanted_and_available();
        _createInfo.enabledLayerCount = layers.size();
        _createInfo.ppEnabledLayerNames = layers.data();

        
        
        std::cout << "\nENABLED_EXTENSIONS: \n";
        for (uint32_t i = 0; i < _createInfo.enabledExtensionCount; ++i) {
            std::cout << '\t' << _createInfo.ppEnabledExtensionNames[i] << '\n';
        }
        
        //create instance
        
        if (vkCreateInstance(&_createInfo, NULL, &_instance) != VK_SUCCESS){
            error("Failure to create instance");
            throw std::runtime_error("");
        }
        
    }

    void Instance::init_instance(const VkInstanceCreateInfo &create, const VkApplicationInfo &app)
    {
        //create instance
        VkResult result = vkCreateInstance(&create, nullptr, &_instance);
        if (result != VK_SUCCESS){
            error("Failure to create instance");
            throw std::runtime_error("");
        }
    }

    VkInstance Instance::getInstance()
    {
        return _instance;
    }
    
   
}