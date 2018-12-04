/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 17;
int n, a[MX][MX], ff[1<<MX];

int dp( int men, int mask )
{
  if( men>n ) return 0LL;

  int &ret = ff[mask];
  if( ret!=-1 ) return ff[mask];

  ret = 0LL;
  for(int i=1; i<=n; i++)
  {
    if( mask&(1<<(i-1)) ) continue;
    ret = max(ret, a[men][i] + dp( men+1, mask|(1<<(i-1)) ) );
  }
  return ret;
}

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
    printf("Case %d: %d\n", ++caseno, dp( 1, 0 ));
  }
  return 0;
}
