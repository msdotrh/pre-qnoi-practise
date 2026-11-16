import std;
using namespace std;

char el = '\n';

int main() {
  vector<int> a;
  for (int x : views::iota(1, 10)) {
    a.push_back(x);
  }
  for (int x : a | ranges::views::transform([](int x) { return x * 2; })) {
    cout << x << " ";
  }
  cout << el;
}
