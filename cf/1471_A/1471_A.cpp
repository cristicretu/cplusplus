#include <bits/stdc++.h>

class Read {
 public:
  template <class T>
  Read& operator>>(T& number) {
    bool negative = false;
    register int c;
    number = 0;
    c = getchar();
    if (c == '-') {
      negative = true;
      c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
    if (negative) number *= -1;
    return *this;
  }
};
Read cin;
int main() {
  std::ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, x, mn(0), mx(0);
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      mn += (a / x);
      mx += (a / x + 1);
    }
    std::cout << mn << ' ' << mx << '\n';
  }
  return 0;
}
