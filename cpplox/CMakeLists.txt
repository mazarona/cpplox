add_executable(cpplox cpplox.cpp)

add_subdirectory(error)
add_subdirectory(token)
add_subdirectory(scanner)

add_library(cpplox_dep INTERFACE)
target_link_libraries(cpplox_dep INTERFACE scanner token error)

# cpplox is the final executalbe nothing will link against it
# so there is no need for PUBLIC. make it PRIVATE
target_link_libraries(cpplox PRIVATE cpplox_dep INTERFACE cpplox_compile_flags)

