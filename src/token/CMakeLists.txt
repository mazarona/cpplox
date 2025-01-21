# Add a new traget that needs to be compiled and that will
# be linked to
add_library(token STATIC token.cpp)

# Any target that links to token needs to find its include
# file which is located at ${CMAKE_CURRENT_SOURCE_DIR} while
# the token target itself has no problem finding it. so
# we put INTERFACE.
target_include_directories(token INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(token PUBLIC cpplox_compile_flags)

