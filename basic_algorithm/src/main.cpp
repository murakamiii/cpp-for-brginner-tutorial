#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include "my_sort.cpp"
#include "my_container.h"

int main() {
  // auto vec_sorted = bubble_sorted(std::vector<int>({11, 15, 13, 1, 234, 22, 3, 4, 13}), true);
  // auto vec_q_sorted = quick_sorted(std::vector<int>({11, 15, 13, 1, 234, 22, 3, 4, 13}), true);
  
  // std::cout << "vec_sorted: " ;
  // std::for_each(begin(vec_sorted), end(vec_sorted), [&](auto i){ std::cout << i << " "; });
  // std::cout << "\n" ;
  
  // std::cout << "qck_sorted: " ;
  // std::for_each(begin(vec_q_sorted), end(vec_q_sorted), [&](auto i){ std::cout << i << " "; });
  // std::cout << "\n" ;
  
  std::cout << "qck_sorted: " << mystd::two() << "\n";
  std::vector<int> v{12, 23};
  mystd::VectorStack<int> vecStack = mystd::VectorStack(v);
  vecStack.push(99);
  // std::optional<int> p = vecStack.pop();
  // if (p.has_value()) {
    // std::cout << "VectorStack.pop: " << p.value() << "\n";
  // } else {
  //   std::cout << "VectorStack.pop: null" << "\n";
  // }
}