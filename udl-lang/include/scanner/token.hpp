#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include <string>

namespace udl {

enum Tid {
  ident_var,
  ident_type,
  list_str,
  lit_num,
  unknown_char,
};

struct Cursor {
  std::size_t nstmt = 0;
  std::size_t nrow = 0;
  std::size_t ncol = 0;
};

struct Token final {
  Tid tid = Tid::unknown_char;
  std::string val = "";
  Cursor cursor;
};

}  // namespace udl

#endif  // _UDL_TOKEN_
