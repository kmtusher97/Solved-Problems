/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 55

typedef long long intl;

const int MX = 52;
int n, K, m;
intl ff[MX_N][MX_N][MX_N];

intl dp( int pos, int sec, int mx )
{
  if( sec<0 ) return 0LL;
  if( pos==0 ) return (!sec) ? 1LL : 0LL;
  intl& ret = ff[pos][sec][mx];
  if( ~ret ) return ret;

  intl temp = 0LL;
  for(int i=1; i<=mx; i++)
  {
    if( pos-i<0 ) break;
    temp += dp( pos-i, sec-1, mx );
  }
  return ff[pos][sec][mx] = temp;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  memset(ff, -1, sizeof ff);
  while( cases-- )
  {
    scanf("%d %d %d", &n, &K, &m);
    printf("Case %d: %lld\n", ++caseno, dp( n, K, m ));
  }
  return 0;
}
