#ifndef CREATING_LOGICAL_DEVICE
#define CREATING_LOGICAL_DEVICE
#include "Common.h"
#include "Tools.h"
namespace VAPI {
	bool CreateLogicalDevice(VkPhysicalDevice& physical_device, 
							std::vector<QueueInfo> queue_infos,
							std::vector<const char*> desired_extensions, 
							VkPhysicalDeviceFeatures& desired_features, 
							VkDevice& logical_device,
							std::vector<VkDeviceQueueCreateInfo>& queue_create_infos);
}

#endif // !CREATING_LOGICAL_DEVICE


