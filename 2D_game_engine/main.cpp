#define VK_NO_PROTOTYPES
#include "AllHeaders.h"
using namespace VAPI;
int main()
{
	LIBRARY_TYPE vulkan_library;
	ConnectVulkanLoaderLibrary(vulkan_library);
	LoadFunctionExportedFromVulkanLoaderLibrary(vulkan_library);
	LoadGlobalLevelFunctions();
	std::vector<const char*> desired_extensions = { VK_KHR_SURFACE_EXTENSION_NAME };
	VkInstance instance;
	CreateVkInstanceWithExtentions(instance, desired_extensions, "Vulkan Tutorial");
	LoadInstanceLevelVulkanFunctions(instance);
	LoadInstanceLevelVulkanFunctionsFromExtentions(instance, desired_extensions);
	std::vector<VkPhysicalDevice> available_devices;
	EnumeratePhysicalDevices(instance, available_devices);
	VkPhysicalDevice physical_device = available_devices[0];
	std::vector<VkExtensionProperties> available_extentions;
	std::vector<const char*> desired_device_extensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	EnumerateExtentionsSupportedByDevice(physical_device, available_extentions);
	for (auto& extension : desired_device_extensions) {
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
	// VkQueueFlags desired_capabilities = VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT;
	VkQueueFlags graphics_capabilities = VK_QUEUE_GRAPHICS_BIT;
	VkQueueFlags compute_capabilities = VK_QUEUE_COMPUTE_BIT;
	uint32_t graphics_queue_family_index;
	uint32_t compute_queue_family_index;
	GetQueueFamilyIndexWIthCapabilities(queue_families, graphics_capabilities, graphics_queue_family_index);
	GetQueueFamilyIndexWIthCapabilities(queue_families, compute_capabilities, compute_queue_family_index);
	std::vector<QueueInfo> queue_infos = {
		{graphics_queue_family_index, {1.0f}}
	};
	if (graphics_queue_family_index != compute_queue_family_index){
		queue_infos.push_back({ compute_queue_family_index, { 1.0f } });
	}
	VkDevice logical_device;
	std::vector<VkDeviceQueueCreateInfo> queue_create_infos;
	CreateLogicalDevice(physical_device, queue_infos, desired_device_extensions, desired_features,	logical_device, queue_create_infos);
	LoadDeviceLevelVulkanFunctions(logical_device);
	LoadDeviceLevelVulkanFunctionsFromExtentions(logical_device, desired_device_extensions);
	std::vector<VkQueue> queues;
	GetDeviceQueues(logical_device, queue_create_infos, queues);
	// 241
	return 0;
}