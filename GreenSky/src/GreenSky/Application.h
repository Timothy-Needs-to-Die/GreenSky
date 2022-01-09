#pragma once
#include "Core.h"

namespace GreenSky {
	class GREENSKY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in a client
	Application* CreateApplication();
}


