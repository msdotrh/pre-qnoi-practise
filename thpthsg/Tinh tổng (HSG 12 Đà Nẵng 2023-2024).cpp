// #include <@msr.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
char el = '\n';
#define int ll

string s;
pair<int, int> memo[11][11][2][2];
bool visited[11][11][2][2];

pair<int, int> dp(int curr, int prev, bool tight, bool lead) {
  if (curr == s.size()) {
    return {1, 0};
  }
  int l = 0;
  int r = tight ? s[curr] - '0' : 9;
  int cnt = 0;
  int sum = 0;
  auto &mem = memo[curr][prev][tight][lead];
  bool &state = visited[curr][prev][tight][lead];
  if (state)
    return mem;
  for (int i = l; i <= r; i++) {
    bool neuetight = tight && (i == s[curr] - '0');
    bool neuelead = (lead && i == 0);
    auto [f, sum2] = dp(curr + 1, i, neuetight, neuelead);
    cnt += f;
    sum += sum2 + i * f;
  }
  state = 1;
  return mem = make_pair(cnt, sum);
}

int dp(int x) {
  s = to_string(x);
  memset(visited, 0, sizeof(visited));
  pair<int, int> ans = dp(0, 10, 1, 1);
  return ans.second;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  freopen("TONG.INP", "r", stdin);
  freopen("TONG.OUT", "w", stdout);
  int n;
  cin >> n;
  cout << n * (n - 1) / 2 << el;
}
