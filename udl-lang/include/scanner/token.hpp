#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include <string>

namespace udl {

enum Tid {
  semicolon,
  ident_var,
  ident_type,
  list_str,
  lit_num,
  unknown,
};

struct Cursor {
  std::size_t nrow = 0;
  std::size_t ncol = 0;
};

struct Token final {
  Tid tid = Tid::unknown;
  std::string val = "";
  Cursor cursor;
};

}  // namespace udl

#endif  // _UDL_TOKEN_
