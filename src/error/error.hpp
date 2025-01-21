#ifndef ERROR_H
#define ERROR_H
#include <string>

extern bool hadError;
void error(int line, const std::string &message);

#endif // ERROR_H
