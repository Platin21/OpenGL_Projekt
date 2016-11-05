#pragma once
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

//Special Defines
#define	ret return

//Build namespace
namespace PB
{
	typedef std::string str;

	//Int Datatypes
	typedef char	   i4;
	typedef short	   i8;
	typedef int       i16;
	typedef long      i32;
	typedef long long i64;

	//Special Integer Values
	//Reference
	typedef char&      r_i4;
	typedef short&     r_i8;
	typedef int&       r_i16;
	typedef long&      r_i32;
	typedef long long& r_i64;
	//Pointer


	//Charackter Datatypes
	typedef char       c8;
	typedef char16_t  c16;
	typedef char32_t  c32;

	//Floating Point Values
	typedef float f16;
	typedef double f32;
	typedef long double f64;

	//File System Stuff
	typedef	FILE* fs;

	//Boolean Value
	typedef bool bl;
	//Enums for Diffrent Things

	//Structs for Diffrent Things
	 // Maybe add some things to this Section?
}

//Alpha Namespace
namespace PA
{
	//Globals
	namespace global {
		//[Error Section

		//Error Code Int
		extern int Error;

		//Error Reasons
		enum Reason
		{
			GLFW_Init_Failed,
			GLEW_Init_Failed,
			Vertex_Shader_Compile_Failed,
			Fragment_Shader_Compile_Failed,
			Geometrie_Shader_Compile_Failed,
			Tesselation_Shader_Compile_Failed,
			Vector_Size_to_big,
			Vector_is_Not_Vec3,
			Vector_is_Not_Vec4,
			Vector_is_Not_Vec2,
			Vector_is_Not_Vec1,
			Divide_by_Zero,
			File_Does_Not_Exist,
			//NOTE: Add more Errors to the Enum
		};

		//Simple Error Checker
		bool error_check();

		//Show Error Msg
		PB::str error_msg();

		//If Error KIll Programm
		void error_exc();

		//]Error Section
	}
}
