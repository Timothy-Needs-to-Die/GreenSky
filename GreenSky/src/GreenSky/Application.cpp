#include "Application.h"

#include "Log.h"

#include "GreenSky/Events/ApplicationEvent.h"
#include "GreenSky/Events/MouseEvent.h"

namespace GreenSky {
	GreenSky::Application::Application()
	{

	}

	GreenSky::Application::~Application()
	{

	}

	void Application::Run()
	{
		while(true) {
			WindowResizeEvent e(1280, 720);
			MouseButtonPressedEvent e2(0);

			if (e.IsInCategory(EventCategoryApplication))
			{
				GS_TRACE(e);
			}
			if (e2.IsInCategory(EventCategoryInput))
			{
				GS_TRACE(e2);
			}
		}
	}

}


