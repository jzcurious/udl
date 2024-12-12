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
      std::regex(R"(^    |\t)")                 /*indent*/,
      std::regex(R"(^ )")                       /*space*/,
      std::regex(R"(^type)")                    /*type_kw*/,
      std::regex(R"(^var)")                     /*var_kw*/,
      std::regex(R"(^[A-Z][A-Za-z0-9_]*)")      /*ident_type*/,
      std::regex(R"(^\|)")                      /*join*/,
      std::regex(R"(^[a-z][a-z0-9_]*)")         /*ident_var*/,
      std::regex(R"(^=)")                       /*assign*/,
      std::regex(R"(^\"([^\"\n]|\.)*\")")       /*str_lit*/,
      std::regex(R"(^[0-9]+(\.[0-9]+)?)")       /*num_lit*/,
      std::regex(R"(^;)")                       /*semicolon*/,
      std::regex(R"(^\[)")                      /*lbracket*/,
      std::regex(R"(^\])")                      /*rbracket*/,
      std::regex(R"(^\{)")                      /*lbrace*/,
      std::regex(R"(^\})")                      /*rbrace*/,
      std::regex(R"(^<)")                       /*langle*/,
      std::regex(R"(^>)")                       /*rangle*/,
      std::regex(R"(^:)")                       /*colon*/,
      std::regex(R"(^,)")                       /*comma*/,
      std::regex(R"(^\n)")                      /*newline*/,
      std::regex(R"(^//.*\n)")                  /*line_comment*/,
      std::regex(R"(^/\*(.|\s)*\*/)")           /*block_comment*/,
      std::regex(R"(^.*)")                      /*unknown*/,
  };

  inline static const char* _repr[] = {
      "indent",
      "space",
      "type_kw",
      "var_kw",
      "ident_type",
      "join",
      "ident_var",
      "assign",
      "str_lit",
      "num_lit",
      "semicolon",
      "lbracket",
      "rbracket",
      "lbrace",
      "rbrace",
      "langle",
      "rangle",
      "colon",
      "comma",
      "newline",
      "line_comment",
      "block_comment",
      "unknown",
  };
  // clang-format on

 public:
  static Token operator[](const Span& span);
  static const char* operator[](const Token& token);
};

inline ScanTable ScanTable;

}  // namespace udl

#endif  // _UDL_SCANTABLE_
