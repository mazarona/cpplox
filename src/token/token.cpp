#include "token.hpp"
#include <any>
#include <string>

namespace cpplox {
namespace token {

std::string toString(TokenType tokenType) {
  std::string s;
  switch (tokenType) {
  case TokenType::LEFT_PAREN:
    s = "LEFT_BRACE";
    break;
  case TokenType::RIGHT_PAREN:
    s = "RIGHT_PAREN";
    break;
  case TokenType::LEFT_BRACE:
    s = "LEFT_BRACE";
    break;
  case TokenType::RIGHT_BRACE:
    s = "RIGHT_BRACE";
    break;
  case TokenType::COMMA:
    s = "COMMA";
    break;
  case TokenType::DOT:
    s = "DOT";
    break;
  case TokenType::MINUS:
    s = "MINUS";
    break;
  case TokenType::PLUS:
    s = "PLUS";
    break;
  case TokenType::SEMICOLON:
    s = "SEMICOLON";
    break;
  case TokenType::SLASH:
    s = "SLASH";
    break;
  case TokenType::STAR:
    s = "STAR";
    break;

    // One or two character tokens.
  case TokenType::BANG:
    s = "BANG";
    break;
  case TokenType::BANG_EQUAL:
    s = "BANG_EQUAL";
    break;
  case TokenType::EQUAL:
    s = "EQUAL";
    break;
  case TokenType::EQUAL_EQUAL:
    s = "EQUAL_EQUAL";
    break;
  case TokenType::GREATER:
    s = "GREATER";
    break;
  case TokenType::GREATER_EQUAL:
    s = "GREATER_EQUAL";
    break;
  case TokenType::LESS:
    s = "LESS";
    break;
  case TokenType::LESS_EQUAL:
    s = "LESS_EQUAL";
    break;

    // Literals.
  case TokenType::IDENTIFIER:
    s = "IDENTIFIER";
    break;
  case TokenType::STRING:
    s = "STRING";
    break;
  case TokenType::NUMBER:
    s = "NUMBER";
    break;

    // Keywords.
  case TokenType::AND:
    s = "AND";
    break;
  case TokenType::CLASS:
    s = "CLASS";
    break;
  case TokenType::ELSE:
    s = "ELSE";
    break;
  case TokenType::FALSE:
    s = "FALSE";
    break;
  case TokenType::FUN:
    s = "FUN";
    break;
  case TokenType::FOR:
    s = "FOR";
    break;
  case TokenType::IF:
    s = "IF";
    break;
  case TokenType::NIL:
    s = "NIL";
    break;
  case TokenType::OR:
    s = "OR";
    break;
  case TokenType::PRINT:
    s = "PRINT";
    break;
  case TokenType::RETURN:
    s = "RETURN";
    break;
  case TokenType::SUPER:
    s = "SUPER";
    break;
  case TokenType::THIS:
    s = "THIS";
    break;
  case TokenType::TRUE:
    s = "TRUE";
    break;
  case TokenType::VAR:
    s = "VAR";
    break;
  case TokenType::WHILE:
    s = "WHILE";
    break;
  case TokenType::END_OF_FILE:
    s = "END_OF_FILE";
    break;
  }

  return s;
}

Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
    : tokenType{type}, lexeme{lexeme}, literal{literal}, line{line} {}

std::string Token::toString() {

  std::string literal_string;
  switch (tokenType) {
  case TokenType::IDENTIFIER:
    literal_string = lexeme;
  case TokenType::STRING:
    literal_string = std::any_cast<std::string>(literal);
    break;
  case TokenType::NUMBER:
    // first cast the any object to a double then convert the double
    literal_string = std::to_string(std::any_cast<double>(literal));
    break;
  case TokenType::TRUE:
    literal_string = "true";
    break;
  case TokenType::FALSE:
    literal_string = "false";
    break;
  }

  return cpplox::token::toString(tokenType) + " " + lexeme + " " +
         literal_string;
}

} // namespace token
} // namespace cpplox
