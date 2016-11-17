/*
Created by: Armin Hamar
Date:	    22.10.2016
Licence:    GPL
*/
#pragma once
#include "shader.hpp"

//OpenGL shaders:
//Note: keep in mind it returns void the main function

GLuint compile_sh()
{
	GLuint vert_sh;
	GLuint frag_sh;
	GLuint program;

	PB::fs fil,fil2;

	const GLchar * v;
	const GLchar * f;


	//Fragement / Vertex / Shaders / Buffer
	PB::str shv;
	PB::str fhv;

	//Error Buffers / Flags
	GLint frag_error,vert_error;


	//[Load Vertex Shader from File
	fil = PB::file_open("vshader.vert", PB::fsm::read);
	shv = PB::basic_file_read(fil);
	v = shv.c_str();
	//]Load Vertex Shader from File


	//[File Error Handling
	if ((sizeof(f) / sizeof(PB::c8)) == 0)
	{
		std::cerr << "There is no Vertex Shader in the File" << std::endl;
	}
	fclose(fil);
	//]File Error Handling



	//[Load Fragment Shader from File
	fil2 = PB::file_open("fshader.frag", PB::fsm::read);
	fhv = PB::basic_file_read(fil2);
	f = fhv.c_str();
	//]Load Fragment Shader from File

	//[File Error Handling
	if ((sizeof(f)/sizeof(PB::c8)) == 0)
	{
		std::cerr << "There is no Fragment Shader in the File" << std::endl;
	}
	fclose(fil2);
	//]File Error Handling



	//Create and Compile Vertex Shader
	vert_sh = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert_sh, 1,&v, NULL);
	glCompileShader(vert_sh);

	//[Error Handling via Compile Status Vertex Shader
	glGetShaderiv(vert_sh, GL_COMPILE_STATUS, &vert_error);
	if (vert_error == GL_FALSE)
	{
		//INFO: Implemented Shader Log
		PB::i16 loglenght{ 0 };
		glGetShaderiv(vert_sh, GL_INFO_LOG_LENGTH, &loglenght);
		PB::c8* log = new PB::c8[loglenght];
		std::cerr << "Vertex Shader gets not Compiled" << std::endl;
		glGetShaderInfoLog(vert_sh, loglenght, NULL, log);
		std::cerr << log << std::endl;
		free(log);
	}
	//]Error Handling via Compile Status Vertex Shader


	//Create and Compile Fragment Shader
	frag_sh = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag_sh, 1, &f, NULL);
	glCompileShader(frag_sh);
	//]Create and Compile Fragment Shader

	//[Error Handling via Compile Status Fragment Shader
	glGetShaderiv(frag_sh, GL_COMPILE_STATUS, &frag_error);
	if (frag_error == GL_FALSE)
	{
		//INFO: Implemented Shader Log
		PB::i16 loglenght{ 0 };
		glGetShaderiv(frag_sh, GL_INFO_LOG_LENGTH, &loglenght);
		PB::c8* log = new PB::c8[loglenght];
		std::cerr << "Fragment Shader gets not Compiled" << std::endl;
		glGetShaderInfoLog(frag_sh,loglenght, NULL, log);
		std::cerr << log << std::endl;
		free(log);
	}
	//]Error Handling via Compile Status Fragment Shader


	//[Shader Programm Creation
	program = glCreateProgram();
	//]Shader Programm Creation


	//[Attach Simple Shaders to the programm
	glAttachShader(program, vert_sh);
	glAttachShader(program, frag_sh);
	glLinkProgram(program);
	//]Attach Simple Shaders to the programm

	//[Error Handling on Linkage
	GLint lnksh = 0;
	glGetProgramiv(program, GL_LINK_STATUS, &lnksh);
	if(lnksh == GL_FALSE)
	{
		PB::i16 loglenght{ 0 };
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &loglenght);
		PB::c8* log = new PB::c8[loglenght];
		glGetProgramInfoLog(program, loglenght, NULL,log);
	}
	//]Error Handling on Linkage


	//Delete Shaders (Free Memory Space)
	glDeleteShader(vert_sh);
	glDeleteShader(frag_sh);

	//Return to the main function
	return program;
}
