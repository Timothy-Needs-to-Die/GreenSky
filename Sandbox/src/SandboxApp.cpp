#include <GreenSky.h>

class Sandbox : public GreenSky::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}



};

GreenSky::Application* GreenSky::CreateApplication() {
	return new Sandbox();
}
