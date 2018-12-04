/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 17;
int n, a[MX][MX], ff[MX][1<<MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=n; j++)
      {
        scanf("%d", &a[i][j]);
      }
    }
    memset(ff, -1, sizeof ff);
    for(int i=1; i<=n; i++)
    {
      ff[1][1<<(i-1)] = a[1][i];
    }
    for(int i=2; i<=n; i++)
    {
      for(int mask=0; mask<(1<<n); mask++)
      {
        if( ff[i-1][mask]==-1 ) continue;
        for(int j=1; j<=n; j++)
        {
          if( mask&(1<<(j-1)) ) continue;
          ff[i][mask|(1<<(j-1))] = max(ff[i][mask|(1<<(j-1))], a[i][j]+ff[i-1][mask]);
        }
      }
    }
    printf("Case %d: %d\n", ++caseno, ff[n][(1<<n)-1]);
  }
  return 0;
}
