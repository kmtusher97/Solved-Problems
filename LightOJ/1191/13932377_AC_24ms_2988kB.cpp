/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 55

typedef long long intl;

const int MX = 52;
int n, K, m;
intl ff[MX_N][MX_N][MX_N];

int main()
{
  for(int i=0; i<=MX; i++) ff[0][0][i] = 1LL;
  for(int i=1; i<=MX; i++)
  {
    for(int j=1; j<=MX; j++)
    {
      for(int k=1; k<=MX; k++)
      {
        for(int l=1; l<=k; l++)
        {
          if( i-l<0 ) break;
          ff[i][j][k] += ff[i-l][j-1][k];
        }
      }
    }
  }
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &n, &K, &m);
    printf("Case %d: %lld\n", ++caseno, ff[n][K][m]);
  }
  return 0;
}
