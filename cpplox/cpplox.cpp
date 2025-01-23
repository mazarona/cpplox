#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "error.hpp"
#include "scanner.hpp"
#include "token.hpp"

std::string readFile(const std::string &path) {
  std::string source;

  // open a file
  std::fstream file;
  file.open(path, std::ios::in);
  std::stringstream ss;
  // read from file to stringstream ss
  ss << file.rdbuf();
  source = ss.str();

  return source;
}

void run(const std::string &source) {
  cpplox::scanner::Scanner scanner{source};
  std::vector<cpplox::token::Token> tokens = scanner.scanTokens();

  // just print the token for now
  for (auto token : tokens) {
    std::cout << token.toString() << std::endl;
  }
}

void runFile(const std::string &path) {
  std::string source = readFile(path);
  run(source);
  if (cpplox::error::hadError) std::exit(65);
}

void runPrompt() {
  for (;;) {
    std::cout << "> ";
    std::string line;
    if (!getline(std::cin, line)) break;
    run(line);
    // don't exit if he mistypes when the interpreter runs
    // interactively
    cpplox::error::hadError = false;
  }
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    std::cout << "Usage: cpplox [script]" << std::endl;
    std::exit(64);
  } else if (argc == 2) {
    runFile(static_cast<std::string>(argv[1]));
  } else {
    runPrompt();
  }
  return 0;
}
