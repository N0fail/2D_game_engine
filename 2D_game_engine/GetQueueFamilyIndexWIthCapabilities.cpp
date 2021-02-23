#include "GetQueueFamilyIndexWIthCapabilities.h"

namespace VAPI {
	bool GetQueueFamilyIndexWIthCapabilities(std::vector<VkQueueFamilyProperties>& queue_families, VkQueueFlags& desired_capabilities, uint32_t& res_queue_index) {
		for (uint32_t index = 0; index < queue_families.size(); index++)
		{
			if ((queue_families[index].queueCount > 0) && (queue_families[index].queueFlags & desired_capabilities)) {
				res_queue_index = index;
				std::cout << "Queue family with desired capabilities found" << std::endl;
				return true;
			}
		}

		std::cout << "Could not find queue family with desired capabilities" << std::endl;
		return false;
	}
}