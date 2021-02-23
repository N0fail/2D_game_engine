#include "GetDeviceQueueFamilies.h"

namespace VAPI {
	bool GetDeviceQueueFamilies(VkPhysicalDevice physical_device, std::vector<VkQueueFamilyProperties>& queue_families) {
		uint32_t queue_families_count;
		vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_families_count, nullptr);
		if (queue_families_count <= 0) {
			std::cout << "Could not get device queue families count" << std::endl;
			return false;
		}

		queue_families.resize(queue_families_count);
		vkGetPhysicalDeviceQueueFamilyProperties(physical_device, &queue_families_count, &queue_families[0]);
		if (queue_families_count <= 0) {
			std::cout << "Could not enumerate device queue families" << std::endl;
			return false;
		}

		std::cout << "Successfully enumerated device queue families" << std::endl;
		return true;
	}
}// VAPI