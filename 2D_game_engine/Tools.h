#ifndef VAPI_TOOLS
#define VAPI_TOOLS
#include "Common.h"
struct QueueInfo {
	uint32_t FamilyIndex;
	std::vector<float> Priorities;
};
#endif // ! VAPI_TOOLS

