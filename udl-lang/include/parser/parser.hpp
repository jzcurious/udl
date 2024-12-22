#ifndef _UDL_PARSER_
#define _UDL_PARSER_

#include "astnode.hpp"
#include "scanner/scanner.hpp"
#include "scanner/scantable.hpp"
#include "scanner/token.hpp"

#include <format>
#include <iostream>  // IWYU pragma: export, TODO: remove later

namespace udl {

namespace detail {
template <class T>
concept TidT = std::is_same_v<Tid, T>;
}

using AST = NodePtr;

class Parser final {
 private:
  Scanner& _scanner;
  Token _sym;

  bool _next();

  template <detail::TidT... Ts>
  Tid _accept(Ts... tids);

  template <detail::TidT... Ts>
  Tid _expect(Ts... tids);

  void _parse_expr();
  void _parse_stmt();
  void _parse_decl();
  void _parse_type_decl();
  void _parse_var_or_const_decl();
  void _parse_class_decl();
  void _parse_var_upd();
  void _parse_type_val();
  void _parse_var_or_const_val();
  void _parse_list();
  void _parse_dict();

 public:
  Parser(Scanner& scanner);
  void parse();
};

template <detail::TidT... Ts>
Tid Parser::_accept(Ts... tids) {
  // TODO: maybe accept any or all passed symbols
  Tid tid = Tid::unknown;
  ((_sym.tid == tids ? (tid = tids, true) : false) || ...);
  if (tid) _next();
  return tid;
}

template <detail::TidT... Ts>
Tid Parser::_expect(Ts... tids) {
  Tid tid;
  if ((tid = _accept(tids...))) return tid;

  // TODO: replace to message
  std::cout << std::format("Unexpected symbol \"{}\" at {}:{}\n",
      _sym.val,
      _sym.cursor.nrow,
      _sym.cursor.ncol);

  if constexpr (sizeof...(tids) == 1) {
    std::cout << std::format("  ~~> The expected symbol is a {}", ScanTable[tids]...);
  } else {
    std::cout << "  ~~> One of the following characters was expected:\n";
    ((std::cout << std::format("        {}\n", ScanTable[tids])), ...);
  }

  std::exit(2);
}

}  // namespace udl

#endif  // _UDL_PARSER_
