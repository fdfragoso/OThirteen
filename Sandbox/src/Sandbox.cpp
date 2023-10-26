#include <OThirteen.h>

class Sandbox : public OThirteen::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

OThirteen::Application* OThirteen::CreateApplication()
{
	return new Sandbox();
}