#pragma once
#include <vulkan/vulkan.h>
extern bool instance_check_extension_availability(const char * instanceExtensionsWanted[ ]);
extern bool device_check_extension_availability(const char * deviceExtensionsWanted[ ], const VkPhysicalDevice &physicalDevice);