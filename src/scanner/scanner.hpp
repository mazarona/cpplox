#ifndef SCANNER_H
#define SCANNER_H

#include "token.hpp"
#include <string>
#include <vector>

namespace cpplox {
namespace scanner {
class Scanner {
public:
  Scanner(const std::string &source);
  std::vector<cpplox::token::Token> scanTokens();
};
} // namespace scanner
} // namespace cpplox

#endif // SCANNER_H
