#pragma once

#ifdef GS_PLATFORM_WINDOWS
	#ifdef GS_BUILD_DLL
		#define GREENSKY_API __declspec(dllexport)
	#else 
		#define GREENSKY_API __declspec(dllimport)
	#endif
#else
	#error GreenSky Only Supports Windows!
#endif

#define BIT(x) (1 << x)