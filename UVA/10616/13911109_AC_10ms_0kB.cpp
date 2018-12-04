/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 202;
int n, m, d, Q, a[MX];
intl ff[2][22][12];

int main()
{
  int caseno = 0;
  while( scanf("%d %d", &n, &Q)==2 && n && Q )
  {
    for(int i=1; i<=n; i++) scanf("%d", a+i);
    printf("SET %d:\n", ++caseno);
    for(int q=0; q<Q; q++)
    {
      scanf("%d %d", &d, &m);
      memset(ff, 0, sizeof ff);
      ff[0][0][0] = ff[1][0][0] = 1LL;
      int now = 0;
      for(int i=1; i<=n; i++)
      {
        now ^= 1;
        for(int k=1; k<=m; k++)
        {
          for(intl j=0; j<d; j++)
          {
            ff[now][j][k] = ff[now^1][((j+a[i])%d+d)%d][k-1] + ff[now^1][j][k];
          }
        }
      }
      printf("QUERY %d: %lld\n", q+1, ff[now][0][m]);
    }
  }
  return 0;
}
