#ifndef SCANNER_H
#define SCANNER_H

#include "token.hpp"
#include <map>
#include <string>
#include <vector>

namespace cpplox {
namespace scanner {
class Scanner {
public:
  Scanner(const std::string &source);
  std::vector<cpplox::token::Token> scanTokens();

private:
  std::vector<cpplox::token::Token> tokens;
  // Add a new token of type tokenType.
  void addToken(token::TokenType tokenType);
  // addToken overload to handle tokens with literal values.
  void addToken(cpplox::token::TokenType tokenType, std::any tokenLiteral);

  // consume the string token
  void string();
  // consume the number token
  void number();
  // consume the identifier token
  // the identifier token could be one of three things
  // 1. An Identifier. duh
  // 2. A keyword.
  // 3. A literal (true, false, nil)
  void identifier();

  bool match(char expected);
  // scan a single token
  void scanToken();
  // are we at the end of the source code
  bool isAtEnd();
  // return char and advance cursor by 1
  char advance();
  // peek at the character without consuming it.
  // this is called lookahead
  // the smaller this number, the faster the scanner.
  char peek();
  // peek at the next character without consuming it.
  char peekNext();

  bool isDigit(char c);
  bool isAlpha(char c);
  bool isAlphaNumeric(char c);

  int m_start = 0;
  int m_current = 0;
  int m_line = 1;
  const std::string m_source;
  std::map<std::string, cpplox::token::TokenType> keywords{
      {"and", cpplox::token::TokenType::AND},
      {"class", cpplox::token::TokenType::CLASS},
      {"else", cpplox::token::TokenType::ELSE},
      {"false", cpplox::token::TokenType::FALSE},
      {"for", cpplox::token::TokenType::FOR},
      {"fun", cpplox::token::TokenType::FUN},
      {"if", cpplox::token::TokenType::IF},
      {"nil", cpplox::token::TokenType::NIL},
      {"or", cpplox::token::TokenType::OR},
      {"print", cpplox::token::TokenType::PRINT},
      {"return", cpplox::token::TokenType::RETURN},
      {"super", cpplox::token::TokenType::SUPER},
      {"this", cpplox::token::TokenType::THIS},
      {"true", cpplox::token::TokenType::TRUE},
      {"var", cpplox::token::TokenType::VAR},
      {"while", cpplox::token::TokenType::WHILE},
  };
};
} // namespace scanner
} // namespace cpplox

#endif // SCANNER_H
