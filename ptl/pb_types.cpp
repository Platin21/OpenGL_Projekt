#include "pb_types.hpp"

namespace PB
{
	//Add Types Code Here

}

namespace PA 
{
	namespace global {
		int Error = 0;

		bool error_check()
		{
			if (Error != 0)
			{
				ret false;
			}
			else
			{
				ret true;
			}
		}

		PB::str error_msg()
		{
			PB::str a = "Error" + std::to_string(Error);
			ret a;
		}

		void error_exc()
		{
			if (Error != 0)
			{
				std::exit(Error);
			}	
		}

	}
}