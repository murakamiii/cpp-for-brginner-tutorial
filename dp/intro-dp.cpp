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

struct DpEdge
{
  std::vector<int> nodes;
  int cost;
  bool isChecked;

  DpEdge(std::vector<int> n, int c): nodes(n), cost(c), isChecked(false){}
};

struct DpNode
{
  int cost;
  bool isMinimized;

  DpNode(): cost(INT_MAX), isMinimized(false){}
};

template <typename T>
struct VectorWrapper
{
  std::vector<T> raw_value;

  VectorWrapper(std::vector<T> vec): raw_value(vec){}

  VectorWrapper filter(std::function<bool(T)> f) {
    std::vector<T> filtered;
    std::copy_if(
      raw_value.begin(),
      raw_value.end(),
      back_inserter(filtered),
      f
    );

    return VectorWrapper(filtered);
  }

  template <typename U>
  VectorWrapper<U> map(std::function<U(T)> f) {
    std::vector<U> transformed;
    std::transform(
      raw_value.begin(),
      raw_value.end(), 
      std::back_inserter(transformed),
      f
    );
    return VectorWrapper<U>(transformed);
  }

  template <typename V>
  V reduce(V init, std::function<V(V,T)> f) {
    return std::accumulate(
      raw_value.begin(),
      raw_value.end(), 
      init,
      f
    );
  }

  void foreach(std::function<void(T)> f) {
    std::for_each(
      raw_value.begin(),
      raw_value.end(),
      f
    );
  }
};


/*
  g++ dp/intro-dp.cpp -std=c++17 -Wall --pedantic-errors && ./a.out dp/eg1.csv
 */
int main(int argc, char const *argv[])
{
  std::string fileName = argv[1];
  std::ifstream ifs(fileName);
  if (ifs.fail()) {
    std::cout << "読み込みエラー" << "\n";
  }
  
  std::vector<DpEdge> edges;
  std::unordered_map<int, DpNode> nodes;

  std::string line;
  while(getline(ifs, line)){
    std::vector<int> v;
    std::stringstream ss{line};
    std::string buf;
    while (std::getline(ss, buf, ',')) {
      v.push_back(std::stoi(buf));
    }

    std::vector<int> node_vec = {v[0], v[1]};

    edges.push_back(
      DpEdge(node_vec, v[2])
    );

    std::vector<int> keys;
    std::copy_if(
      node_vec.begin(), 
      node_vec.end(), 
      back_inserter(keys), 
      [nodes](int x) { return nodes.find(x) == nodes.end();}
    );

    for(auto&& k : keys)
    {
      nodes[k] = DpNode();
    }
  }
  
  int target_node = 0;
  nodes[target_node].isMinimized = true;
  nodes[target_node].cost = 0;

  // while (std::all_of(nodes.begin(), nodes.end(), [](DpNode n) { return n.isMinimized; })){
  while (true){
    std::cout << "\ntarget: " + std::to_string(target_node) << "\n";
    std::vector<DpEdge> target_edges;
    std::copy_if(
      edges.begin(), 
      edges.end(), 
      back_inserter(target_edges), 
      [target_node](DpEdge e) { return std::find(e.nodes.begin(), e.nodes.end(), target_node) != e.nodes.end();}
    );

    // nodesのコストと比較して小さかったら更新する
    for(auto&& edge : target_edges)
    {
      std::vector<int> goal;
      std::copy_if(
        edge.nodes.begin(), 
        edge.nodes.end(), 
        back_inserter(goal), 
        [target_node](int x) { return x != target_node;}
      );
      auto key = goal[0];
      int calc_cost = edge.cost + nodes[target_node].cost;
      std::cout << "key: " + std::to_string(key) << "\n";
      std::cout << "calc_cost: " + std::to_string(calc_cost) << "\n";
      if (calc_cost < nodes[key].cost) {
        nodes[key].cost = calc_cost;
      }      
    }
    

    // isMinimized: falseの中で最小コストのnodeを見つけ、target_nodeにする & isMinimizedをtrue
    std::unordered_map<int, DpNode> filtered;
    std::copy_if(
      nodes.begin(),
      nodes.end(),
      std::inserter(filtered, filtered.end()),
      [](std::pair<int, DpNode>  const& node_pair){ return node_pair.second.isMinimized == false; }
    );
    auto min = std::min_element(
      filtered.begin(),
      filtered.end(),
      [](const auto &lhs, const auto &rhs) {
        return lhs.second.cost < rhs.second.cost;
      }
    );

    target_node = min->first;
    nodes[target_node].isMinimized = true;
    if(filtered.size() == 1) {
      break;
    }
  }

  std::cout << "\n";
  for(auto&& node : nodes)
  {
    std::cout << "node: "
              << std::to_string(node.first) + ", cost: "
              << node.second.cost << "\n";
  }
}
