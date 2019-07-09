// WA

#include <iostream>
#include <unordered_set>
#include <vector>

namespace ds {
class ufds {
public:
  explicit ufds(std::size_t size);
  std::size_t find_set(std::size_t i);
  bool is_same_set(std::size_t i, std::size_t j);
  void union_set(std::size_t i, std::size_t j);
  std::size_t num_components();

  std::size_t size;
  std::vector<std::size_t> parent_index;
  std::vector<std::size_t> rank;
};

inline ufds::ufds(const std::size_t size) : size(size) {
  rank.assign(size, 0);
  parent_index.resize(size);
  for (std::size_t i = 0; i < size; ++i) {
    parent_index[i] = i;
  }
}

inline std::size_t ufds::find_set(const std::size_t i) {
  if (parent_index[i] == i) {
    return i;
  }

  parent_index[i] = find_set(parent_index[i]);
  return parent_index[i];
}

inline bool ufds::is_same_set(const std::size_t i, const std::size_t j) {
  return find_set(i) == find_set(j);
}

inline void ufds::union_set(const std::size_t i, const std::size_t j) {
  if (!is_same_set(i, j)) {
    const auto parent_i = find_set(i);
    const auto parent_j = find_set(j);
    if (rank[parent_i] > rank[parent_j]) {
      parent_index[parent_j] = parent_i;
    } else {
      parent_index[parent_i] = parent_j;
      if (rank[parent_i] == rank[parent_j]) {
        ++rank[parent_j];
      }
    }
  }
}

std::size_t ufds::num_components() {
  std::unordered_set<std::size_t> unique;
  for (std::size_t i = 0; i < size; ++i) {
    // It is super important to use find_set method here
    // Initially I went wrong by just looping over parent_index and trying to
    // find unique elements That was so totally wrong because UFDS updates the
    // parent indices lazily So, I need to use find_set which forcefully updates
    // the parent indices
    unique.insert(find_set(i));
  }
  return unique.size();
}
} // namespace ds

using ll = long long;

ll GetTotalCost(const size_t num_cities,
                const std::vector<std::pair<size_t, size_t>> &roads,
                const int cost_road, const int cost_library) {
  ll total_cost{static_cast<int>(num_cities) * cost_library};
  ds::ufds set(num_cities);
  for (const auto &[u, v] : roads) {
    if (!set.is_same_set(u, v)) {
      const auto new_cost = total_cost - cost_library + cost_road;
      if (new_cost < total_cost) {
        total_cost = new_cost;
        set.union_set(u, v);
      }
    }
  }
  return total_cost;
}

int main(int argc, char *argv[]) {
  auto q{0}, cost_road{0}, cost_library{0};
  size_t n{0}, m{0};
  std::vector<std::pair<size_t, size_t>> roads;

  std::cin >> q;
  while (q--) {
    std::cin >> n >> m >> cost_library >> cost_road;
    roads.resize(m);
    for (size_t i = 0; i < m; ++i) {
      std::cin >> roads[i].first >> roads[i].second;
      --roads[i].first;
      --roads[i].second;
    }
    std::cout << GetTotalCost(n, roads, cost_road, cost_library) << std::endl;
  }
  return 0;
}
