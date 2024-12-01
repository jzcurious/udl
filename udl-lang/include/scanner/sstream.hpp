#ifndef _UDL_SSTREAM_
#define _UDL_SSTREAM_

#include <fstream>

namespace udl {

class SourceStream {
 private:
  std::ifstream _ifstream;

 public:
  const std::string fname;
  SourceStream(const std::string& fname);
  std::ifstream& operator>>(std::string& s);
};

}  // namespace udl

#endif  // _UDL_SSTREAM_
