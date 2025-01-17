#include "parser/parser.hpp"

using namespace udl;

Parser::Parser(Scanner& scanner)
    : _scanner(scanner)
    , _first_sym()
    , _follow_sym() {}

void Parser::parse() {
  _parse_expr();
}

bool Parser::_next() {
  _first_sym = _follow_sym;
  return _scanner >> _follow_sym;
}

void Parser::_parse_expr() {
  _next();
  while (_scanner) {
    _parse_stmt();
    _expect(Tid::semicolon);
  }
}

void Parser::_parse_stmt() {
  if (_accept(Tid::var_id)) {
    _parse_var_upd();
    return;
  }
  _parse_decl();
}

void Parser::_parse_decl() {
  switch (_expect(Tid::type_kw, Tid::var_kw, Tid::const_kw, Tid::struct_kw)) {
    case Tid::var_kw:
    case Tid::const_kw: _parse_inst_decl(); return;
    case Tid::type_kw: _parse_type_decl(); return;
    case Tid::struct_kw: _parse_class_decl(); return;
    default: return;
  }
}

void Parser::_parse_type_decl() {
  _expect(Tid::type_id);
  _expect(Tid::assign);
  _parse_type_val();
}

void Parser::_parse_inst_decl() {
  _parse_type_val();
  _expect(Tid::var_id);
  _expect(Tid::assign);
  _parse_inst_val();
}

void Parser::_parse_var_upd() {
  _expect(Tid::assign);
  _parse_inst_val();
}

void Parser::_parse_type_val() {
  _expect(Tid::type_id);

  if (_accept(Tid::langle)) {
    do {
      _parse_type_val();
    }
    while (_accept(Tid::comma));

    _expect(Tid::rangle);
  }

  while (_accept(Tid::join)) _parse_type_val();
}

void Parser::_parse_inst_val() {
  switch (_expect(Tid::str_lit, Tid::num_lit, Tid::var_id, Tid::lbracket, Tid::lbrace)) {
    case Tid::lbracket: _parse_list(); return;
    case Tid::lbrace: _parse_dict(); return;
    default: return;
  }
}

void Parser::_parse_list() {
  if (_accept(Tid::lbracket)) {
    _parse_list();
  }

  do {
    if (_accept(Tid::rbracket)) return;
    _parse_inst_val();
  }
  while (_accept(Tid::comma));

  _expect(Tid::rbracket);
}

void Parser::_parse_dict() {
  if (_accept(Tid::lbrace)) {
    _parse_dict();
  }

  do {
    if (_accept(Tid::rbrace)) return;
    _parse_inst_val();
    _expect(Tid::colon);
    _parse_inst_val();
  }
  while (_accept(Tid::comma));

  _expect(Tid::rbrace);
}

void Parser::_parse_class_decl() {
  _expect(Tid::type_id);
  _expect(Tid::lbrace);

  do {
    if (_accept(Tid::rbrace)) return;
    _parse_decl();
  }
  while (_accept(Tid::semicolon));

  _expect(Tid::rbrace);
}
