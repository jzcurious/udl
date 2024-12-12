#include "scanner/source.hpp"

using namespace udl;

Source::Source(const std::string& fname)
    : _ifstream(fname)
    , fname(fname) {}

Source& Source::operator>>(Line& line) {
  if (eof()) return *this;

  for (line.content = '\n'; line.content == "\n";) {
    std::getline(_ifstream, line.content);
    line.num = ++_line_counter;
  }

  return *this;
}

Source::operator bool() {
  return not _ifstream.eof();
}

bool Source::eof() {
  return _ifstream.eof();
}
