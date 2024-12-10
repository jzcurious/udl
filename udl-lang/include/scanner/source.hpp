#ifndef _UDL_SSTREAM_
#define _UDL_SSTREAM_

#include <fstream>

namespace udl {

struct Row {
  std::size_t num;
  std::string content;
};

class Source {
 private:
  std::size_t _row_counter = 0;
  std::fstream _ifstream;

 public:
  const std::string fname;
  Source(const std::string& fname);
  Source& operator>>(Row& row);
  bool eof();
};

}  // namespace udl

#endif  // _UDL_SSTREAM_
