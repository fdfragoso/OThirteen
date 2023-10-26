#pragma once

#ifdef OT_PLATFORM_WINDOWS

extern OThirteen::Application* OThirteen::CreateApplication();

int main(int argc, char** argv)
{
	printf("OThirteen Entry Point");
	auto app = OThirteen::CreateApplication();
	app->Run();
	delete app;
}

#endif