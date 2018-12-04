/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 202;
int n, m, d, Q, a[MX];
intl ff[MX][22][12];

intl dp( int pos, intl rmndr, int rest )
{
  if( rest<0 ) return 0LL;
  if( !pos )
  {
    if( !rest && !rmndr ) return 1LL;
    return 0LL;
  }
  if( ~ff[pos][rmndr][rest] ) return ff[pos][rmndr][rest];
  return ff[pos][rmndr][rest] = dp( pos-1, ((rmndr+a[pos])%d+d)%d, rest-1 ) + dp( pos-1, rmndr, rest );
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &Q);
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      scanf("%d %d", &d, &m);
      memset(ff, -1, sizeof ff);
      printf("%lld\n", dp( n, 0, m ));
    }
  }
  return 0;
}
