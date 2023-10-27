#include "Application.h"

#include "Events/Application.h"
#include "Log.h"


namespace OThirteen {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			OT_CORE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			OT_CORE_TRACE(e);
		}
		while (true);
	}
}