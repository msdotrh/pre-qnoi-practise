// #include <@msr.h>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <random>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
template <typename T> using vec = vector<T>;
using ll = long long;
namespace r = ranges;
char el = '\n';
#define int ll

void open(string inp, string out) {
  string x = inp + ".inp";
  string y = out + ".out";
  freopen(x.c_str(), "r", stdin);
  freopen(y.c_str(), "w", stdout);
}

void io() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

int t = 1;
int MAX = 1e18;
int MIN = -MAX;

void solve() {
  mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  int n;
  cin >> n;
  vec<int> a(n);
  vec<int> b(n);
  unordered_map<int, int> hash;
  for (int &x : a) {
    cin >> x;
    if (hash.contains(x)) {
      continue;
    }
    auto random = rng();
    hash[x] = random;
  }
  for (int &x : b) {
    cin >> x;
    if (hash.contains(x)) {
      continue;
    }
    int random = rng();
    hash[x] = random;
  }

  int Xor = 0;

  vec<int> p1(n + 1, 0);
  vec<int> p2(n + 1, 0);

  unordered_set<int> st1, st2;

  for (int i = 1; i <= n; i++) {
    if (st1.contains(a[i - 1])) {
      p1[i] = p1[i - 1];
    } else {
      st1.insert(a[i - 1]);
      p1[i] = p1[i - 1] ^ hash[a[i - 1]];
    }

    if (st2.contains(b[i - 1])) {
      p2[i] = p2[i - 1];
    } else {
      st2.insert(b[i - 1]);
      p2[i] = p2[i - 1] ^ hash[b[i - 1]];
    }
  }

  cout << el;
  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (p1[x] == p2[y]) {
      cout << "Yes" << el;
    } else {
      cout << "No" << el;
    }
  }
}

signed main() {
  io();
  // cin >> t;
  while (t--) {
    solve();
  }
}
