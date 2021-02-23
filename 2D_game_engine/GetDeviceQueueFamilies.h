#ifndef GETTING_DEVICE_QUEUE_FAMILIES
#define GETTING_DEVICE_QUEUE_FAMILIES
#include "Common.h"
namespace VAPI {
	bool GetDeviceQueueFamilies(VkPhysicalDevice, std::vector<VkQueueFamilyProperties>&);
} // VAPI
#endif // GETTING_DEVICE_QUEUE_FAMILIES