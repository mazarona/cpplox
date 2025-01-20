add_executable(cpplox cpplox.cpp)

add_subdirectory(scanner)

add_library(cpplox_dep INTERFACE)
target_link_libraries(cpplox_dep INTERFACE scanner)

target_link_libraries(cpplox cpplox_dep)

