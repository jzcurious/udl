#include "scanner/scanner.hpp"
#include "messenger/messenger.hpp"

using namespace udl;

Scanner::Scanner(Source& source)
    : _source(source) {}

void Scanner::_scan_line(const Source::Line& line) {
  Span span(line.content);

  for (std::size_t ncol = 0; not span.empty(); ncol = span.begin_idx()) {
    auto token = ScanTable[span];
    span.begin_idx(ncol + token.val.size());

    if (ScanTable::skip.contains(token.tid)) continue;
    token.cursor = {_source.fname, line.num, ncol + 1};

    // TODO: replace to message
    if (token.tid == Tid::unknown) {
      Messenger::unknown_symbol(token);
      exit(1);
    }

    _token_buffer.push(token);
  }
}

Scanner& Scanner::operator>>(Token& token) {
  if (_source.eof()) return *this;

  while (_token_buffer.empty() and not _source.eof()) {
    Source::Line line;
    _source >> line;
    _scan_line(line);
  }

  if (_token_buffer.empty()) return *this;

  token = _token_buffer.front();
  _token_buffer.pop();

  return *this;
}

bool Scanner::eof() {
  return _token_buffer.empty() and _source.eof();
}

Scanner::operator bool() {
  return not eof();
}
