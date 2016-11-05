#pragma once
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>
#include "pb_types.hpp"
#include "pb_opengl.hpp"

namespace PB {
   template<typename T>
   struct Angle
   {
	  T univalue;

	  bl is_rad = false;
	  bl is_degree = false;
   };

   template<typename T>
   Angle<T> make_degree(T deg)
   {
	  Angle<T> f;
	  f.is_degree = true;
	  f.univalue = deg;
	  return f;
   }

   template<typename T>
   Angle<T> make_radiant(T radiants)
   {
	  Angle<T> f;
	  f.is_rad = true;
	  f.univalue = radiants;
	  return f;
   }

   template<typename T>
   Angle<T> to_degree(Angle<T> a)
   {
	  if(a.is_rad)
	  {
		 Angle<T> x;
		 x.univalue = ((360/2*PI)*a);
		 x.is_rad = false;
		 x.is_degree = true;

		 return x;
	  }

	  return a;
   }

   template<typename T>
   Angle<T> to_radiants(Angle<T> a)
   {
	  if(a.is_degree)
	  {
		 Angle<T> x;
		 x.univalue = ((2*PI/360)*a);
		 x.is_rad = true;
		 x.is_degree = false;
		 return x;
	  }
	  return a;
   }

   template<typename T>
   Angle<T> to_radiants(T a)
   {
		 Angle<T> x;
		 x.univalue = ((2*PI/360)*a);
		 x.is_rad = true;
		 x.is_degree = false;
		 return x;
   }

   template<typename T>
   Angle<T> to_degree(T a)
   {
	  Angle<T> x;
	  x.univalue = ((360/2*PI)*a);
	  x.is_rad = false;
	  x.is_degree = true;
	  return x;
   }
}
