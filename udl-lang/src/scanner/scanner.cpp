#include "scanner/scanner.hpp"

using namespace udl;

Scanner::Scanner(Source& source)
    : _source(source) {}

std::queue<Token> Scanner::scan() {
  std::queue<Token> tokens;
  Row row;

  _source >> row;
  Span span(row.content);

  for (; span.size();) {
    auto token = ScanTable[span];
    auto ncol = span.begin_idx();
    token.cursor = {row.num, ncol};
    span.begin_idx(ncol + token.val.size());
    tokens.push(token);
  }

  return tokens;
}
