//
// Created by Gautham on 06-12-2018.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using ll = long long;

struct FerryInfo {
  FerryInfo(ll count, std::vector<std::string> directions) : count(count), directions(std::move(directions)) {}

  ll count;
  std::vector<std::string> directions;
};

class Ferry {
 public:
  Ferry(ll port_len, ll starboard_len, const std::vector<ll> &cars);
  FerryInfo Direct();

 private:
  ll Direct(std::size_t i, ll port_len, ll starboard_len, std::vector<std::string> &directions);
  bool IsExists(std::size_t i, ll port_len, ll starboard_len);

  const ll port_len_;
  const ll starboard_len_;
  const std::vector<ll> &cars_;
  std::unordered_map<std::size_t, std::unordered_map<ll, std::unordered_map<ll, ll>>> memo_;
};

Ferry::Ferry(const ll port_len, const ll starboard_len, const std::vector<ll> &cars)
    : port_len_(port_len), starboard_len_(starboard_len), cars_(cars) {
}

ll Ferry::Direct(std::size_t i, ll port_len, ll starboard_len, std::vector<std::string> &directions) {
  if (i >= cars_.size()) {
    return 0;
  }

  if (IsExists(i, port_len, starboard_len)) {
    return memo_[i][port_len][starboard_len];
  }

  if (cars_[i] > port_len && cars_[i] > starboard_len) {
    return 0;
  }

  if (cars_[i] <= port_len && cars_[i] > starboard_len) {
    directions[i] = "port";
    return Direct(i + 1, port_len - cars_[i], starboard_len, directions) + 1;
  }

  if (cars_[i] > port_len && cars_[i] <= starboard_len) {
    directions[i] = "starboard";
    return Direct(i + 1, port_len, starboard_len - cars_[i], directions) + 1;
  }

  auto l = Direct(i + 1, port_len - cars_[i], starboard_len, directions) + 1;
  auto r = Direct(i + 1, port_len, starboard_len - cars_[i], directions) + 1;
  if (l >= r) {
    directions[i] = "port";
    memo_[i][port_len][starboard_len] = l;
  } else {
    directions[i] = "starboard";
    memo_[i][port_len][starboard_len] = r;
  }
  return memo_[i][port_len][starboard_len];
}

FerryInfo Ferry::Direct() {
  std::vector<std::string> directions(cars_.size());
  auto num_loaded = Direct(0, port_len_, starboard_len_, directions);
  directions.resize(static_cast<std::size_t>(num_loaded));
  return {num_loaded, directions};
}

bool Ferry::IsExists(std::size_t i, ll port_len, ll starboard_len) {
  auto find_i_it = memo_.find(i);
  if (find_i_it == memo_.end()) {
    return false;
  }

  const std::unordered_map<ll, std::unordered_map<ll, ll>> &port_len_map = find_i_it->second;
  auto port_len_it = port_len_map.find(port_len);
  if (port_len_it == port_len_map.end()) {
    return false;
  }

  const std::unordered_map<ll, ll> &starboard_len_map = port_len_it->second;
  auto starboard_len_it = starboard_len_map.find(starboard_len);
  if (starboard_len_it == starboard_len_map.end()) {
    return false;
  }

  return true;
}

int main() {
//  ll ferry_len = 98;
//  ll ferry_len = 20;
//  ll ferry_len = 20;
  std::size_t t;
  ll ferry_len = 15, car_len = 0;
  std::vector<ll> cars{
      /*2500,
      3000,
      1000,
      1000,
      1500,
      700,
      800*/

      /*3551,
      8043,
      6203,
      1798,
      1190*/

      /*101,
      207,
      155,
      143,
      512,
      335,
      108,
      977,
      567,
      201,
      188,
      311,
      112*/

      100,
      100,
      200,
      200,
      300,
      300,
      400,
      400,
      500,
      500
  };

  /*auto info = Ferry(ferry_len * 100, ferry_len * 100, cars).Direct();
  std::cout << info.count << std::endl;
  for (const auto &direction : info.directions) {
    std::cout << direction << std::endl;
  }*/

  std::cin >> t;
  for (std::size_t i = 0; i < t; ++i) {
    std::cin >> ferry_len;
    cars.clear();
    while (std::cin >> car_len, car_len) {
      cars.emplace_back(car_len);
    }

    if (i > 0) {
      std::cout << std::endl;
    }

    auto info = Ferry(ferry_len * 100, ferry_len * 100, cars).Direct();
    std::cout << info.count << std::endl;
    for (const auto &direction : info.directions) {
      std::cout << direction << std::endl;
    }
  }
  return 0;
}