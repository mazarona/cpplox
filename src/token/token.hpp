#ifndef TOKEN_H
#define TOKEN_H

#include <any>
#include <string>

namespace cpplox {
namespace token {

enum class TokenType {
  // Single-character tokens.
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,

  // One or two character tokens.
  BANG,
  BANG_EQUAL,
  EQUAL,
  EQUAL_EQUAL,
  GREATER,
  GREATER_EQUAL,
  LESS,
  LESS_EQUAL,

  // Literals.
  IDENTIFIER,
  STRING,
  NUMBER,

  // Keywords.
  AND,
  CLASS,
  ELSE,
  FALSE,
  FUN,
  FOR,
  IF,
  NIL,
  OR,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE,
  END_OF_FILE,
};

std::string toString(TokenType tokenType);

class Token {
public:
  Token(TokenType type, std::string lexeme, std::any literal, int line);
  std::string toString();

private:
  TokenType tokenType; // the type of the token according to lox.
  std::string lexeme;  // the sequence of characters the represent the token.
  std::any literal;    // the actual value of the lexeme (string, int ...)
  int line;            // the line where the token is located.
};

} // namespace token
} // namespace cpplox

#endif // TOKEN_H
