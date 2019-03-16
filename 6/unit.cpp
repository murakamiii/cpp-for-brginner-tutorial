#include <iostream>
#include <thread>
#include <chrono>

int main() {
    // unit29
    for(int i = 0; i < 3; i++)
    {
        std::cout << i << "\n";
    }

    // unit30
    for(int i = 1; i < 100; i *= 2)
    {
        std::cout << i << "ダメージを与えた！\n" << "\n";
    }
    
    // unit31&32
    std::cout << "はじめ\n" << "\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    
    std::cout << "終わり\n" << "\n";
    
}