#pragma once

#include "Core.h"

namespace OThirteen {

	class OTHIRTEEN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in client
	Application* CreateApplication();

}



