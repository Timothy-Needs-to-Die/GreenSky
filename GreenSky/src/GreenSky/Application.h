#pragma once
#include "Core.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace GreenSky {
	class GREENSKY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		bool _running;
	};

	//To be defined in a client
	Application* CreateApplication();
}


