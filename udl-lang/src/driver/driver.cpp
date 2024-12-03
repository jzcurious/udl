#include "driver/driver.hpp"

using namespace udl;

Driver::Driver(const std::string& fname)
    : _sstream(fname) {}

SourceStream& Driver::source() {
  return _sstream;
}
