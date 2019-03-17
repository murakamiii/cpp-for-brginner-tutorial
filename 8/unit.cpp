#include <iostream>
#include <random>

int main() {
    // unit35
    std::mt19937 rng;

    std::cout << rng() << "\n";
    std::cout << rng() << "\n";
    std::cout << rng() << "\n";
    std::cout << rng() << "\n\n";

    // unit36
    std::random_device rd;
    std::mt19937 rng2(rd());

    for(int i = 0; i < 5; ++i)
    {
        std::cout << rng2() << "\n\n";
    }

    // unit37
    std::random_device rd2;
    std::mt19937 rng3(rd2());
    std::uniform_int_distribution<int> dist(1,6);

    for(int i = 0; i < 5; ++i)
    {
        std::cout << dist(rng3) << "\n";
    }

    std::cout << "\n" << "\n";

    // unit38
    std::uniform_int_distribution<int> point(0,100);

    for(int i = 0; i < 5; ++i)
    {
        std::cout << point(rng3) << "\n";
    }

    // unit39
    enum Fortune
    {
        LUCKY,
        GOOD,
        BAD,
    };

    std::uniform_int_distribution<int> luck(0,2);
    Fortune ftn = static_cast<Fortune>(luck(rng3));
    switch (ftn)
    {
        case LUCKY:
            std::cout << "今日はラッキー" << "\n";
            break;
        case GOOD:
            std::cout << "まずまず" << "\n";
            break;
        case BAD:
            std::cout << "ダメダメ" << "\n";
            break;
        default:
            std::cout << "？？？" << "\n";
            break;
    }
    
}