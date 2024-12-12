#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include <string>

namespace udl {

enum Tid {
  indent,
  space,
  type_kw,
  var_kw,
  ident_type,
  join,
  ident_var,
  assign,
  str_lit,
  num_lit,
  semicolon,
  lbracket,
  rbracket,
  lbrace,
  rbrace,
  langle,
  rangle,
  colon,
  comma,
  newline,
  line_comment,
  block_comment,
  unknown,
};

struct Cursor {
  std::size_t nrow = 0;
  std::size_t ncol = 0;
};

struct Token final {
  Tid tid = Tid::unknown;
  std::string val;
  Cursor cursor;
};

}  // namespace udl

#endif  // _UDL_TOKEN_
