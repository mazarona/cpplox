#include "scanner.hpp"
#include "error.hpp"
#include "token.hpp"
#include <string>

namespace cpplox {
namespace scanner {

Scanner::Scanner(const std::string &source) : m_source{source} {}

std::vector<cpplox::token::Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    m_start = m_current;
    // start is now pointing at the first character of the next token to consume
    scanToken();
  }
  tokens.push_back(cpplox::token::Token(cpplox::token::TokenType::END_OF_FILE,
                                        "", nullptr, m_line));
  return tokens;
}

void Scanner::scanToken() {
  char c = advance();
  switch (c) {
  // single character lexemes.
  case '(':
    addToken(token::TokenType::LEFT_PAREN);
    break;
  case ')':
    addToken(token::TokenType::RIGHT_PAREN);
    break;
  case '{':
    addToken(token::TokenType::LEFT_BRACE);
    break;
  case '}':
    addToken(token::TokenType::RIGHT_BRACE);
    break;
  case ',':
    addToken(token::TokenType::COMMA);
    break;
  case '.':
    addToken(token::TokenType::DOT);
    break;
  case '-':
    addToken(token::TokenType::MINUS);
    break;
  case '+':
    addToken(token::TokenType::PLUS);
    break;
  case ';':
    addToken(token::TokenType::SEMICOLON);
    break;
  case '*':
    addToken(token::TokenType::STAR);
    break;
  // double character lexemes
  case '!':
    addToken(match('=') ? token::TokenType::BANG_EQUAL
                        : token::TokenType::BANG);
    break;
  case '=':
    addToken(match('=') ? token::TokenType::EQUAL_EQUAL
                        : token::TokenType::EQUAL);
    break;
  case '<':
    addToken(match('=') ? token::TokenType::LESS_EQUAL
                        : token::TokenType::LESS);
    break;
  case '>':
    addToken(match('=') ? token::TokenType::GREATER_EQUAL
                        : token::TokenType::GREATER);
    break;
  case '/':
    // lox doesn't consider comments as tokens so ignore it.
    if (peek() == '/') {
      while (peek() != '\n' && !isAtEnd())
        advance();
    } else {
      addToken(token::TokenType::SLASH);
    }
    break;
  // skip these characters
  case ' ':
  case '\r':
  case '\t':
    break;
  case '\n':
    m_line++;
    break;
  case '"':
    string();
    break;
  default:
    if (isDigit(c)) {
      number();
    } else if (isAlpha(c)) {
      identifier();
    } else {
      cpplox::error::error(m_line, "Unexpected character.");
    }
    break;
  }
}

void Scanner::string() {
  while (peek() != '"' && !isAtEnd()) {
    // lox handles multi-line strings.
    if (peek() == '\n')
      m_line++;
    advance();
  }

  if (isAtEnd()) {
    cpplox::error::error(m_line, "Unterminated string.");
    return;
  }

  // consume the closing "
  advance();

  // "hello"
  // ^      ^
  // s      c
  // this is the actual string value that will be used by the interpreter
  // to evaluate expressions.
  std::string tokenLiteral =
      m_source.substr(m_start + 1, m_current - m_start - 2);
  addToken(token::TokenType::STRING, tokenLiteral);
}

void Scanner::number() {
  while (isDigit(peek()))
    advance();

  if (peek() == '.' && isDigit(peekNext())) {
    // consume it
    advance();

    while (isDigit(peek()))
      advance();
  }

  // note that (.123) or (123.) would result in an error "Unexpected character"
  double tokenLiteral =
      std::stod(m_source.substr(m_start, m_current - m_start));
  addToken(token::TokenType::NUMBER, tokenLiteral);
}

void Scanner::identifier() {
  while (isAlphaNumeric(peek()))
    advance();

  std::string identifierLexeme = m_source.substr(m_start, m_current - m_start);
  // check if this lexeme is a keyword
  auto match = keywords.find(identifierLexeme);
  cpplox::token::TokenType type;

  // if not a keyword then it's an identifier otherwise fetch
  // the token type of the lexeme from the keywords map.
  if (match == keywords.end())
    type = token ::TokenType::IDENTIFIER;
  else
    type = match->second;

  addToken(type);
}

void Scanner::addToken(token::TokenType tokenType) {
  addToken(tokenType, nullptr);
}

void Scanner::addToken(cpplox::token::TokenType tokenType,
                       std::any tokenLiteral) {
  std::string tokenLexeme = m_source.substr(m_start, m_current - m_start);
  cpplox::token::Token token(tokenType, tokenLexeme, tokenLiteral, m_line);
  tokens.push_back(token);
}

bool Scanner::isAtEnd() {
  return m_current >= static_cast<int>(m_source.length());
}

char Scanner::advance() { return m_source[m_current++]; }

char Scanner::peek() {
  if (isAtEnd())
    return '\0';
  else
    return m_source[m_current];
}

char Scanner::peekNext() {
  if (m_current + 1 >= static_cast<int>(m_source.length()))
    return '\0';
  else
    return m_source[m_current + 1];
}

bool Scanner::match(char expected) {
  // make sure not to access out of bound
  if (isAtEnd())
    return false;
  if (m_source[m_current] != expected)
    return false;
  advance();
  return true;
}

bool Scanner::isDigit(char c) { return c >= '0' && c <= '9'; }

bool Scanner::isAlpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
bool Scanner::isAlphaNumeric(char c) { return isDigit(c) || isAlpha(c); }

} // namespace scanner
} // namespace cpplox
