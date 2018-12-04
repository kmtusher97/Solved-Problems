/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long intl;
typedef pair<int, int> pii;
#define MX_N 40050
int n, a[MX_N];
intl tt[3 * MX_N];
pii b[MX_N];

void update( int idx, int v ) {
  for(; idx < MX_N; tt[idx] += v, idx += (idx & (-idx)));
}

intl query( int idx ) {
  intl sum = 0;
  for(; idx > 0; sum += tt[idx], idx -= (idx & (-idx)));
  return sum;
}

int main() {
  int caseno = 0;
  while( ~scanf("%d", &n) && n ) {
    for(int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      b[i] = {a[i], i};
    }
    sort(b + 1, b + n + 1);
    for(int i = 1, j = 1; i <= n; i++) {
      if( i > 1 && b[i - 1].F != b[i].F ) j++;
      a[b[i].S] = j;
    }

    intl res = 0;
    memset(tt, 0, sizeof tt);
    for(int i = n; i > 0; i--) {
      res += query( a[i] - 1 );
      update( a[i], 1 );
    }
    memset(tt, 0, sizeof tt);
    for(int i = 1; i <= n; i++) {
      res += query( a[i] - 1 );
      update( a[i], 1 );
    }
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
