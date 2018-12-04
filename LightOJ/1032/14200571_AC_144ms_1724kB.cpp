/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 33;
intl n, ff[MX][2][2][MX];
bitset<MX> num;

intl dfs( int pos, int chk, int last, int sum ) {
  if( pos==-1 ) return sum;
  intl& ret = ff[pos][chk][last][sum];
  if( ~ret ) return ret;

  ret = 0;
  if( chk ) {
    for(int bit=0; bit<2; bit++)
      ret += dfs( pos-1, 1, bit, sum+(last&bit) );
  }
  else {
    for(int bit=0; bit<num[pos]; bit++)
      ret += dfs( pos-1, 1, bit, sum+(last&bit) );
    ret += dfs( pos-1, 0, num[pos], sum+(last&num[pos]) );
  }
  return ff[pos][chk][last][sum] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%lld", &n);
    num = n;
    memset(ff, -1, sizeof ff);
    intl res = dfs( 32, 0, 0, 0 );
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
