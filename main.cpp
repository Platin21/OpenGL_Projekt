/*
Created by: Armin Hamar
Date:	    22.10.2016
Licence:    GPL
*/
#pragma once;
//[Window Libaray Include + Context Loader
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
//]Window Libaray Include + Context Loader

//[Some Standart Libarrays
#include <math.h>
#include <iostream>
//]Some Standart Libarrays

//[PB Lib includes
#include "ptl/pb_types.hpp"
#include "ptl/pb_file.hpp"
#include "ptl/pb_opengl.hpp"
//]PB Lib includes


//[Own Includes Projekt Internal
#include "shader.hpp"
//]Own Includes Projekt Internal

//[Some defines For Esetetics
#define glPointSize(sz) glPointSize(sz)
//]Some defines For Esetetics


//@NOTE: Disable argv argc warning
#pragma warning(disable: 4100)

//TODO: Do Something whit the Arguments passed to the programm
int main(int argv,char ** argc)
{

	PB::Vector2D<PB::f16> v(0.45f,0.45f);

	//NOTE: Works Fine Probably Allow more ?
	v += { -0.5f , 4.5f };

	std::cout << v << std::endl;

	//NOTE: Only for Testing purepose
/*

	//[TODO: Remove this stuff to PB::window
		GLFWwindow* window;

		if (!glfwInit())
		{
			std::exit(1);
		}
		//[Get Correct Version of OpenGL loaded
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		//]Get Correct Version of OpenGL loaded
		//Create Window
		window = glfwCreateWindow(800, 600, "OpenGL ", NULL, NULL);

		//[Window Creation Error Handling
		if (!window)
		{
			//Terminate GLFW if the window could not be Created
			glfwTerminate();
			std::cerr << "Could not Create Window" << std::endl;
		}
		//]Window Creation Error Handling

		glfwMakeContextCurrent(window);
		//Intitialize Glew wich loads all Extensions
		glewInit();

		//Set The Window Max Swap interval (Framelock act _vsync)
		glfwSwapInterval(1);
	//]TODO: Remove this stuff to PB::window


	//Run Compile_sh which is in shader.hpp defined
	GLuint prog = compile_sh();

	//[State of OpenGL go here
	GLuint vert_array;
	glCreateVertexArrays(1,&vert_array);
	glBindVertexArray(vert_array);
	//]State of OpenGL go here

	//[Constants for OpenGL
   const GLfloat pb_clear[] = { 0.0f,0.0f,0.0f };
	//]Clear Color for OpenGL

	//[Configuration of Opengl Parameters
	  //[Tesselation Config
	  glPatchParameteri(GL_PATCH_VERTICES, 1);
	  //]Tesselation Config

	  //[TODO: Make it Possible to Reset ?
	  glPointSize(40.0f);
	  //]TODO: Make it Possible to Reset ?

	//]Configuration of Opengl Parameters

	while (!glfwWindowShouldClose(window))
	{
		//[ TODO: Create Special Function Inside PB::window
			glClearBufferfv(GL_COLOR, 0, pb_clear);
		//] TODO: Create Special Function Inside PB::window


		float r = -(float)sin(glfwGetTime());
		float g = (float)sin(glfwGetTime());
		float b = -(float)sin(glfwGetTime());
		const GLfloat color[] = { r , g , b , 1.0f };

		//Run the Vertex Shader
		glUseProgram(prog);
		//Attributes
		GLfloat attrib[] =
		{
		   (float)sin(glfwGetTime()) * 0.5f,
		   (float)cos(glfwGetTime()) * 0.6f,
		   0.0f,1.0f
		};

		glVertexAttrib4fv(0, attrib);
		glVertexAttrib4fv(1, color);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		//[ TODO: Create Special Function Inside PB::window
		glfwSwapBuffers(window);
		glfwPollEvents();
		//] TODO: Create Special Function Inside PB::window
	}

	glDeleteVertexArrays(1, &vert_array);
	glDeleteProgram(prog);
	glDeleteVertexArrays(1, &vert_array);

	//[TODO: Move to PB::window
	glfwDestroyWindow(window);
	glfwTerminate();
	//]TODO: Move to PB::window

*/

	ret 0;
}
