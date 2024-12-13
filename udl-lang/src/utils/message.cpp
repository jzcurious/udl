#include "utils/message.hpp"

using namespace udl;

void Message::operator()(const char* text) {
  std::cout << text << std::endl;
}

void Message::operator()(const char* text, const Source& src, const Cursor& cursor) {
  std::cout << std::format(
      "{} ({}, {}): {}\n", src.fname, cursor.nrow, cursor.ncol, text);
}

void Message::operator()(const char* text, const Source& src, const Token& token) {
  std::cout << std::format(
      "{} ({}, {}): {}\n", src.fname, token.cursor.nrow, token.cursor.ncol, text);
}
