#pragma once

#ifdef GS_PLATFORM_WINDOWS

extern GreenSky::Application* GreenSky::CreateApplication();

void main(int argc, char** argv) {
	printf("GreenSky Engine\n");
	auto app = GreenSky::CreateApplication();
	app->Run();
	delete app;
}
#else
#error GreenSky only Supports Windows!
#endif
