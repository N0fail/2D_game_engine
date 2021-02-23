#define VK_NO_PROTOTYPES
#include "AllHeaders.h"
using namespace VAPI;
int main()
{
	LIBRARY_TYPE vulkan_library;
	ConnectVulkanLoaderLibrary(vulkan_library);
	LoadFunctionExportedFromVulkanLoaderLibrary(vulkan_library);
	LoadGlobalLevelFunctions();
	std::vector<const char*> desired_extensions = {};
	VkInstance instance;
	CreateVkInstanceWithExtentions(instance, desired_extensions, "Vulkan Tutorial");
	LoadInstanceLevelVulkanFunction(instance);
	LoadInstanceLevelVulkanFunctionFromExtentions(instance, desired_extensions);
	std::vector<VkPhysicalDevice> available_devices;
	EnumeratePhysicalDevices(instance, available_devices);
	VkPhysicalDevice physical_device = available_devices[0];
	std::vector<VkExtensionProperties> available_extentions;
	EnumerateExtentionsSupportedByDevice(physical_device, available_extentions);
	for (auto& extension : desired_extensions) {
		if (!IsExtensionSupported(available_extentions, extension)) {
			std::cout << "Extension named '" << extension << "' is not supported by a physical device." << std::endl;
		}
	}
	VkPhysicalDeviceFeatures desired_features;
	VkPhysicalDeviceProperties device_properties;
	vkGetPhysicalDeviceFeatures(physical_device, &desired_features);
	vkGetPhysicalDeviceProperties(physical_device, &device_properties);
	std::vector<VkQueueFamilyProperties> queue_families;
	GetDeviceQueueFamilies(physical_device, queue_families);
	// possible flags : VK_QUEUE_GRAPHICS_BIT, VK_QUEUE_COMPUTE_BIT, VK_QUEUE_TRANSFER_BIT, VK_QUEUE_SPARSE_BINDING_BIT
	VkQueueFlags desired_capabilities = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT;
	uint32_t queue_family_index;
	GetQueueFamilyIndexWIthCapabilities(queue_families, desired_capabilities, queue_family_index);

	return 0;
}