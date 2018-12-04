/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 102
const int inf = 1234567;
int n, a[MX_N], ff[MX_N][MX_N];

int dfs( int l, int r ) {
  if( l>r ) return 0;
  int& ret = ff[l][r];
  if( ~ret ) return ret;

  int sum = 0; ret = -inf;
  for(int i=l; i<=r; i++) {
    sum += a[i];
    ret = max(ret, sum - dfs( i+1, r ));
  }
  sum = 0;
  for(int i=r; i>=l; i--) {
    sum += a[i];
    ret = max(ret, sum - dfs( l, i-1 ));
  }
  return ff[l][r] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    memset(ff, -1, sizeof ff);
    printf("Case %d: %d\n", ++caseno, dfs( 1, n ));
  }
  return 0;
}
