#include "ReleaseVulkanResources.h"

namespace VAPI {
	void ReleaseVulkanResources(LIBRARY_TYPE& vulkan_library, VkInstance& instance, VkDevice& logical_device) {
		if (logical_device) {
			vkDestroyDevice(logical_device, nullptr);
			logical_device = VK_NULL_HANDLE;
		}
		if (instance) {
			vkDestroyInstance(instance, nullptr);
			instance = VK_NULL_HANDLE;
		}
#if defined _WIN32
		FreeLibrary(vulkan_library);
#elif defined __linux
		dlclose(vulkan_library);
#endif
		vulkan_library = nullptr;
	}
}