#ifndef _UDL_SCANNER_
#define _UDL_SCANNER_

#include "scanner/scantable.hpp"  // IWYU pragma: export
#include "scanner/source.hpp"
#include "scanner/token.hpp"

#include <queue>

namespace udl {

class Scanner final {
 private:
  Source& _source;
  std::queue<Token> _token_buffer;

  void _scan(const Source::Line& line);

 public:
  Scanner(Source& source);
  Scanner& operator>>(Token& token);
  operator bool();
  bool source_eof();
};

}  // namespace udl

#endif  // _UDL_SCANNER_
