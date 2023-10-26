#pragma once

#ifdef OT_PLATFORM_WINDOWS
	#ifdef OT_BUILD_DLL
		#define OTHIRTEEN_API __declspec(dllexport)
	#else
		#define OTHIRTEEN_API __declspec(dllimport)
	#endif
#else
	#error OThirteen only support Windows!
#endif