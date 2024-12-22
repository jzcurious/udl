#include "parser/parser.hpp"
#include "scanner/scantable.hpp"
#include "scanner/source.hpp"
#include "scanner/token.hpp"
#include <format>
#include <gtest/gtest.h>
#include <iostream>
#include <scanner/scanner.hpp>

// TEST(Scanner, scan) {
//   udl::Source src("/home/void/Projects/cpp/udl/assets/tests.udl");
//   udl::Scanner scanner(src);

//   udl::Token t;

//   while (scanner >> t) {
//     std::cout << std::format(
//         "({}, {}) {} : \"{}\"\n", t.cursor.nrow, t.cursor.ncol, udl::ScanTable[t],
//         t.val);
//   }

//   EXPECT_EQ(1, 1);
// }

TEST(Parser, parse) {
  udl::Source src("/home/void/Projects/cpp/udl/assets/tests.udl");
  udl::Scanner scanner(src);
  udl::Parser parser(scanner);

  parser.parse();

  EXPECT_EQ(1, 1);
}
