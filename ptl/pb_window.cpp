#include "pb_window.hpp"

namespace PB{

	window::window()
	{
	  win =	glfwCreateWindow(880, 800, "", NULL, NULL);
	}

	window::window(i16 size_y,i16 size_x, str title)
	{
		win = glfwCreateWindow(size_y,size_x,title.c_str(), NULL, NULL);
	}

	window::window(r_i16 size_y,r_i16 size_x,str& title)
	{
		win = glfwCreateWindow(size_y,size_x,title.c_str(), NULL, NULL);
	}

	window::window(str title)
	{
		win = glfwCreateWindow(800,800,title.c_str(), NULL, NULL);
	}

	window::window(str & title)
	{
		 win = glfwCreateWindow(800,800,title.c_str(), NULL, NULL);
	}

	window::window(window_discriptor wnd)
	{
		 win = glfwCreateWindow(static_cast<int>(wnd.size_x),static_cast<int>(wnd.size_y),wnd.title.c_str(), NULL, NULL);
	}

	window::window(window_discriptor & wnd)
	{
		 win = glfwCreateWindow(wnd.size_x,wnd.size_y,wnd.title.c_str(), NULL, NULL);
	}

	void window::clear()
	{
	}

	//@NOTE: Waht was the Idea behind it ?
	void window::swap()
	{
	}

	window::~window()
	{

	}
}
