#include "scanner/scantable.hpp"
#include "scanner/token.hpp"

using namespace udl;

Token ScanTable::operator[](const Span& span) {
  std::smatch sm;
  std::size_t i = 0;

  for (auto p : _patterns) {
    std::regex_search(span.begin(), span.end(), sm, _patterns[i]);
    if (sm.size()) return Token{static_cast<Tid>(i), sm[0]};
    ++i;
  }

  return Token{};
}

const char* ScanTable::operator[](const Token& token) {
  return _repr[token.tid];
}
