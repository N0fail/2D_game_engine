#include "EnumerateExtentionsSupportedByDevice.h"
namespace VAPI {
	bool EnumerateExtentionsSupportedByDevice(VkPhysicalDevice physical_device, std::vector<VkExtensionProperties>& available_extensions) {
		uint32_t extensions_count = 0;
		VkResult result = VK_SUCCESS;
		result = vkEnumerateDeviceExtensionProperties(physical_device, nullptr, &extensions_count, nullptr);
		if ((result != VK_SUCCESS) ||
			(extensions_count == 0)) {
			std::cout << "Could not get the number of Extentions for physical device" << std::endl;
			return false;
		}
		
		available_extensions.resize(extensions_count);
		result = vkEnumerateDeviceExtensionProperties(physical_device, nullptr, &extensions_count, &available_extensions[0]);
		if ((result != VK_SUCCESS) ||
			(extensions_count == 0)) {
			std::cout << "Could not enumerate device extensions." << std::endl;
			return false;
		}
		std::cout << "Successfully enumerated device extensions." << std::endl;
		return true;
	}
} // VAPI