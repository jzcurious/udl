#ifndef _UDL_TOKEN_
#define _UDL_TOKEN_

#include <string>

namespace udl {

enum class Tid {
  ident_var,
  ident_type,
  list_str,
  lit_num,
};

struct Token {
  Tid id;
  std::string val;
};

}  // namespace udl

#endif  // _UDL_TOKEN_
