#include <iostream>
#include <vector>
#include <numeric>

int main() {
    // unit41
    double wgt = 5.5;

    std::cout << wgt << "キロのスイカ" << "\n";
    // unit43
    std::cout << "半分だと" << wgt / 2 << "\n";

    // unit44 
    std::vector<int> weightList = { 1, 2, 3, 4, 5, 76 };
    std::cout << "全部で" << weightList.size() << "個" << "\n";

    // unit45
    for(int weight : weightList)
    {
        std::cout << weight << "\n";
    }

    // unit46
    std::vector<double> doubleList = { 1.0, 2.3, 5.4, 0.8, 100 };
    std::cout << "全部で" << doubleList.size() << "個" << "\n";

    // unit47
    for(const auto& weight : doubleList)
    {
        std::cout << weight << "\n";
    }
    
    // unit48
    std::cout << "合計:" << std::reduce(doubleList.begin(), doubleList.end()) << "kg" << "\n";
    
}