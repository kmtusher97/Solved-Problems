/*  ~BISMILLAHIR RAHMANIR RAHIM~  */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define MX_N 1002

vector<int> C[MX_N];

void preprocess() {
  C[1].push_back(0);

  for(int m = 2; m < MX_N; m++) {
    C[m].push_back(0);
    C[m].push_back(1);
    for(int rgt = 2; ; rgt++) {
      C[m].push_back((C[m][rgt - 2] + C[m][rgt - 1]) % m);
      if( C[m][rgt] == 1 and C[m][rgt - 1] == 0 ) {
        C[m].pop_back();
        C[m].pop_back();
        break;
      }
    }
  }
}

ull big_mod( ull b, ull p, ull mod ) {
  ull x = 1;
  for(; p > 0; p /= 2) {
    if( p & 1 ) x = (b % mod * x % mod) % mod;
    b = (b % mod * b % mod) % mod;
  }
  return x % mod;
}

int main() {
  preprocess();

  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    ull a, b, n;
    scanf("%llu %llu %llu", &a, &b, &n);
    ull nth = big_mod( a % (ull)C[n].size(), b, C[n].size() );
    printf("%d\n", C[n][nth]);
  }
  return 0;
}
