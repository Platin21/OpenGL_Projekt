#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "pb_types.hpp"
#include "pb_opengl.hpp"

namespace PB {

	struct window_discriptor
	{
		str title;
		i64 size_x;
		i64 size_y;
	};

	class window
	{
	public:
		window();
		window(int size_y,int size_x,str title);
		window(int& size_y, int& size_x, str& title);
		window(str title);
		window(str &title);
		window(window_discriptor wnd);
		window(window_discriptor &wnd);
		bool shouldclose();

		//@NOTE: Clearing Functions sets the clear Color of the Window
		void clear_color(color<i8> c);
		void clear_color(color<f16> c);
		void clear_color(color<f32> c);

		void clear_color(GLfloat r,GLfloat g,GLfloat b);
		void clear();
		void swap();
		bool valid();
		void context();
		void events();
		~window();
	private:
		GLFWwindow *win;
		bool single = true;
	};
}
