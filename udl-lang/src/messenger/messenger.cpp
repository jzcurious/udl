#include "messenger/messenger.hpp"

void Messenger::unknown_symbol(const Token& sym) {
  std::cout << std::format("Unknown symbol at {}\n", sym.cursor.path());
}
