#include <iostream>
#include <string>

int main() {
    // unit19
    int age;

    std::cin >> age;

    if (age < 18) {
        std::cout << "子供\n";

    // unit21
    } else if (age > 60) {
        std::cout << "老人\n";
    // unit20
    } else {
        std::cout << "大人\n";
    }

    // unit22
    std::cout << "1:右 or 2:左？\n";
    int ans;
    std::cin >> ans;
    if (ans == 1) {
        std::cout << "右は行き止まり";
    } else {
        std::cout << "左は出口:ok:";
    }

    // unit23
    std::cout << "1個200円\n何個？\n";
    int n;
    std::cin >> n;

    if (200 * n >= 1000) {
        std::cout << "1000円以上なので割引\n";
    }
    
    std::cout << "飲酒？\n";
    std::string resp;
    std::cin >> resp;
    if (resp == "yes") {
        std::cout << "はい\n";
    }
    
}