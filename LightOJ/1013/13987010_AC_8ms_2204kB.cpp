/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

#define MX_N 32

typedef long long intl;

char a[MX_N], b[MX_N];
int n, m, N, ff[MX_N][MX_N];
intl ff1[MX_N*2][MX_N][MX_N];

intl dfs( int pos, int i, int j ) {
  if( !pos ) return ( !i && !j );
  intl& ret = ff1[pos][i][j];
  if( ~ret ) return ret;

  ret = 0LL;
  if( a[i-1]==b[j-1] ) ret = dfs( pos-1, i-1, j-1 );
  else ret = ( dfs( pos-1, i-1, j ) + dfs( pos-1, i, j-1 ) );
  return ff1[pos][i][j] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s %s", a, b);
    n = strlen(a), m = strlen(b);
    memset(ff, 0, sizeof ff);
    for(int i=n; i>0; i--) {
      for(int j=m; j>0; j--) {
        if( a[i-1]==b[j-1] ) ff[i-1][j-1] = 1 + ff[i][j];
        else ff[i-1][j-1] = max( ff[i-1][j], ff[i][j-1] );
      }
    }
    N = m+n-ff[0][0];
    memset(ff1, -1, sizeof ff1);
    intl res = dfs( N, n, m );
    printf("Case %d: %d %lld\n", ++caseno, N, res);
  }
  return 0;
}