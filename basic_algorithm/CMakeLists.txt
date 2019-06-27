cmake_minimum_required(VERSION 3.13)
enable_language(CXX)
project(BSC_ALG)

set(main_src
  src/my_sort.cpp
  src/my_container.h
  src/my_container.cpp
  src/main.cpp
)

add_definitions("-std=c++17 -Wall --pedantic-errors") 
add_executable(a.out ${main_src})

enable_testing()

set(test_src
  test/test_sort.cpp
  test/test_container.cpp
)
add_executable(unit_test.out ${test_src}) 

set (CATCH_INCLUDE_DIR libs/catch})
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
target_link_libraries(unit_test.out Catch)

add_test(UNITTEST unit_test.out)