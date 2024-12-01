#include "tstream.hpp"

using namespace udl;

TokenStream& TokenStream::operator<<(const Token& t) {
  _tbuffer.push(t);
  return *this;
}

TokenStream& TokenStream::operator>>(Token& t) {
  t = _tbuffer.front();
  _tbuffer.pop();
  return *this;
}
