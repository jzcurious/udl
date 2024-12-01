#ifndef _UDL_DRIVER_
#define _UDL_DRIVER_

#include "scanner/sstream.hpp"

namespace udl {

class Driver final {
 private:
  SourceStream _sstream;
  // scanner
  // parser

 public:
  Driver(const std::string& fname)
      : _sstream(fname) {}

  SourceStream& source() {
    return _sstream;
  }
};

}  // namespace udl

#endif  // _UDL_DRIVER_
