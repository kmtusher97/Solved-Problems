/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
 
typedef long long intl;
#define MX_N 62
intl n, ff[MX_N][MX_N];
char s[MX_N];
 
intl dp( int l, int r ) {
  if( l>r ) return 0;
  intl& ret = ff[l][r];
  if( ~ret ) return ret;
 
  ret = 0;
  if( s[l]==s[r] ) ret += ( 1 + dp( l+1, r-1 ) );
  ret += ( dp(l+1, r) + dp( l, r-1 ) - dp( l+1, r-1 ) );
  return ff[l][r] = ret;
}
 
int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    n = strlen(s);
    memset(ff, -1, sizeof ff);
    printf("Case %d: %lld\n", ++caseno, dp( 0, n-1 ));
  }
  return 0;
}
 