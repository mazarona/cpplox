#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace cpplox {
namespace token {
class Token {
public:
  Token() = default;
  std::string toString();
};
} // namespace token
} // namespace cpplox

#endif // TOKEN_H
