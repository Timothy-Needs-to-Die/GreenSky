#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "Core.h"
#include <memory.h>

namespace GreenSky {
	class GREENSKY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetApplicationLogger() { return s_applicationLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_engineLogger;
		static std::shared_ptr<spdlog::logger> s_applicationLogger;
	};
}

//Core Log Macros
#define GS_ENGINE_ERROR(...) ::GreenSky::Log::GetEngineLogger()->error(__VA_ARGS__)
#define GS_ENGINE_FATAL(...) ::GreenSky::Log::GetEngineLogger()->critical(__VA_ARGS__)
#define GS_ENGINE_WARN(...)  ::GreenSky::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define GS_ENGINE_INFO(...)  ::GreenSky::Log::GetEngineLogger()->info(__VA_ARGS__)
#define GS_ENGINE_TRACE(...) ::GreenSky::Log::GetEngineLogger()->trace(__VA_ARGS__)

//Client Log Macros
#define GS_ERROR(...) ::GreenSky::Log::GetApplicationLogger()->error(__VA_ARGS__)
#define GS_FATAL(...) ::GreenSky::Log::GetApplicationLogger()->critical(__VA_ARGS__)
#define GS_WARN(...)  ::GreenSky::Log::GetApplicationLogger()->warn(__VA_ARGS__)
#define GS_INFO(...)  ::GreenSky::Log::GetApplicationLogger()->info(__VA_ARGS__)
#define GS_TRACE(...) ::GreenSky::Log::GetApplicationLogger()->trace(__VA_ARGS__)

