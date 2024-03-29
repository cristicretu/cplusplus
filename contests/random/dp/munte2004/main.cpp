/*
  2    4    8    7    9    3
a[1] a[2] a[3] a[4] a[5] a[6]

  1    2    3    3    4    2
L[1] L[2] L[3] L[4] L[5] L[6] -> 2, 4, 8, 9 sau 2, 4, 7, 9

  4    3    2    2    1    1
R[1] R[2] R[3] R[4] R[5] R[6] -> 9, 8, 4, 2 sau 9, 7, 4, 2

L[i]: cmlsc [1..i]
R[i]: cmlsc [i..n]
sol: n - max(L[i] + R[i])
*/
#include <fstream>
#include <iostream>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  ifstream fin("mountain.in");
  ofstream fout("mountain.out");
#endif

using ll = long long;
#define mod 1000000007

const int maxN = 1e4 + 1;

int a[maxN];
int L[maxN], R[maxN];

int D[maxN]; // D[j] - elementul din a in care se termina subsirul de lung j
int n, lung;

void solve();
void read();
void cmlscL();
void cmlscR();
int cbin(int x);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll test=1;
  //cin>>test;

  while(test--)
  {
    solve();
  }

  return 0;
}


void solve() {
  read();
  lung = 0;
  cmlscL();
  lung = 0;
  cmlscR();

  int mx = -1;
  for (int i = 1; i <= n; ++i) {
    int sum = L[i] + R[i];
    mx = max(mx, sum);
  }

  cerr << n << ' ' << mx << '\n';
  fout << n - mx;
}

int cbin(int x) {
  if (D[lung] <= x) return lung + 1;
  int lb = 1, rb = lung;
  int ans(0);
  while (lb <= rb) {
    int mb = (lb + (rb - lb) / 2);

    if (D[mb] > x) {
      ans = mb;
      rb = mb - 1;
    } else {
      lb = mb + 1;
    }
  }

  return ans;
}

void cmlscL() {
  for (int i = 1; i <= n; ++i) {
    int poz = cbin(a[i]);
    if (poz > lung) {
      lung ++;
      poz = lung;
    }

    D[poz] = a[i];
    L[i] = poz;
  } 
}

void cmlscR() {
  for (int i = n; i; --i) {
    int poz = cbin(a[i]);
    if (poz > lung) {
      lung ++;
      poz = lung;
    }

    R[i] = poz;
    D[poz] = a[i];
  }
}

void read() {
  char c;
  n = 0;
  while (fin >> c) {
    a[++n] = c - '0';
  }
}
