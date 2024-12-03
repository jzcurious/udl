#include "scanner/source.hpp"

using namespace udl;

Source::Source(const std::string& fname)
    : _ifstream(fname)
    , fname(fname) {}

Source& Source::operator>>(std::string& stmt) {
  std::string stmt_head;
  std::getline(_ifstream, stmt_head, _delim);
  stmt = stmt_head + _delim;
  return *this;
}

bool Source::eof() {
  return _ifstream.eof();
}
