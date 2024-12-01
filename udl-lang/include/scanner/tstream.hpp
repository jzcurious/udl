#ifndef _UDL_TSTREAM_
#define _UDL_TSTREAM_

#include "token.hpp"

#include <queue>

namespace udl {

class TokenStream {
 private:
  std::queue<Token> _tbuffer;

 public:
  TokenStream& operator<<(const Token& t);
  TokenStream& operator>>(Token& t);
};

}  // namespace udl

#endif  // _UDL_TSTREAM_
