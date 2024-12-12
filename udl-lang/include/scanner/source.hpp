#ifndef _UDL_SSTREAM_
#define _UDL_SSTREAM_

#include <fstream>

namespace udl {

class Source {
 private:
  std::size_t _line_counter = 0;
  std::fstream _ifstream;

 public:
  struct Line {
    std::size_t num;
    std::string content;
  };

  const std::string fname;
  Source(const std::string& fname);
  Source& operator>>(Line& line);
  operator bool();
  bool eof();
};

}  // namespace udl

#endif  // _UDL_SSTREAM_
