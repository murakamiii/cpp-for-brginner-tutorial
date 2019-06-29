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

  mystd::LLStack<int> lStack{};
  auto lp = lStack.pop();
  if (lp.has_value()) {
    std::cout << "LLStack.pop: " << lp.value() << "\n";
  } else {
    std::cout << "LLStack.pop: null" << "\n";
  }
  lStack.push(1111);
  lStack.push(2222);
  lp = lStack.pop();
  if (lp.has_value()) {
    std::cout << "LLStack.pop: " << lp.value() << "\n";
  } else {
    std::cout << "LLStack.pop: null" << "\n";
  }
  lp = lStack.pop();
  if (lp.has_value()) {
    std::cout << "LLStack.pop: " << lp.value() << "\n";
  } else {
    std::cout << "LLStack.pop: null" << "\n";}
}