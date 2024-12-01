#include "sstream.hpp"

using namespace udl;

SourceStream::SourceStream(const std::string& fname)
    : fname(fname)
    , _ifstream(fname) {}

std::ifstream& SourceStream::operator>>(std::string& s) {
  _ifstream >> s;
  return _ifstream;
}
