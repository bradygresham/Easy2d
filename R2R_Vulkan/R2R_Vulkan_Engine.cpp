#include "R2R_Vulkan_Engine.h"
#include "R2R_Layer_Utils.h"
#include "R2R_Extension_Utils.h"
#include "../Error.h"
R2R::R2R_Vulkan_Engine::R2R_Vulkan_Engine():
_app{
    Window{},
    R2R::Instance{},
    R2R::PhysicalDevice{},
    R2R::LogicalDevice{},
    Camera2D{},
    InputManager{}
}

{
}


R2R::R2R_Vulkan_Engine::R2R_Vulkan_Engine(const R2R_Vulkan_Engine &app)
{
}

R2R::R2R_Vulkan_Engine::~R2R_Vulkan_Engine()
{
}



void R2R::R2R_Vulkan_Engine::init_systems()
{
    //initialize info for creation
    //init window info
	_init.winfo.title = "Hello Vulkan!";
	_init.winfo.x = SDL_WINDOWPOS_CENTERED;
	_init.winfo.y = SDL_WINDOWPOS_CENTERED;
	_init.winfo.w = 1024;
	_init.winfo.h = 768;
	_init.winfo.window_flags = (SDL_WindowFlags)SDL_WINDOW_VULKAN;

	//init application info
	_init.app.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	_init.app.pNext = NULL;
	_init.app.pApplicationName = "Hello Vulkan";
	_init.app.applicationVersion = VK_MAKE_VERSION(1,0,0);
	_init.app.pEngineName = "Ready2Render";
	_init.app.engineVersion = VK_MAKE_VERSION(1,0,0);
	_init.app.apiVersion = VK_API_VERSION_1_1;
	
	//init creation info
	const char * instanceExtensionsWanted[ ] =
	{
		"VK_KHR_surface",
		"VK_EXT_debug_report"
	};

	const char * instanceLayersWanted[ ] =
	{
		"VK_LAYER_KHRONOS_validation"
	};
    
	if(!instance_check_extension_availability(instanceExtensionsWanted)){
		error("Requested extensions not available");
	}
	if(!instance_check_layer_availability(instanceLayersWanted)){
		error("Requested layers not available");
	}

	uint32_t numExtensions = sizeof(instanceExtensionsWanted) / sizeof(instanceExtensionsWanted[0]);
	uint32_t numLayers = sizeof(instanceLayersWanted) / sizeof(instanceLayersWanted[0]);

	_init.create.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	_init.create.pNext = NULL;
    _init.create.flags = 0;
	_init.create.pApplicationInfo = &_init.app;
	_init.create.enabledLayerCount = numLayers;
    _init.create.ppEnabledLayerNames = instanceLayersWanted;
    _init.create.enabledExtensionCount = numExtensions;
    _init.create.ppEnabledExtensionNames = instanceExtensionsWanted;
    
    _app.window.init_window(_init.winfo);
    _app.instance.init_instance(_init.create,_init.app);
    _app.physicalDevice.init_device(_app.instance.getInstance());
    //put logical device here
    _app.camera2d.init_camera(_app.window.get_width(),_app.window.get_height());
    //putinput manager here

}
