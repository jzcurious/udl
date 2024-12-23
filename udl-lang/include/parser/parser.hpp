#ifndef _UDL_PARSER_
#define _UDL_PARSER_

#include "astnode.hpp"
#include "messenger/messenger.hpp"
#include "scanner/scanner.hpp"
#include "scanner/token.hpp"

namespace udl {

using AST = NodePtr;

class Parser final {
 private:
  Scanner& _scanner;
  Token _first_sym;
  Token _follow_sym;

  bool _next();

  template <TidT... Ts>
  Tid _accept(Ts... tids);

  template <TidT... Ts>
  Tid _expect(Ts... tids);

  void _parse_expr();
  void _parse_stmt();
  void _parse_decl();
  void _parse_type_decl();
  void _parse_inst_decl();
  void _parse_class_decl();
  void _parse_var_upd();
  void _parse_type_val();
  void _parse_inst_val();
  void _parse_list();
  void _parse_dict();

 public:
  Parser(Scanner& scanner);
  void parse();
};

template <TidT... Ts>
Tid Parser::_accept(Ts... tids) {
  Tid tid = Tid::unknown;
  ((_follow_sym.tid == tids ? (tid = tids, true) : false) || ...);
  if (tid) _next();
  return tid;
}

template <TidT... Ts>
Tid Parser::_expect(Ts... tids) {
  Tid tid;
  if ((tid = _accept(tids...))) return tid;
  Messenger::unexpected_symbol(_first_sym, _follow_sym, tids...);
  std::exit(2);
}

}  // namespace udl

#endif  // _UDL_PARSER_
