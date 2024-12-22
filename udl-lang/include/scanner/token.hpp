#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include "tid.hpp"

#include <string>

namespace udl {

struct Cursor {
  std::size_t nrow = 0;
  std::size_t ncol = 0;
};

struct Token final {
  Tid tid = Tid::unknown;
  std::string val;
  Cursor cursor;

  // TODO: overload operator<<
};

}  // namespace udl

#endif  // _UDL_TOKEN_
