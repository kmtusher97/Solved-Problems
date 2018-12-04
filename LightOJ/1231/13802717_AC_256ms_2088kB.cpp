/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const intl mod = 100000007;
intl n, K, c[51], t[51], ff[51][1001];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%lld %lld", &n, &K);
    for(int i=1; i<=n; i++) scanf("%lld", c+i);
    for(int i=1; i<=n; i++) scanf("%lld", t+i);

    for(int i=0; i<=n; i++)
    {
      for(int j=0; j<=K; j++)
      {
        ff[i][j] = 0LL;
        if( j==0 ) ff[i][j] = 1LL;
      }
    }
    for(int i=1; i<=n; i++)
    {
      for(int j=K; j>0; j--)
      {
        for(int k=0; k<=t[i]; k++)
        {
          if( j>=c[i]*k )
          {
            ff[i][j] = (ff[i][j] + ff[i-1][j-(c[i]*k)])%mod;
          }
        }
      }
    }
    printf("Case %d: %lld\n", ++caseno, ff[n][K]);
  }
  return 0;
}
