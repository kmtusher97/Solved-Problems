/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const intl mod = 100000007;
intl n, K, c[51], t[51], ff[51][1001];

intl dp( int pos, int value )
{
  if( pos==n+1 )
  {
    if( value==0 ) return 1;
    return 0;
  }
  intl& ret = ff[pos][value];
  if( ~ret ) return ret;

  intl tmp = 0;
  for(int i=0; i<=t[pos]; i++)
  {
    if( c[pos]*i>value ) break;
    tmp = (tmp + dp( pos+1, value - (c[pos]*i)) ) % mod;
  }
  return ff[pos][value] = tmp%mod;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%lld %lld", &n, &K);
    for(int i=1; i<=n; i++) scanf("%lld", c+i);
    for(int i=1; i<=n; i++) scanf("%lld", t+i);

    memset(ff, -1, sizeof ff);
    printf("Case %d: %lld\n", ++caseno, dp( 1, K ));
  }
  return 0;
}
