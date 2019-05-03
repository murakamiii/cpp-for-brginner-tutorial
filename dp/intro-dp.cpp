/*
  https://mieruca-ai.com/ai/introduction-dynamic-programming/
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

struct dpEdge
{
  std::vector<int> nodes;
  int cost;
  bool isChecked;

  dpEdge(std::vector<int> n, int c): nodes(n), cost(c), isChecked(false){}
};

struct dpNode
{
  int cost;
  bool isMinimized;

  dpNode(): cost(INT_MAX), isMinimized(false){}
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
  
  std::vector<dpEdge> edges;
  std::unordered_map<int, dpNode> nodes;

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
      dpEdge(node_vec, v[2])
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
      nodes[k] = dpNode();
    }
  }
  
  int target_node = 0;
  nodes[target_node].isMinimized = true;
  nodes[target_node].cost = 0;

  // while (std::all_of(nodes.begin(), nodes.end(), [](dpNode n) { return n.isMinimized; })){
  while (true){
    std::cout << "\ntarget: " + std::to_string(target_node) << "\n";
    std::vector<dpEdge> target_edges;
    std::copy_if(
      edges.begin(), 
      edges.end(), 
      back_inserter(target_edges), 
      [target_node](dpEdge e) { return std::find(e.nodes.begin(), e.nodes.end(), target_node) != e.nodes.end();}
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
    std::unordered_map<int, dpNode> filtered;
    std::copy_if(
      nodes.begin(),
      nodes.end(),
      std::inserter(filtered, filtered.end()),
      [](std::pair<int, dpNode>  const& node_pair){ return node_pair.second.isMinimized == false; }
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
