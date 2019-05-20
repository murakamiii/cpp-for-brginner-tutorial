#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include "my_sort.cpp"

int main() {
  std::vector<int> vec{11, 15, 13, 1, 234, 22, 3, 4, 13};
  auto vec_sorted = bubble_sorted(vec, true);
  
  std::cout << "vec_sorted: " ;
  std::for_each(begin(vec_sorted), end(vec_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
  
  std::random_device rd{};
  std::vector<unsigned short int> vec_rnd(10);
  std::generate( vec_rnd.begin(), vec_rnd.end(), std::ref(rd));
  
  std::cout << "vec_rnd: " ;
  std::for_each(begin(vec_rnd), end(vec_rnd), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
  
  auto vec_rnd_sorted = bubble_sorted(vec_rnd, false);
  std::cout << "vec_rnd_sorted: " ;
  std::for_each(begin(vec_rnd_sorted), end(vec_rnd_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
}