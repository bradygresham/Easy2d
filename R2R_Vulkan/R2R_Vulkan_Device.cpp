#include "R2R_Vulkan_Device.h"
#include "../Error.h"
#include "R2R_Extension_Utils.h"
#include "R2R_Layer_Utils.h"
namespace R2R
{
    //Physical Device Methods

    PhysicalDevice::PhysicalDevice(){
        _physicalDevice = NULL;
    }
    PhysicalDevice::PhysicalDevice(const VkInstance &instance)
    {
        _physicalDevice = NULL;
        VkInstance tmpInst = instance;
        init_device(tmpInst);
    }
    PhysicalDevice::~PhysicalDevice()
    {
        
    }

    void PhysicalDevice::init_device(const VkInstance &instance){
        VkResult result = VK_SUCCESS;
        uint32_t deviceCount = 0;

        result = vkEnumeratePhysicalDevices( instance,&deviceCount, (VkPhysicalDevice *)nullptr ); 

        if( result != VK_SUCCESS || deviceCount <= 0 ){
            error("Could not count the physical devices");
        }

        VkPhysicalDevice * physicalDevices = new VkPhysicalDevice[ deviceCount ];
	    result = vkEnumeratePhysicalDevices( instance, &deviceCount, physicalDevices  );
	
        int discreteSelect   = -1;
	    int integratedSelect = -1;

        for( unsigned int i = 0; i < deviceCount; i++ ){
            VkPhysicalDeviceProperties vpdp;
		    vkGetPhysicalDeviceProperties( physicalDevices[i], &vpdp );

            if( vpdp.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ){
			    discreteSelect = i;
            }
		    if( vpdp.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU ){
			    integratedSelect = i;
            }
        }
        int which = -1;
        if( discreteSelect >= 0 )
        {
            which = discreteSelect;
            _physicalDevice = physicalDevices[which];
        }
        else if( integratedSelect >= 0 )
        {
            which = integratedSelect;
            _physicalDevice = physicalDevices[which];
        }
        else
        {
            error("Could not select a physical device");
        }

        delete[] physicalDevices;
    }

    VkPhysicalDevice PhysicalDevice::getDevice(){
        return _physicalDevice;
    }
    //****************************************************************************************************
    //Logical Device Methods
    //****************************************************************************************************
    
    LogicalDevice::LogicalDevice(){
        _logicalDevice = NULL;
    }
    LogicalDevice::~LogicalDevice(){
        vkDestroyDevice(_logicalDevice, nullptr);
    }

    void LogicalDevice::init_device(const VkPhysicalDevice &physicalDevice)
    {
        int numQueuesWanted = 1;

        float queuePriorities[numQueuesWanted] =
        {
            1.
        };

        //create queue create info
        VkDeviceQueueCreateInfo queueCreateInfo[numQueuesWanted];
        queueCreateInfo[0].sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueCreateInfo[0].pNext = nullptr;
        queueCreateInfo[0].flags = 0;
        //find queue family that does graphics
        uint32_t count = -1;
        int queueIndex = -1;
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, nullptr);
        VkQueueFamilyProperties *vqfp = new VkQueueFamilyProperties[count];
        vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &count, vqfp);
        for (unsigned int i = 0; i < count; i++)
        {
            if ((vqfp[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0)
            {
                queueIndex = i;
                break;
            }
        }
        if(queueIndex == -1){
            error("Could not find a queue family that supports graphics");
        }
        queueCreateInfo[0].queueFamilyIndex = queueIndex;

        delete[] vqfp;

        queueCreateInfo[0].queueCount = numQueuesWanted;
        queueCreateInfo[0].pQueuePriorities = queuePriorities; // array of queue priorities [0.,1.]

        //create logical device

       // const char * myDeviceLayers[ ] =
       // {
           // "VK_LAYER_LUNARG_object_tracker",
           // "VK_LAYER_LUNARG_parameter_validation",
        //};

        const char * myDeviceExtensions[ ] =
        {
            "VK_KHR_swapchain",
        };
        //if(!device_check_layer_availability(myDeviceLayers, physicalDevice)){
        //    error("Requested layers not available");
       // }
        if(!device_check_extension_availability(myDeviceExtensions,physicalDevice)){
            error("Requested extensions not available");
        }

	    uint32_t numExtensions = sizeof(myDeviceExtensions) / sizeof(myDeviceExtensions[0]);
	    //uint32_t numLayers = sizeof(myDeviceLayers) / sizeof(myDeviceLayers[0]);

        //device features
        VkPhysicalDeviceFeatures deviceFeatures = {};
        vkGetPhysicalDeviceFeatures( physicalDevice, &deviceFeatures );


        VkDeviceCreateInfo deviceCreateInfo = {};
        deviceCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        deviceCreateInfo.pNext = nullptr;
        deviceCreateInfo.flags = 0;
        deviceCreateInfo.queueCreateInfoCount = numQueuesWanted;
        deviceCreateInfo.pQueueCreateInfos = &queueCreateInfo[0];
        deviceCreateInfo.enabledLayerCount = 0;
        deviceCreateInfo.ppEnabledLayerNames = nullptr;
        deviceCreateInfo.enabledExtensionCount = numExtensions;
        deviceCreateInfo.ppEnabledExtensionNames = myDeviceExtensions;
        deviceCreateInfo.pEnabledFeatures = &deviceFeatures; 

        VkResult result = vkCreateDevice(physicalDevice, &deviceCreateInfo, nullptr, &_logicalDevice);
        if (result != VK_SUCCESS)
        {
            error("Could not create logical device");
        }
    }
} // namespace R2R
