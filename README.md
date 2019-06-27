## Thirdparty libraries
* Catch2: see [basic_algorithm/libs/catch/LICENSE.txt](basic_algorithm/libs/catch/LICENSE.txt).

## execute basic_alogorithm
cmake --build . --target a.out && ./a.out

## test
cmake --build . --target unit_test.out && ctest && cat Testing/Temporary/LastTest.log