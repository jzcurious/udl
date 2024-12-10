#include "scanner/tstream.hpp"

using namespace udl;

TokenStream::TokenStream(const std::string& fname, Scanner& scanner)
    : _source(fname)
    , _scanner(scanner)
    , _tbuffer() {}

TokenStream& TokenStream::operator>>(Token& token) {
  if (eof()) return *this;

  if (_tbuffer.empty()) {
    auto tokens = _scanner.scan();
    for (; not tokens.empty(); tokens.pop()) {
      _tbuffer.push(tokens.front());
    }
  }

  token = _tbuffer.front();
  _tbuffer.pop();

  return *this;
}

bool TokenStream::eof() {
  return _tbuffer.empty() and _source.eof();
}
