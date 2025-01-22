#include "error.hpp"
#include <iostream>

namespace cpplox {
namespace error {

bool hadError = false;
static void report(int line, const std::string &where,
                   const std::string &message) {
  std::cerr << "[line " << line << "] Error" << where << ": " << message
            << "\n";
  hadError = true;
}

void error(int line, const std::string &message) { report(line, "", message); }

} // namespace error
} // namespace cpplox
