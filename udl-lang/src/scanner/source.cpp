#include "scanner/source.hpp"

using namespace udl;

Source::Source(const std::string& fname)
    : std::ifstream(fname)
    , fname(fname) {}
