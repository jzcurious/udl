#include "scanner/scanner.hpp"
#include "scanner/source.hpp"

using namespace udl;

Scanner::Scanner(Source& source)
    : _source(source) {}

void Scanner::_scan(const Source::Line& line) {
  Span span(line.content);

  for (std::size_t ncol = 0; not span.empty(); ncol = span.begin_idx()) {
    auto token = ScanTable[span];
    token.cursor = {line.num, ncol + 1};
    span.begin_idx(ncol + token.val.size());
    _token_buffer.push(token);
  }
}

Scanner& Scanner::operator>>(Token& token) {
  if (_source.eof()) return *this;
  if (_token_buffer.empty()) {
    Source::Line line;
    _source >> line;
    if (not line.content.size()) return *this;
    _scan(line);
  }
  token = _token_buffer.front();
  _token_buffer.pop();
  return *this;
}

bool Scanner::source_eof() {
  return _token_buffer.empty() and _source.eof();
}

Scanner::operator bool() {
  return not source_eof();
}
