#ifndef _UDL_SCANNER_
#define _UDL_SCANNER_

#include "scanner/scantable.hpp"  // IWYU pragma: export
#include "scanner/token.hpp"
#include "source.hpp"

#include <queue>

namespace udl {

class Scanner final {
 private:
  Source& _source;

 public:
  Scanner(Source& source);
  std::queue<Token> scan();
};

}  // namespace udl

#endif  // _UDL_SCANNER_
