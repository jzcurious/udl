#ifndef _UDL_SSTREAM_
#define _UDL_SSTREAM_

#include <fstream>

namespace udl {

class Source {
 private:
  const char _delim = ';';
  std::fstream _ifstream;

 public:
  const std::string fname;
  Source(const std::string& fname);
  Source& operator>>(std::string& stmt);
  bool eof();
};

}  // namespace udl

#endif  // _UDL_SSTREAM_
