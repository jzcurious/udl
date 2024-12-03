#ifndef _UDL_TSTREAM_
#define _UDL_TSTREAM_

#include "scanner/scanner.hpp"
#include "scanner/source.hpp"
#include "token.hpp"

#include <queue>

namespace udl {

class TokenStream final {
 private:
  Source _source;
  Scanner& _scanner;
  std::queue<Token> _tbuffer;

 public:
  TokenStream(const std::string& fname, Scanner& scanner);
  TokenStream& operator>>(Token& t);
  bool eof();
};

}  // namespace udl

#endif  // _UDL_TSTREAM_
