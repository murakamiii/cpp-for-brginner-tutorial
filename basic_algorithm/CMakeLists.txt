cmake_minimum_required(VERSION 3.13)
enable_language(CXX)
project(BSC_ALG)

# set(CATCH_INCLUDE_DIR ../libraries/catch)
# add_library(Catch2::Catch IMPORTED INTERFACE)
# set_property(Catch2::Catch PROPERTY INTERFACE_INCLUDE_DIRECTORIES "${CATCH_INCLUDE_DIR}")

set(main_src
  src/my_sort.cpp
  src/main.cpp
)
add_definitions("-std=c++17 -Wall --pedantic-errors") 
add_executable(a.out ${main_src})