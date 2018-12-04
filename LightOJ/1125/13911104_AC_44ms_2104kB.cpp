/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 202;
int n, m, d, Q, a[MX];
intl ff[MX][22][12];

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
      memset(ff, 0, sizeof ff);
      for(int i=0; i<=n; i++) ff[i][0][0] = 1LL;
      for(int i=1; i<=n; i++)
      {
        for(int k=1; k<=m; k++)
        {
          for(intl j=0; j<d; j++)
          {
            ff[i][j][k] = ff[i-1][((j+a[i])%d+d)%d][k-1] + ff[i-1][j][k];
          }
        }
      }
      printf("%lld\n", ff[n][0][m]);
    }
  }
  return 0;
}
