#include "scanner/scantable.hpp"
#include "scanner/source.hpp"
#include "scanner/token.hpp"
#include <format>
#include <gtest/gtest.h>
#include <iostream>
#include <scanner/scanner.hpp>

TEST(Source, read) {
  udl::Source src("/home/void/Projects/cpp/udl/assets/v1.udl");
  udl::Scanner scanner(src);

  udl::Token t;

  while (scanner >> t) {
    std::cout << std::format(
        "({}, {}) {} : \"{}\"\n", t.cursor.nrow, t.cursor.ncol, udl::ScanTable[t], t.val);
  }

  EXPECT_EQ(1, 1);
}
