#pragma once

#include "spdlog/spdlog.h"
#include "Core.h"
#include <memory.h>

namespace GreenSky {
	class GREENSKY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

//Core Log Macros
#define GS_CORE_ERROR(...) ::GreenSky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GS_CORE_FATAL(...) ::GreenSky::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define GS_CORE_WARN(...)  ::GreenSky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GS_CORE_INFO(...)  ::GreenSky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GS_CORE_TRACE(...) ::GreenSky::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client Log Macros
#define GS_ERROR(...) ::GreenSky::Log::GetClientLogger()->error(__VA_ARGS__)
#define GS_FATAL(...) ::GreenSky::Log::GetClientLogger()->critical(__VA_ARGS__)
#define GS_WARN(...)  ::GreenSky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GS_INFO(...)  ::GreenSky::Log::GetClientLogger()->info(__VA_ARGS__)
#define GS_TRACE(...) ::GreenSky::Log::GetClientLogger()->trace(__VA_ARGS__)

