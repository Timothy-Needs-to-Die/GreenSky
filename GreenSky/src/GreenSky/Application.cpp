#include "gspch.h"
#include "Application.h"

#include "Log.h"

#include "GreenSky/Events/Event.h"
#include "GreenSky/Events/ApplicationEvent.h"
#include "GreenSky/Events/MouseEvent.h"

#include "GLFW/glfw3.h"
#include "GL/GL.h"

namespace GreenSky {

	//#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	GreenSky::Application::Application() : _running(true)
	{
		GLFWwindow* window = glfwCreateWindow(1280, 720, "Demo", nullptr, nullptr);
		glfwMakeContextCurrent(window);
		//glfwSetWindowUserPointer(window)

	}

	GreenSky::Application::~Application()
	{

	}

	void Application::Run()
	{
		//-- Event Tests --
		WindowResizeEvent e(1280, 720);
		MouseButtonPressedEvent e2(0);

		if (e.IsInCategory(EventCategoryApplication))
		{
			//Outputs the event information
			GS_TRACE(e);
		}
		if (e2.IsInCategory(EventCategoryInput))
		{
			//Outputs the event information
			GS_TRACE(e2);
		}
		//-- End Event Tests --

		//Game Loop
		while(_running) {
		}
	}
}