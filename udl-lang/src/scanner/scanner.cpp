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
  _source >> stmt;
  _cursor.nstmt++;
  return stmt;
}

std::vector<Token> Scanner::scan() {
  std::string stmt = next_stmt();

  return {Token{}};
}
