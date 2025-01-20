# minimum version of cmake required to run this build
cmake_minimum_required(VERSION 3.10)

# set project name and language
project(cpplox DESCRIPTION "Tree-walking interpreter for the lox programming language" LANGUAGES CXX)

# generate compile_commands.json for clang LSP
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
file(CREATE_LINK
  "${CMAKE_BINARY_DIR}/compile_commands.json"
  "${CMAKE_SOURCE_DIR}/compile_commands.json"
  SYMBOLIC
)

# Set the C++ standard used to compile this project
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add the src subdirectory
add_subdirectory(src)
