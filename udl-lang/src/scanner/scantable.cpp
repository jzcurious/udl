#include "scanner/scantable.hpp"
#include "scanner/token.hpp"

using namespace udl;

Token ScanTable::operator[](const std::string& s) {
  std::smatch sm;
  std::size_t i = 0;

  for (auto p : _patterns) {
    std::regex_search(s, sm, _patterns[i]);
    if (sm.size()) return Token{static_cast<Tid>(i), sm[0]};
    ++i;
  }

  return Token{};
}
