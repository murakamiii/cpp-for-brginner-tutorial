#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../libs/catch/catch.hpp"
#include "../src/my_sort.cpp"

TEST_CASE("バブルソート", "[assert_sorted]") {
  std::vector<int> vec_empty{};
  std::vector<int> vec_one{12};
  std::vector<int> vec_two{2, 1};
  std::vector<int> vec_ten{11, 15, 13, 1, 234, 22, 3, 4, 13, 0};

  SECTION("test assert_sorted") {
    REQUIRE(assert_sorted(vec_ten, true) == false);
  }

  SECTION("test bubble sort") {
    // 空配列
    REQUIRE(bubble_sorted(vec_empty, true) == std::vector<int>({}));
    // 要素数1の配列
    REQUIRE(bubble_sorted(vec_one, true) == std::vector<int>({12}));
    // 要素数2の配列
    REQUIRE(bubble_sorted(vec_two, true) == std::vector<int>({1, 2}));
    // 要素数10の配列・昇順
    CHECK(bubble_sorted(vec_ten, true) == std::vector<int>({0, 1, 3, 4, 11, 13, 13, 15, 22, 234}));
    // 要素数10の配列・降順
    CHECK(bubble_sorted(vec_ten, false) == std::vector<int>({234, 22, 15, 13, 13, 11, 4, 3, 1, 0}));
  }
}