#ifndef _UDL_SCANTABLE_
#define _UDL_SCANTABLE_

#include "token.hpp"
#include <regex>

namespace udl {

class ScanTable final {
 private:
  // clang-format off
  inline static std::regex _patterns[] = {
      std::regex(R"(\n)")                     /*NEWLINE*/,
      std::regex(R"(;)")                      /*SEMICOLON*/,
      std::regex(R"(^[A-Z_][a-zA-Z0-9_]*)")   /*IDENT_TYPE*/,
      std::regex(R"(^[a-z][a-z0-9_]*)")       /*IDENT_VAR*/,
      std::regex(R"(^[0-9]+(\.[0-9]+)?)")     /*NUM_LIT*/,
      std::regex(R"(\"([^\"\n]|\.)*\")")      /*STR_LIT*/,
      std::regex(R"(^\.)")                    /*UNKNOWN_CHAR*/,
  };
  // clang-format on

 public:
  static Token operator[](const std::string& s);
};

}  // namespace udl

#endif  // _UDL_SCANTABLE_
