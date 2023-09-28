#include "R2R_Extension_Utils.h"
#include "../R2R_Utils/Error.h"
#include <cstring>
#include <vulkan/vulkan.h>

bool instance_check_extension_availability(const char *instanceExtensionsWanted[])
{
    uint32_t numExtensionsWanted = sizeof(instanceExtensionsWanted) / sizeof(char *);

        uint32_t numExtensionsAvailable;
		vkEnumerateInstanceExtensionProperties( (char *)nullptr, &numExtensionsAvailable, (VkExtensionProperties *)nullptr );
		VkExtensionProperties* InstanceExtensions = new VkExtensionProperties[ numExtensionsAvailable ];
		VkResult result = vkEnumerateInstanceExtensionProperties( (char *)nullptr, &numExtensionsAvailable, InstanceExtensions );
		if( result != VK_SUCCESS )
		{
			error("Extensions not init");
		}

		for( uint32_t wanted = 0; wanted < numExtensionsWanted; wanted++ )
		{
            bool is_available = false;
			for( uint32_t available = 0; available < numExtensionsAvailable; available++ )
			{
				if( strcmp( instanceExtensionsWanted[wanted], InstanceExtensions[available].extensionName ) == 0 )
				{
					is_available = true;
					break;
				}
			}
            if(!is_available){
				delete [] InstanceExtensions;
                error("Requested extensions not available");
                return false;
            }
		}

        delete [] InstanceExtensions;
        return true;
}

bool device_check_extension_availability(const char *deviceExtensionsWanted[],const VkPhysicalDevice &physicalDevice)
{
	uint32_t numExtensionsWanted = sizeof(deviceExtensionsWanted) / sizeof(char *);

	uint32_t numExtensionsAvailable;
	vkEnumerateDeviceExtensionProperties( physicalDevice, (char *)nullptr, &numExtensionsAvailable, (VkExtensionProperties *)nullptr );
	VkExtensionProperties* DeviceExtensions = new VkExtensionProperties[ numExtensionsAvailable ];
	VkResult result = vkEnumerateDeviceExtensionProperties( physicalDevice, (char *)nullptr, &numExtensionsAvailable, DeviceExtensions );
	if( result != VK_SUCCESS )
	{
		error("Extensions not init");
	}

	for( uint32_t wanted = 0; wanted < numExtensionsWanted; wanted++ )
	{
		bool is_available = false;
		for( uint32_t available = 0; available < numExtensionsAvailable; available++ )
		{
			if( strcmp( deviceExtensionsWanted[wanted], DeviceExtensions[available].extensionName ) == 0 )
			{
				is_available = true;
				break;
			}
		}
		if(!is_available){
			error("Requested extensions not available");
			delete [] DeviceExtensions;
			return false;
		}
	}

	delete [] DeviceExtensions;
	return true;
}
