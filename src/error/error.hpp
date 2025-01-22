#ifndef ERROR_H
#define ERROR_H
#include <string>

namespace cpplox {
namespace error {

extern bool hadError;
void error(int line, const std::string &message);

} // namespace error
} // namespace cpplox

#endif // ERROR_H
