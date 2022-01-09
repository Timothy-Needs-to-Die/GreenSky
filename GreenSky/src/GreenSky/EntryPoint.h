#pragma once

#ifdef GS_PLATFORM_WINDOWS

extern GreenSky::Application* GreenSky::CreateApplication();

void main(int argc, char** argv) {
	GreenSky::Log::Init();
	GS_CORE_FATAL("Fatal Log!");
	GS_CORE_ERROR("Error Log!");
	GS_CORE_WARN("Warning Log!");
	GS_CORE_INFO("Info Log!");
	GS_CORE_TRACE("Trace Log!");
	int a = 5;
	GS_INFO("Hello! Var={0}", a);

	auto app = GreenSky::CreateApplication();
	app->Run();
	delete app;
}
#else
#error GreenSky only Supports Windows!
#endif
