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

  int a[10][10], ans = -64;
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j) cin >> a[i][j];

  for (int i = 0; i <= 3; ++i)
    for (int j = 0; j <= 3; ++j) {
      int s = a[i][j] + a[i][j + 1] + a[i][j + 2];
      s += a[i + 1][j + 1] + a[i + 2][j] + a[i + 2][j + 1] + a[i + 2][j + 2];
      if (ans < s) ans = s;
    }
  std::cout << ans;
  return 0;
}
