#include <iostream>

int main()
{
    int price = 300;
    std::cout << price << "\n";
    std::cout << price * 2 << "\n";

    // unit15
    price = 500;
    std::cout << price * 1.08 << "\n";

    // unit16
    int a = 1010, b = 9090, c = a;
    std::cout << a * b * c << "\n";

    // unit17
    std::cout << "個数？" << "\n";
    int n;
    std::cin >> n;
    std::cout << "合計 " << a * n << " 金\n"; 
}