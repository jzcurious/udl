#ifndef _UDL_SCANNER_
#define _UDL_SCANNER_

#include "scanner/token.hpp"
#include "source.hpp"

#include <vector>

namespace udl {

class Scanner final {
 private:
  Source& _source;
  Cursor _cursor;

 public:
  Scanner(Source& source);
  std::string next_stmt();
  bool eof();
  std::vector<Token> scan();
};

}  // namespace udl

#endif  // _UDL_SCANNER_
