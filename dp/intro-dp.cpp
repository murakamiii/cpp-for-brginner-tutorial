// Copyright 2019 Murakami

/*
  https://mieruca-ai.com/ai/introduction-dynamic-programming/
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <numeric>

struct DpEdge {
  std::vector<int> nodes;
  int cost;
  bool isChecked;

  DpEdge(std::vector<int> n, int c): nodes(n), cost(c), isChecked(false){}
};

struct DpNode {
  int cost;
  bool isMinimized;

  DpNode(): cost(INT_MAX), isMinimized(false){}
};

template <typename T> struct VectorWrapper {
  std::vector<T> raw_value;
  explicit VectorWrapper(std::vector<T> vec): raw_value(vec) {}

  T min(std::function<bool(T,T)> f) {
    auto min = std::min_element(raw_value.begin(), raw_value.end(), f);
    return *min;
  }

  T max(std::function<bool(T,T)> f) {
    auto max = std::max_element(raw_value.begin(), raw_value.end(), f);
    return *max;
  }

  VectorWrapper filter(std::function<bool(T)> f) {
    std::vector<T> filtered = {};
    std::copy_if(raw_value.begin(), raw_value.end(), back_inserter(filtered), f);
    return VectorWrapper(filtered);
  }

  template <typename U> VectorWrapper<U> map(std::function<U(T)> f) {
    std::vector<U> transformed;
    std::transform(raw_value.begin(), raw_value.end(), std::back_inserter(transformed), f);
    return VectorWrapper<U>(transformed);
  }

  template <typename V> V reduce(V& init, std::function<V(V, T)> f) {
    return std::accumulate(raw_value.begin(), raw_value.end(), init, f);
  }

  void foreach(std::function<void(T)> f) {
    std::for_each(raw_value.begin(), raw_value.end(), f);
  }
};

template <typename W, typename X> struct MapWrapper {
  using map_type = std::unordered_map<W, X>;
  using pair_type = std::pair<W, X>;
  map_type raw_value;
  explicit MapWrapper(map_type umap): raw_value(umap) {}

  W min(std::function<bool(pair_type, pair_type)> f) {
    auto min = std::min_element(raw_value.begin(), raw_value.end(), f);
    return *min;
  }

  W max(std::function<bool(pair_type, pair_type)> f) {
    auto max = std::max_element(raw_value.begin(), raw_value.end(), f);
    return *max;
  }

  MapWrapper filter(std::function<bool(pair_type)> f) {
    map_type filtered = {};
    std::copy_if(raw_value.begin(), raw_value.end(), std::inserter(filtered), f);
    return MapWrapper(filtered);
  }

  template <typename Y, typename Z> MapWrapper<Y, Z> map(std::function<std::pair<Y, Z>(pair_type)> f) {
    std::unordered_map<Y, Z> transformed;
    std::transform(raw_value.begin(), raw_value.end(), std::inserter(transformed), f);
    return MapWrapper<Y, Z>(transformed);
  }

  template <typename VV> VV reduce(VV& init, std::function<VV(pair_type)> f) {
    return std::accumulate(raw_value.begin(), raw_value.end(), init, f);
  }

  void foreach(std::function<void(pair_type)> f) {
    std::for_each(raw_value.begin(), raw_value.end(), f);
  }
};

/*
  g++ dp/intro-dp.cpp -std=c++17 -Wall --pedantic-errors && ./a.out dp/eg1.csv
 */
int main(int argc, char const *argv[]) {
  std::string fileName = argv[1];
  std::ifstream ifs(fileName);
  if (ifs.fail()) {
    std::cout << "読み込みエラー" << "\n";
  }

  std::vector<DpEdge> edges;
  std::unordered_map<int, DpNode> nodes;

  std::string line;
  while (getline(ifs, line)) {
    std::vector<int> v;
    std::stringstream ss{line};
    std::string buf;
    while (std::getline(ss, buf, ',')) {
      v.push_back(std::stoi(buf));
    }

    std::vector<int> node_vec {v[0], v[1]};

    edges.push_back(
      DpEdge(node_vec, v[2]));

    VectorWrapper(node_vec)
      .filter([=](int x) { return nodes.find(x) == nodes.end();})
      .foreach([&](int key) {
        nodes[key] = DpNode();
      });
  }

  int target_node = 0;
  nodes[target_node].isMinimized = true;
  nodes[target_node].cost = 0;

  while (true) {
    // nodesのコストと比較して小さかったら更新する
    VectorWrapper(edges)
      .filter([=](DpEdge e) {
        return std::find(e.nodes.begin(), e.nodes.end(), target_node) != e.nodes.end();
      })
      .map(std::function<std::pair<int, int>(DpEdge)>([&](DpEdge e) {
        int key = VectorWrapper(e.nodes)
          .filter([=](int x) { return x != target_node;})
          .raw_value[0];
        int calc_cost = e.cost + nodes[target_node].cost;
        return std::make_pair(key, calc_cost);
      }))
      .filter([&](std::pair<int, int> p) { return p.second < nodes[p.first].cost; })
      .foreach([&](std::pair<int, int> p) {
        nodes[p.first].cost = p.second;
      });

    // 未最適化の中で最小コストのnodeを見つけ、target_nodeにするisMinimizedをtrue
    std::unordered_map<int, DpNode> filtered;
    std::copy_if(
      nodes.begin(),
      nodes.end(),
      std::inserter(filtered, filtered.end()),
      [](std::pair<int, DpNode> const& node_pair){
        return node_pair.second.isMinimized == false;
      });
    auto min = std::min_element(
      filtered.begin(),
      filtered.end(),
      [](const auto &lhs, const auto &rhs) {
        return lhs.second.cost < rhs.second.cost;
      });

    target_node = min->first;
    nodes[target_node].isMinimized = true;
    if (filtered.size() == 1) {
      break;
    }
  }

  std::cout << "\n";
  for (auto&& node : nodes) {
    std::cout << "node: "
              << std::to_string(node.first) + ", cost: "
              << node.second.cost << "\n";
  }
}
