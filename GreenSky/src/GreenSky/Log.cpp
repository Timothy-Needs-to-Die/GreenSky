#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

//Documentation for spdlog library: https://github.com/gabime/spdlog/wiki
namespace GreenSky {

	std::shared_ptr<spdlog::logger> Log::s_engineLogger;
	std::shared_ptr<spdlog::logger> Log::s_applicationLogger;

	void Log::Init()
	{
		//Pattern expands to: [Timestamp] Name of Logger: Message
		//E.g [15:32:10] GreenSky: Initialized Renderer
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_engineLogger = spdlog::stdout_color_mt("GreenSky");
		s_engineLogger->set_level(spdlog::level::trace);

		s_applicationLogger = spdlog::stdout_color_mt("Application");
		s_applicationLogger->set_level(spdlog::level::trace);
	}
}

