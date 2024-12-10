#include "scanner/source.hpp"

using namespace udl;

Source::Source(const std::string& fname)
    : _ifstream(fname)
    , fname(fname) {}

Source& Source::operator>>(Row& row) {
  if (eof()) return *this;
  row.num = ++_row_counter;
  std::getline(_ifstream, row.content);
  return *this;
}

bool Source::eof() {
  return _ifstream.eof();
}
