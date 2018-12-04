/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const intl mod = 100000007;
int n, K, c[51], t[51], ff[51][1001];

int dp( int pos, int value )
{
  if( pos==n+1 )
  {
    if( value==0 ) return 1;
    return 0;
  }
  if( ff[pos][value]!=-1 ) return ff[pos][value]%mod;

  ff[pos][value] = 0;
  for(int i=0; i<=t[pos]; i++)
  {
    if( c[pos]*i>value ) break;
    ff[pos][value] = (ff[pos][value] + dp( pos+1, value - (c[pos]*i)) ) % mod;
  }
  return ff[pos][value]%mod;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &K);
    for(int i=1; i<=n; i++) scanf("%d", c+i);
    for(int i=1; i<=n; i++) scanf("%d", t+i);

    memset(ff, -1, sizeof ff);
    printf("Case %d: %d\n", ++caseno, dp( 1, K ));
  }
  return 0;
}
