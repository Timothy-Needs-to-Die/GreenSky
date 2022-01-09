#pragma once

//Adds the __declspec(dllexport) to anything in the GreenSky project and __declspec(dllimport) to the application side
#ifdef GS_PLATFORM_WINDOWS
	#ifdef GS_BUILD_DLL
		#define GREENSKY_API __declspec(dllexport)
	#else 
		#define GREENSKY_API __declspec(dllimport)
	#endif
#else
	#error GreenSky Only Supports Windows!
#endif

//Bit shift 1 << 0 = 0, 1 << 1 = 1, 1 << 2 = 4, 1 << 3 = 8, 1 << 4 = 16
#define BIT(x) (1 << x)