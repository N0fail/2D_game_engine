#ifndef ENUMERATING_PHYSICAL_DEVICES
#define ENUMERATING_PHYSICAL_DEVICES
#include "Common.h"
namespace VAPI {
	bool EnumeratePhysicalDevices(VkInstance, std::vector<VkPhysicalDevice>&);
} // VAPI
#endif // ENUMERATING_PHYSICAL_DEVICES