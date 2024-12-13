#ifndef _UDL_MESSAGE_
#define _UDL_MESSAGE_

#include "scanner/source.hpp"
#include "scanner/token.hpp"

#include <format>  // IWYU pragma: export
#include <iostream>  // IWYU pragma: export

namespace udl {

class Message {
  static void operator()(const char* text);
  static void operator()(const char* text, const Source& src, const Cursor& cursor);
  static void operator()(const char* text, const Source& src, const Token& token);
};

}  // namespace udl

#endif  // _UDL_MESSAGE_
