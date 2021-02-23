#ifndef ENUMERATING_EXTENTIONS_SUPPORTED_BY_DEVICE
#define ENUMERATING_EXTENTIONS_SUPPORTED_BY_DEVICE
#include "Common.h"
namespace VAPI {
	bool EnumerateExtentionsSupportedByDevice(VkPhysicalDevice, std::vector<VkExtensionProperties>&);
} // VAPI
#endif // ENUMERATING_EXTENTIONS_SUPPORTED_BY_DEVICE