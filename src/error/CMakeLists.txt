# Add a new traget that needs to be compiled and that will
# be linked to
add_library(error STATIC error.cpp)

# Any target that links to error needs to find its include
# file which is located at ${CMAKE_CURRENT_SOURCE_DIR} while
# the error target itself has no problem finding it. so
# we put INTERFACE.
target_include_directories(error INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(error PUBLIC cpplox_compile_flags)

