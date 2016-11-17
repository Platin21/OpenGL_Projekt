#include "pb_stream.hpp"

namespace PB {
   std::ostream& end(std::ostream& os)
   {
	  os << '\n';
	  return os;
   }
}
