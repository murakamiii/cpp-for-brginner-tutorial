#include <vector>
#include <numeric>
#include <random>

template <typename T> bool assert_sorted(const std::vector<T>& vec, bool is_ascending) {
    if (vec.size() < 2) { return true; }
    for (std::size_t i = 0 ; i + 1 <  vec.size(); ++i) {
        if ((is_ascending && vec[i] > vec[i+1]) || (!is_ascending && vec[i] < vec[i+1])) {
            return false;
        }
    }
    return true;
}

template <typename T> std::vector<T> bubble_sorted(const std::vector<T>& vec, bool is_ascending) {
    std::vector<T> sorted(vec.size());
    std::copy(vec.begin(), vec.end(), sorted.begin());
    if (sorted.size() < 2) return sorted;

    for (std::size_t i = 0 ; i + 1 <  sorted.size(); ++i) {
        for (std::size_t j = sorted.size() - 1 ; j > i ; --j) {
            if ((is_ascending && sorted[j] < sorted[j-1]) || (!is_ascending && sorted[j] > sorted[j-1])) {
                auto temp = sorted[j];
                sorted[j] = sorted[j-1];
                sorted[j-1] = temp;
            }
        }
        
        if (assert_sorted(sorted, is_ascending)) {
            break;
        }
    }
    
    return sorted;
}