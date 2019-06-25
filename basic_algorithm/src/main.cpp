#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include "my_sort.cpp"

int main() {
  auto vec_sorted = bubble_sorted(std::vector<int>({11, 15, 13, 1, 234, 22, 3, 4, 13}), true);
  auto vec_q_sorted = quick_sorted(std::vector<int>({11, 15, 13, 1, 234, 22, 3, 4, 13}), true);
  
  std::cout << "vec_sorted: " ;
  std::for_each(begin(vec_sorted), end(vec_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
  
  std::cout << "qck_sorted: " ;
  std::for_each(begin(vec_q_sorted), end(vec_q_sorted), [&](auto i){ std::cout << i << " "; });
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
  
  auto qck_rnd_sorted = quick_sorted(vec_rnd, false);
  std::cout << "qck_rnd_sorted: " ;
  std::for_each(begin(qck_rnd_sorted), end(qck_rnd_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
  
  auto ins_rnd_sorted = insert_sorted(vec_rnd, false);
  std::cout << "ins_rnd_sorted: " ;
  std::for_each(begin(ins_rnd_sorted), end(ins_rnd_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;

  auto merge_rnd_sorted = merge_sorted(vec_rnd, false);
  std::cout << "mer_rnd_sorted: " ;
  std::for_each(begin(merge_rnd_sorted), end(merge_rnd_sorted), [&](auto i){ std::cout << i << " "; });
  std::cout << "\n" ;
}