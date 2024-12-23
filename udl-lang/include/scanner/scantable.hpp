#ifndef _UDL_SCANTABLE_
#define _UDL_SCANTABLE_

#include "strspan.hpp"
#include "token.hpp"

#include <regex>
#include <set>

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
      std::regex(R"(^const)")                   /*const_kw*/,
      std::regex(R"(^struct)")                  /*struct_kw*/,
      std::regex(R"(^[A-Z][A-Za-z0-9_]*)")      /*type_id*/,
      std::regex(R"(^\|)")                      /*join*/,
      std::regex(R"(^[a-z][a-z0-9_]*)")         /*var_id*/,
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
      std::regex(R"(^//.*$)")                   /*line_comment*/,
      std::regex(R"(^/\*(.|\s)*\*/)")           /*block_comment*/,
  };

  inline static const char* _repr[] = {
      "unknown",
      "indent",
      "space",
      "\"type\"",
      "\"var\"",
      "\"const\"",
      "\"struct\"",
      "type identifier",
      "\"|\"",
      "variable identifier",
      "\"=\"",
      "string literal",
      "number literal",
      "\";\"",
      "\"[\"",
      "\"]\"",
      "\"{\"",
      "\"}\"",
      "\"<\"",
      "\">\"",
      "\":\"",
      "\",\"",
      "line comment",
      "block comment",
  };
  // clang-format on

 public:
  // clang-format off
  inline static const std::set<Tid> skip = {
    Tid::space,
    Tid::indent,
    Tid::line_comment,
    Tid::block_comment,
  };
  // clang-format on

  static Token operator[](const Span& span);
  static const char* operator[](const Token& token);
  static const char* operator[](Tid tid);
};

inline ScanTable ScanTable;

}  // namespace udl

#endif  // _UDL_SCANTABLE_
