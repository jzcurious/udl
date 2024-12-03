#include "scanner/scanner.hpp"
#include "scanner/token.hpp"
#include <string>

using namespace udl;

Scanner::Scanner(Source& source)
    : _source(source)
    , _cursor() {}

bool Scanner::eof() {
  return _source.eof();
}

std::string Scanner::next_stmt() {
  std::string stmt;
  std::getline(_source, stmt, delim);
  _cursor.nstmt++;
  return stmt;
}

std::vector<Token> Scanner::scan() {
  std::string stmt = next_stmt();
  auto t = Token{.cursor = _cursor};
  return {Token{}};
}
