#include "pb_opengl.hpp"


namespace PB {
	void init()
	{
		if (glewInit() != GLEW_OK)
		{
			PA::global::Error = PA::global::Reason::GLEW_Init_Failed;
		};
		if (!glfwInit())
		{
			PA::global::Error = PA::global::Reason::GLFW_Init_Failed;
		};
	}
	
}
