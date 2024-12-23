#ifndef _UDL_MESSENGER_
#define _UDL_MESSENGER_

#include "scanner/scantable.hpp"  // IWYU pragma: export
#include "scanner/token.hpp"

#include <format>  // IWYU pragma: export
#include <iostream>  // IWYU pragma: export

using namespace udl;

struct Messenger final {
  template <TidT... Ts>
  static void unexpected_symbol(
      const Token& first_sym, const Token& follow_sym, Ts... tids);

  static void unknown_symbol(const Token& sym);
};

template <TidT... Ts>
void Messenger::unexpected_symbol(
    const Token& first_sym, const Token& follow_sym, Ts... tids) {
  const char* repr = ScanTable[follow_sym];

  if (repr[0] == '\"') {
    std::cout << std::format("Unexpected symbol \"{}\" after \"{}\" at {}\n",
        follow_sym.val,
        first_sym.val,
        follow_sym.cursor.path());
  } else {
    std::cout << std::format("Unexpected symbol \"{}\" as {} after \"{}\" at {}\n",
        follow_sym.val,
        repr,
        first_sym.val,
        follow_sym.cursor.path());
  }

  if constexpr (sizeof...(tids) == 1) {
    std::cout << std::format("  ~~> The expected symbol is a {}", ScanTable[tids]...);
  } else {
    std::cout << "  ~~> One of the following characters was expected:\n";
    ((std::cout << std::format("        {}\n", ScanTable[tids])), ...);
  }
}

#endif  // _UDL_MESSENGER_
