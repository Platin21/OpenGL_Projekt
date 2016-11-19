#include "pb_window.hpp"

namespace PB{

	window::window()
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(880, 800, "", NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(i16 size_y,i16 size_x, str title)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(size_y,size_x,title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(r_i16 size_y,r_i16 size_x,str& title)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(size_y,size_x,title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(str title)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(800,800,title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(str & title)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(800,800,title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(window_discriptor wnd)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(static_cast<int>(wnd.size_x),static_cast<int>(wnd.size_y),wnd.title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	window::window(window_discriptor & wnd)
	{
	   if(single)
	   {
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		  win = glfwCreateWindow(static_cast<int>(wnd.size_x),static_cast<int>(wnd.size_y),wnd.title.c_str(), NULL, NULL);
		  //Set The Window Max Swap interval (Framelock act _vsync)
		  glfwSwapInterval(1);
		  single = false;
	   }
	}

	bool  window::valid()
	{
	  if(!win)
	  {
		 return true;
		 //Terminate GLFW if the window could not be Created
		 glfwTerminate();
		 std::cerr << "Could not Create Window" << '\n';
	  }
	  else
	  {
		 return false;
	  }
	}

	void window::context()
	{
	  glfwMakeContextCurrent(win);
	}

	void  window::clear_color(color<i8> c)
	{
	  glClearColor(c.red,c.green,c.blue,1.0);
	}

	void  window::clear_color(color<f16> c)
	{
	  glClearColor(c.red,c.green,c.blue,1.0);
	}

	void  window::clear_color(color<f32> c)
	{
	  glClearColor(static_cast<float>(c.red),static_cast<float>(c.green),static_cast<float>(c.blue),1.0f);
	}

	void  window::clear_color(GLfloat r,GLfloat g,GLfloat b)
	{
	  glClearColor(r,g,b,1.0);
	}


	void window::clear()
	{
	  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
	}

	//@NOTE: Waht was the Idea behind it ?
	void window::swap()
	{
	  glfwSwapBuffers(win);
	}

	bool window::shouldclose()
	{
	  return !glfwWindowShouldClose(win);
	}

	window::~window()
	{
	  glfwDestroyWindow(win);
	}

	void window::events()
	{
	  glfwPollEvents();
	}
}
