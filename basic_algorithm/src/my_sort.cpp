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

template <typename T> std::vector<T> divide(const std::vector<T>& vec) {
    if (vec.size() < 2) { return vec; }
    
    size_t idx_ref = (vec.size() / 2) - 1;
    auto ref = vec[idx_ref];

    std::vector<T> smaller = {};
    std::vector<T> larger = {};
    
    for (size_t i = 0; i < vec.size(); i++) {
        if (i == idx_ref){
            continue;
        }
        
        if (vec[i] <= ref) {
            smaller.push_back(vec[i]);
        } else {
            larger.push_back(vec[i]);
        }
    }

    auto smaller_sorted = divide(smaller);
    const auto larger_sorted = divide(larger);

    smaller_sorted.push_back(ref);
    smaller_sorted.insert(smaller_sorted.end(), larger_sorted.begin(), larger_sorted.end());

    return smaller_sorted;
}

template <typename T> std::vector<T> quick_sorted(const std::vector<T>& vec, bool is_ascending) {
    auto sorted = divide(vec);
    if (!is_ascending) { std::reverse(sorted.begin(), sorted.end()); }
    return sorted;
}

template <typename T> std::vector<T> insert_sorted(const std::vector<T>& vec, bool is_ascending) {
    std::vector<T> sorted = {};
    for (auto &&ele : vec)
    {
        if (sorted.size() == 0)
        {
            sorted.push_back(ele);
            continue;
        }
        
        for (size_t i = 0; i < sorted.size(); i++)
        {
            if (sorted[i] >= ele)
            {
                sorted.insert(sorted.begin() + i, ele);
                break;
            }
            
            if (sorted.size() == i + 1) {
                sorted.push_back(ele);
                break;
            }
        }
        
    }
    if (!is_ascending) { std::reverse(sorted.begin(), sorted.end()); }
    return sorted;
}

template <typename T> std::vector<T> merge(const std::vector<T>& vec) {
    if (vec.size() <= 1)
    {
        return vec;
    }

    const auto v1 = merge(std::vector<T>(vec.begin(), vec.begin() + (vec.size() / 2)));
    const auto v2 = merge(std::vector<T>(vec.begin() + (vec.size() / 2), vec.end()));

    auto v1_idx = 0;
    auto v2_idx = 0;
    std::vector<T> merged {};
    
    while (v1_idx + 1 <= v1.size() && v2_idx + 1 <= v2.size())
    {
        if (v1[v1_idx] < v2[v2_idx])
        {
            merged.push_back(v1[v1_idx]);
            v1_idx += 1;
        } else {
            merged.push_back(v2[v2_idx]);
            v2_idx += 1;
        }
    }

    merged.insert(merged.end(),v1.begin() + v1_idx, v1.end());
    merged.insert(merged.end(),v2.begin() + v2_idx, v2.end());

    return merged;    
}

template <typename T> std::vector<T> merge_sorted(const std::vector<T>& vec, bool is_ascending) {
    auto sorted = merge(vec);
    if (!is_ascending) { std::reverse(sorted.begin(), sorted.end()); }
    return sorted;
}
