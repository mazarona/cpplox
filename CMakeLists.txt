# minimum version of cmake required to run this build
cmake_minimum_required(VERSION 3.15)

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

# create an interface library that each module in the project
# should link to.
add_library(cpplox_compile_flags INTERFACE)
set(gcc "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
# Only if I'm building my project should my flags be set
# but if I'm installing it no need for warnings. so check
# the BUILD_INTERFACE.
target_compile_options(cpplox_compile_flags INTERFACE "$<${gcc}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>")
target_compile_options(cpplox_compile_flags INTERFACE "$<${msvc}:$<BUILD_INTERFACE:-W3>>")

# add the src subdirectory
add_subdirectory(src)
