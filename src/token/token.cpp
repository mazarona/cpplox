#include "token.hpp"

#include <any>
#include <string>

namespace cpplox {
namespace token {

Token::Token(TokenType type, std::string lexeme, std::any literal, int line)
    : m_tokenType{type}, m_lexeme{lexeme}, m_literal{literal}, m_line{line} {}

std::string Token::toString() {
  std::string tokenTypeString;
  switch (m_tokenType) {
    case TokenType::LEFT_PAREN:
      tokenTypeString = "LEFT_BRACE";
      break;
    case TokenType::RIGHT_PAREN:
      tokenTypeString = "RIGHT_PAREN";
      break;
    case TokenType::LEFT_BRACE:
      tokenTypeString = "LEFT_BRACE";
      break;
    case TokenType::RIGHT_BRACE:
      tokenTypeString = "RIGHT_BRACE";
      break;
    case TokenType::COMMA:
      tokenTypeString = "COMMA";
      break;
    case TokenType::DOT:
      tokenTypeString = "DOT";
      break;
    case TokenType::MINUS:
      tokenTypeString = "MINUS";
      break;
    case TokenType::PLUS:
      tokenTypeString = "PLUS";
      break;
    case TokenType::SEMICOLON:
      tokenTypeString = "SEMICOLON";
      break;
    case TokenType::SLASH:
      tokenTypeString = "SLASH";
      break;
    case TokenType::STAR:
      tokenTypeString = "STAR";
      break;

      // One or two character tokens.
    case TokenType::BANG:
      tokenTypeString = "BANG";
      break;
    case TokenType::BANG_EQUAL:
      tokenTypeString = "BANG_EQUAL";
      break;
    case TokenType::EQUAL:
      tokenTypeString = "EQUAL";
      break;
    case TokenType::EQUAL_EQUAL:
      tokenTypeString = "EQUAL_EQUAL";
      break;
    case TokenType::GREATER:
      tokenTypeString = "GREATER";
      break;
    case TokenType::GREATER_EQUAL:
      tokenTypeString = "GREATER_EQUAL";
      break;
    case TokenType::LESS:
      tokenTypeString = "LESS";
      break;
    case TokenType::LESS_EQUAL:
      tokenTypeString = "LESS_EQUAL";
      break;

      // Literals.
    case TokenType::IDENTIFIER:
      tokenTypeString = "IDENTIFIER";
      break;
    case TokenType::STRING:
      tokenTypeString = "STRING";
      break;
    case TokenType::NUMBER:
      tokenTypeString = "NUMBER";
      break;

      // Keywords.
    case TokenType::AND:
      tokenTypeString = "AND";
      break;
    case TokenType::CLASS:
      tokenTypeString = "CLASS";
      break;
    case TokenType::ELSE:
      tokenTypeString = "ELSE";
      break;
    case TokenType::FALSE:
      tokenTypeString = "FALSE";
      break;
    case TokenType::FUN:
      tokenTypeString = "FUN";
      break;
    case TokenType::FOR:
      tokenTypeString = "FOR";
      break;
    case TokenType::IF:
      tokenTypeString = "IF";
      break;
    case TokenType::NIL:
      tokenTypeString = "NIL";
      break;
    case TokenType::OR:
      tokenTypeString = "OR";
      break;
    case TokenType::PRINT:
      tokenTypeString = "PRINT";
      break;
    case TokenType::RETURN:
      tokenTypeString = "RETURN";
      break;
    case TokenType::SUPER:
      tokenTypeString = "SUPER";
      break;
    case TokenType::THIS:
      tokenTypeString = "THIS";
      break;
    case TokenType::TRUE:
      tokenTypeString = "TRUE";
      break;
    case TokenType::VAR:
      tokenTypeString = "VAR";
      break;
    case TokenType::WHILE:
      tokenTypeString = "WHILE";
      break;
    case TokenType::END_OF_FILE:
      tokenTypeString = "END_OF_FILE";
      break;
  }

  std::string literal_string;
  switch (m_tokenType) {
    case TokenType::IDENTIFIER:
      literal_string = m_lexeme;
      break;
    case TokenType::STRING:
      literal_string = std::any_cast<std::string>(m_literal);
      break;
    case TokenType::NUMBER:
      // first cast the any object to a double then convert the double
      // all numbers in lox are floating-point numbers.
      literal_string = std::to_string(std::any_cast<double>(m_literal));
      break;
    case TokenType::TRUE:
      literal_string = "true";
      break;
    case TokenType::FALSE:
      literal_string = "false";
      break;
    default:
      literal_string = "nil";
  }

  return tokenTypeString + " " + m_lexeme + " " + literal_string;
}

}  // namespace token
}  // namespace cpplox
