#ifndef _UDL_TID_
#define _UDL_TID_

namespace udl {
enum Tid {
  unknown,
  indent,
  space,
  type_kw,
  var_kw,
  const_kw,
  class_kw,
  type_ident,
  join,
  var_ident,
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
  line_comment,
  block_comment,
};
}  // namespace udl

#endif  // _UDL_TID_
