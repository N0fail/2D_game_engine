#include "CreateLogicalDevice.h"

namespace VAPI {
	bool CreateLogicalDevice(VkPhysicalDevice& physical_device,
							std::vector<QueueInfo> queue_infos,
							std::vector<const char*> desired_extensions,
							VkPhysicalDeviceFeatures& desired_features,
							VkDevice& logical_device,
							std::vector<VkDeviceQueueCreateInfo>& queue_create_infos) {

		for (auto& queue_info : queue_infos) {
			queue_create_infos.push_back({
				VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO,
				nullptr,
				0,
				queue_info.family_index,
				queue_info.priorities.size(),
				queue_info.priorities.data()
				});
		}

		VkDeviceCreateInfo device_create_info{
			VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO,
			nullptr,
			0,
			queue_create_infos.size(),
			queue_create_infos.data(),
			0,
			nullptr,
			desired_extensions.size(),
			desired_extensions.size() > 0 ? desired_extensions.data() : nullptr,
			&desired_features
		};

		VkResult result = VK_SUCCESS;
		result = vkCreateDevice(physical_device, &device_create_info, nullptr, &logical_device);
		if ((result != VK_SUCCESS) ||
			(logical_device == VK_NULL_HANDLE) ) {

			std::cout << "Could not create logical device" << std::endl;
			return false;
		}
		std::cout << "Logical device successfully created" << std::endl;
		return true;
	}
}