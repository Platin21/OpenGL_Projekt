#pragma once
#include "pb_types.hpp"

#include <vector>
#include <ostream>

//Special for GL.h
#include <GLEW\glew.h>
#include <GLFW\glfw3.h>

//[Internal Includes
#include <ptl/pb_angle.hpp>
//]Internal Includes

namespace PB {
	template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
	struct color
	{
		T red;
		T blue;
		T green;
	};

	//@INFO: Interface Matrix all Matricys Derive from it
	class Interface_Matrix
	{
	  public:
		  virtual void   x_rotate()		 = 0;
		  virtual void   y_rotate()		 = 0;
		  virtual void   z_rotate()		 = 0;
		  virtual void x_tranform()		 = 0;
		  virtual void y_tranform()		 = 0;
		  virtual void z_tranform()		 = 0;
	};

	//TODO: Implement Interface_Matrix
	template<typename T>
	class Matrix2x2 : Interface_Matrix
	{
		//@INFO: Array Whit 2 times 2 Elements
		T m[2][2];
	};
	//TODO: Implement Interface_Matrix
	template<typename T>
	class Matrix3x3 : Interface_Matrix
	{
	   void x_rotate(T x)
	   {

	   }

	   void y_rotate(T y)
	   {

	   }

	   void z_rotate(T z)
	   {

	   }


		//@INFO: Array Whit 3 times 3 Elements
		T m[3][3];
	};

	//@INFO: Interface for all Vectors
	class Interface_Vector
	{
	   public:
		 virtual PB::i64 distanceToPoint() = 0;
		  //TODO: Add angle to point
	};

	//TODO: Finialize Functions
	template<typename T>
	class Vector2D
	{
	public:
		//[Ctor
		Vector2D()
		{
			this->x = 0;
			this->y = 0;
		}
		Vector2D(T x, T y)
		{
			this->x = x;
			this->y = y;
		}
		Vector2D(T x)
		{
			this->x = x;
		}
		//]Ctor
		//Magnitude	as Simple as it would be
		T mag(Vector2D<T> v)
		{
			ret(this->x*v.y) - (this->y*v.x);
		}
		//NOTE: V is like v[0] = x; v[1] = y;
		T mag(T (&v)[2])
		{
			ret (this->x * v[1]) - (this->y * v[0]);
		}
		//Diffrent Syntax Because of Reference can be a Little bit Faster
		T mag(Vector2D<T> &v)
		{
			ret (this->x * v.y) - (this->y * v.x);
		}
		//[Plus Operators
		//[Plus Equal
		void operator += (Vector2D<T>v)
		{
			this->x = this->x + v.x;
			this->y = this->y + v.y;
		}
		void operator += (T v)
		{
			this->x = this->x + v;
			this->y = this->y + v;
		}
		//]Plus Equal
		Vector2D<T> operator + (Vector2D<T>v)
		{
			Vector2D<T>d(this->x + v.x,this->y + v.y);
			return d;
		}
			//Use Type T Directly
			Vector2D<T> operator + (T v){ Vector2D<T>d(this->x + v, this->y + v); return d; }
			Vector2D<T> operator + (T(v)[2]) { Vector2D<T>d(this->x + v[0], this->y + v[1]); return d; }
		//]Plus Operators
		//[Minus Operator
		void operator -= (Vector2D<T>v)
		{
			this->x = this->x - v.x;
			this->y = this->y - v.y;
		}
		Vector2D<T> operator - (Vector2D<T>v)
		{
			Vector2D<T>d(this->x - v.x, this->y - v.y);
			return d;
		}
			//Use Type T Directly
			Vector2D<T> operator - (T v)
			{
				Vector2D<T>d(this->x - v, this->y - v);
				return d;
			}
			Vector2D<T> operator - (T(v)[2])
		{
			Vector2D<T>d(this->x - v[0], this->y - v[1]);
			return d;
		}
		//]Minus Operator
		//Divide Operator
		void operator /= (Vector2D<T>v)
		{
			if (v.x == 0 || this->x == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			if (v.y == 0 || this->y == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			this->x = this->x / v.x;
			this->y = this->y / v.y;
		}
		Vector2D<T> operator / (Vector2D<T>v)
		{
			if (v.x == 0 || this->x == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			if (v.y == 0 || this->y == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			Vector2D<T>d(this->x / v.x, this->y / v.y);
			return d;
		}
			//Use Type T Directly
			Vector2D<T> operator / (T v)
			{
				if (v == 0 || this->x == 0)
				{
					PA::global::Error = PA::global::Reason::Divide_by_Zero;
					PA::global::error_exc();
				}

				if (this->y == 0)
				{
					PA::global::Error = PA::global::Reason::Divide_by_Zero;
					PA::global::error_exc();
				}

				Vector2D<T>d(this->x / v, this->y / v);
				return d;
			}
			Vector2D<T> operator / (T(v)[2])
		{
			if (v[0] == 0 || this->x == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			if (v[1] == 0 || this->y == 0)
			{
				PA::global::Error = PA::global::Reason::Divide_by_Zero;
				PA::global::error_exc();
			}

			Vector2D<T>d(this->x / v[0], this->y / v[1]);
			return d;
		}
		//Times Operator
		void operator *= (Vector2D<T>v)
		{
			this->x = this->x * v.x;
			this->y = this->y * v.y;
		}
		Vector2D<T> operator * (Vector2D<T>v)
		{
			Vector2D<T>d(this->x * v.x, this->y * v.y);
			return d;
		}
			//Use Type T Directly
			Vector2D<T> operator * (T v)
			{
				Vector2D<T>d(this->x * v, this->y * v);
				return d;
			}
			Vector2D<T> operator * (T(v)[2])
			{
				Vector2D<T>d(this->x * v[0], this->y * v[1]);
				return d;
			}
		//Cout Stream Operator
		friend std::ostream& operator<<(std::ostream& os,const Vector2D& v)
		{
			os << "Vec2(" << v.x << "," << v.y << ")";
			return os;
		}

		//TODO: Add EQUAL or Copy Ctor

		//Matricy transformation
		//TODO: Add Matrix (2x2)
		//Vector2D<T> transform(Matrix2x2<T>& m){ //add some code };

		//Dtor
		~Vector2D() {}
			T x, y;
	};

	template<typename T>
	class Vector3D
	{
		//[Ctor
		Vector3D()
		{
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}
		Vector3D(T x, T y,T z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}
		Vector3D(T x, T y)
		{
			this->x = x;
			this->y = y;
			this->z = 0;
		}
		Vector3D(T x)
		{
			this->x = x;
			this->y = 0;
			this->z = 0;
		}
		//]Ctor

		//[Variuos Operators
			//TODO: Implement thows Operation with T and T[3] and Vector3D<T>
		//]Variuos Operators

		//TODO: Add Matrix(3x3) and Transform

		//[Cross Product
		Vector3D<T> cross(Vector3D<T> v)
		{

		}
		//]Cross Product

		//[Dot Product
		Vector3D<T> dot(Vector3D<T> v)
		{

		}
		//]Dot Product

		T x,y,z;
	};

	//Initilaize Opengl Function Loader + Glfw
	void init();

}
