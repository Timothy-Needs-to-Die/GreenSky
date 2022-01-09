#pragma once

#ifdef GS_PLATFORM_WINDOWS

extern GreenSky::Application* GreenSky::CreateApplication();

void main(int argc, char** argv) {
	GreenSky::Log::Init();
	GS_ENGINE_FATAL("Fatal Log!");
	GS_ENGINE_ERROR("Error Log!");
	GS_ENGINE_WARN("Warning Log!");
	GS_ENGINE_INFO("Info Log!");
	GS_ENGINE_TRACE("Trace Log!");
	int a = 5;
	GS_INFO("Hello! Var={0}", a);

	auto app = GreenSky::CreateApplication();
	app->Run();
	delete app;
}
#else
#error GreenSky only Supports Windows!
#endif
