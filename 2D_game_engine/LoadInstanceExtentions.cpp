#include "LoadInstanceExtentions.h"

namespace VAPI {
	bool LoadInstanceExtentions(std::vector<VkExtensionProperties>& available_extensions) {
		uint32_t extensions_count;
		VkResult result = VK_SUCCESS;
		result = vkEnumerateInstanceExtensionProperties(nullptr, &extensions_count, nullptr);
		if ((result != VK_SUCCESS) ||
			(extensions_count == 0)) {
			std::cout << "Could not get the number of Instance extensions." << std::endl;
			return false;
		}
		available_extensions.resize(extensions_count);
		result = vkEnumerateInstanceExtensionProperties(nullptr, &extensions_count, &available_extensions[0]);
		if ((result != VK_SUCCESS) ||
			(extensions_count == 0)) {
			std::cout << "Could not enumerate Instance extensions." << std::endl;
			return false;
		}
		std::cout << "Successfuly enumerated Instance extensions." << std::endl;
		return true;
	}
}