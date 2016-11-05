#pragma once
#include "pb_types.hpp"

namespace PB {

   static const float PI = 3.14159265359f;

   template<typename T>
   struct Angle;

   template<typename T>
   Angle<T> make_degree(T deg);

   template<typename T>
   Angle<T> make_radiant(T radiants);

   template<typename T>
   Angle<T> to_degree(Angle<T> a);

   template<typename T>
   Angle<T> to_radiants(Angle<T> a);

   template<typename T>
   Angle<T> to_radiants(T a);

   template<typename T>
   Angle<T> to_degree(T a);

}
