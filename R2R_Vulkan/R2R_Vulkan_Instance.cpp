#include "R2R_Vulkan_Instance.h"

namespace R2R{
    Instance::Instance()
    {
        _instance = nullptr;
        _createInfo = {};
        _appInfo = {};
    }

    Instance::Instance(const Instance &inst)
    {
        _instance = inst._instance;
        _createInfo = inst._createInfo;
        _appInfo = inst._appInfo;
    }

    Instance::~Instance()
    {
        vkDestroyInstance(_instance, nullptr);
    }

    void Instance::init_instance()
    {
        //default initialization

        //app info
        _appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        _appInfo.pApplicationName = "R2R_Vulkan App: Application name not initialized";
        _appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        _appInfo.pEngineName = "No Engine";
        _appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        _appInfo.apiVersion = VK_API_VERSION_1_0;

        //create info
        _createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        _createInfo.pApplicationInfo = &_appInfo;

    }

    void Instance::init_instance(VkInstanceCreateInfo create, VkApplicationInfo app)
    {
        //pass in your own vk info
        _createInfo = create;
        _appInfo = app;
    }

    VkInstance *Instance::getInstancePtr()
    {
        return &_instance;
    }
}