// #include <@msr.h>
#include <iostream>
#include <print>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
// #define int ll

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mp;
    vector<int> res{0, 0};
    for (int i = 0; i < nums.size(); i++) {
      int need = target - nums[i];
      if (mp.contains(need)) {
        res = {i, mp[need]};
      } else {
        mp[nums[i]] = i;
      }
    }
    return res;
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solution sol;
  vec<int> data{3, 2, 4};
  println("{}", sol.twoSum(data, 6));
}
