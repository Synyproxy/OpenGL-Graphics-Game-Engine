#include <Context/Window.h>
using namespace Graphics;

int main(int argc, char* argv[])
{
	Window window(1080, 720);

	if(window.Setup())
		window.Run();
}