#pragma once
#include <vulkan/vulkan.h>
namespace R2R{

class Instance{
    public:
    Instance();
    Instance (const Instance & inst);
    ~Instance();

    void init_instance(); //create info as well as app info
    void init_instance(VkInstanceCreateInfo create, VkApplicationInfo app);

    VkInstance* getInstancePtr(); //return pointer to the instance

    private:
    VkInstance _instance;
    VkInstanceCreateInfo _createInfo;
    VkApplicationInfo _appInfo;
};

}