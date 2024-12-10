#ifndef _UDL_SCANTABLE_
#define _UDL_SCANTABLE_

#include "strspan.hpp"
#include "token.hpp"

#include <regex>

namespace udl {

using Span = strspan::StrSpan<const std::string>;

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
      std::regex(R"(^\.)")                    /*UNKNOWN*/,
  };
  // clang-format on

 public:
  static Token operator[](const Span& span);
};

inline ScanTable ScanTable;

}  // namespace udl

#endif  // _UDL_SCANTABLE_
