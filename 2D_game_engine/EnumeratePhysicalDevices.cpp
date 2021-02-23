#include "EnumeratePhysicalDevices.h"

namespace VAPI {
	bool EnumeratePhysicalDevices(VkInstance instance, std::vector<VkPhysicalDevice>& available_devices) {
		uint32_t devices_count;
		VkResult result = VK_SUCCESS;
		result = vkEnumeratePhysicalDevices(instance, &devices_count, nullptr);
		if ((result != VK_SUCCESS) ||
			(devices_count == 0)) {
			std::cout << "Could not get the number of Instance devices." << std::endl;
			return false;
		}
		available_devices.resize(devices_count);
		result = vkEnumeratePhysicalDevices(instance, &devices_count, &available_devices[0]);
		if ((result != VK_SUCCESS) ||
			(devices_count == 0)) {
			std::cout << "Could not enumerate Instance devices." << std::endl;
			return false;
		}
		std::cout << "Successfuly enumerated Instance devices." << std::endl;
		return true;
	}
}