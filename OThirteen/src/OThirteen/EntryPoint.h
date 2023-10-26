#pragma once

#ifdef OT_PLATFORM_WINDOWS

extern OThirteen::Application* OThirteen::CreateApplication();

int main(int argc, char** argv)
{
	printf("OThirteen Entry Point \n \n");

	OThirteen::Log::Init();
	OT_CORE_TRACE("Init log");
	int a = 13;
	OT_CLIENT_INFO("Some message {0}", a);

	auto app = OThirteen::CreateApplication();
	app->Run();
	delete app;
}

#endif