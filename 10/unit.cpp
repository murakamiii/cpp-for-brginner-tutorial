#include <iostream>
#include <vector>
#include <string>

int main() {
    // unit49
    std::vector<std::string> items = { "スイカキャンディ" , "スイカアイス", "スイカジュース", "皮" };

    // unit50 
    for(auto&& i : items)
    {
        std::cout << i << "\n";
    }

    // unit51
    std::vector<int> prices = { 100, 350, 120, 10 };
    std::cout << items[0] << "は" << prices[0] << "円" << "\n";

}