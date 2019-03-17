#include <iostream>

int main() {
    // unit33
    std::cout << "飛距離\n" << "\n";

    int len;
    std::cin >> len;

    if (90 <= len && len <= 110) {
        std::cout << "メダルゲット" << "\n";
    }

    // unit34
    if (len <= 50 || 150 <= len) {
        std::cout << "へたっぴ" << "\n";
    }
    
    
}