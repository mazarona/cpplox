# Add a new traget that needs to be compiled and that will
# be linked to
add_library(scanner STATIC scanner.cpp)

# Any target that links to scanner needs to find its include
# file which is located at ${CMAKE_CURRENT_SOURCE_DIR} while
# the scanner target itself has no problem finding it. so
# we put INTERFACE.
target_include_directories(scanner INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(scanner PUBLIC cpplox_compile_flags PRIVATE token)

