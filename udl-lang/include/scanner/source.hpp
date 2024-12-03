#ifndef _UDL_SSTREAM_
#define _UDL_SSTREAM_

#include <fstream>

namespace udl {

class Source : public std::ifstream {
  // TODO: do not inherit from std::ifstream

 public:
  const std::string fname;
  Source(const std::string& fname);
};

}  // namespace udl

#endif  // _UDL_SSTREAM_
