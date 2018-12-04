/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const intl mod = 100000007;
int N, K, S, ff[2][15002];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &N, &K, &S);
    memset(ff, 0, sizeof ff);
    ff[0][0] = 1;
    int now = 0;
    for(int i=1; i<=N; i++)
    {
      now ^= 1;
      int tmp = 0;
      ff[now][0] = 0;
      for(int j=1; j<=S; j++)
      {
        if( j<=K ) tmp = (tmp%mod + ff[now^1][j-1]%mod)%mod;
        else tmp = (tmp%mod + ff[now^1][j-1]%mod - ff[now^1][j-K-1]%mod + mod)%mod;
        ff[now][j] = tmp%mod;
      }
    }
    printf("Case %d: %d\n", ++caseno, ff[now][S]);
  }
  return 0;
}
