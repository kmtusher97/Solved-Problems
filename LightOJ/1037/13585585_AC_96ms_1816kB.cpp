/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 15;
int n, h[MX+2], w[MX+2][MX+2], ff[(1<<MX)+2];

int dp( int mask )
{
  if( mask==(1<<n)-1 ) return 0;
  int &ret = ff[mask];
  if(  ret!=-1 ) return ret;

  ret = INT_MAX;
  for(int i=0; i<n; i++)
  {
    if( mask&(1<<i) ) continue;
    int mx = 1;
    for(int j=0; j<n; j++)
    {
      if( !(mask&(1<<j)) ) continue;
      mx = max(mx, w[j][i]);
    }
    ret = min(ret, (h[i]/mx) + (h[i]%mx!=0) + dp( mask|(1<<i) ));
  }
  return ff[mask] = ret;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
      scanf("%d", h+i);
    }
    for(int i=0; i<n; i++)
    {
      char ar[n+2];
      scanf("%s", ar);
      for(int j=0; j<n; j++)
      {
        w[i][j] = ar[j]-'0';
      }
    }
    memset(ff, -1, sizeof ff);
    printf("Case %d: %d\n", ++caseno, dp( 0 ));
  }
  return 0;
}
