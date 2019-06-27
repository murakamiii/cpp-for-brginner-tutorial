#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include "my_sort.cpp"
#include "my_container.hpp"

int main() {  
  std::vector<int> v{};
  mystd::VectorStack<int> vecStack = mystd::VectorStack(v);
  
  auto p = vecStack.pop();
  if (p.has_value()) {
    std::cout << "VectorStack.pop: " << p.value() << "\n";
  } else {
    std::cout << "VectorStack.pop: null" << "\n";
  }

  vecStack.push(99);
  vecStack.push(100);
  vecStack.push(101);
  p = vecStack.pop();
  if (p.has_value()) {
    std::cout << "VectorStack.pop: " << p.value() << "\n";
  } else {
    std::cout << "VectorStack.pop: null" << "\n";
  }
}