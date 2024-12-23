#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include "tid.hpp"

#include <format>
#include <string>
#include <string_view>

namespace udl {

struct Cursor {
  std::string_view fname;
  std::size_t nrow;
  std::size_t ncol;

  std::string path() const {
    return std::format("{}:{}:{}", fname, nrow, ncol);
  }
};

struct Token final {
  Tid tid = Tid::unknown;
  std::string val;
  Cursor cursor;
};

template <class T>
concept TidT = std::is_same_v<Tid, T>;

}  // namespace udl

#endif  // _UDL_TOKEN_
