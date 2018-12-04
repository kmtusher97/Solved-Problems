/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 205
int n, a[MX_N], ff[MX_N][MX_N][MX_N];

int dp( int pos, int lasti, int lastj ) {
  if( pos==n ) return 0;
  int& ret = ff[pos][lasti][lastj];
  if( ~ret ) return ret;

  ret = 1 + dp( pos+1, lasti, lastj );
  if( a[pos] > a[lasti] )
    ret = min( ret, dp( pos+1, pos, lastj ) );
  if( a[pos] < a[lastj] )
    ret = min( ret, dp( pos+1, lasti, pos ) );

  return ff[pos][lasti][lastj] = ret;
}

int main() {
  while( scanf("%d", &n) && ~n ) {
    for(int i=2; i<n+2; i++)
      scanf("%d", a+i);
    a[0] = INT_MIN, a[1] = INT_MAX, n += 2;

    memset(ff, -1, sizeof ff);
    int res = dp( 2, 0, 1 );
    printf("%d\n", res);
  }
  return 0;
}
