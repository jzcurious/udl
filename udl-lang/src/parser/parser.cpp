#include "parser/parser.hpp"

using namespace udl;

Parser::Parser(Scanner& scanner)
    : _scanner(scanner)
    , _sym() {}

void Parser::parse() {
  _parse_expr();
}

bool Parser::_next() {
  return _scanner >> _sym;
}

void Parser::_parse_expr() {
  _next();
  while (_scanner) {
    _parse_stmt();
    _expect(Tid::semicolon);
  }
}

void Parser::_parse_stmt() {
  switch (
      _expect(Tid::type_kw, Tid::var_kw, Tid::const_kw, Tid::class_kw, Tid::var_ident)) {
    case Tid::type_kw:
    case Tid::var_kw:
    case Tid::const_kw:
    case Tid::class_kw: _parse_decl(); return;
    case Tid::var_ident: _parse_var_upd(); return;
    default: return;
  }
}

void Parser::_parse_decl() {
  switch (_expect(Tid::type_kw, Tid::var_kw, Tid::const_kw, Tid::class_kw)) {
    case Tid::type_kw: _parse_type_decl(); return;
    case Tid::var_kw:
    case Tid::const_kw: _parse_var_or_const_decl(); return;
    case Tid::class_kw: _parse_class_decl(); return;
    default: return;
  }
}

void Parser::_parse_type_decl() {
  _expect(Tid::type_ident);
  _expect(Tid::assign);
  _parse_type_val();
}

void Parser::_parse_var_or_const_decl() {
  _parse_type_val();
  _expect(Tid::var_ident);
  _expect(Tid::assign);
  _parse_var_or_const_val();
}

void Parser::_parse_var_upd() {
  _expect(Tid::assign);
  _parse_var_or_const_val();
}

void Parser::_parse_type_val() {
  _expect(Tid::type_ident);

  if (_accept(Tid::langle)) {
    do {
      _parse_type_val();
    }
    while (_accept(Tid::comma));

    _expect(Tid::rangle);
  }

  while (_accept(Tid::join)) _parse_type_val();
}

void Parser::_parse_var_or_const_val() {
  switch (
      _expect(Tid::str_lit, Tid::num_lit, Tid::var_ident, Tid::lbracket, Tid::lbrace)) {
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
    _parse_var_or_const_val();
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
    _parse_var_or_const_val();
    _expect(Tid::colon);
    _parse_var_or_const_val();
  }
  while (_accept(Tid::comma));

  _expect(Tid::rbrace);
}

void Parser::_parse_class_decl() {
  _expect(Tid::type_ident);
  _expect(Tid::lbrace);

  do {
    if (_accept(Tid::rbrace)) return;
    _parse_stmt();
  }
  while (_accept(Tid::semicolon));

  _expect(Tid::rbrace);
}
