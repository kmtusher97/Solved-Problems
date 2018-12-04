/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 102;
int n, w, k, y[MX], ff[MX][MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &n, &w, &k);
    for(int i=1; i<=n; i++) scanf("%d %d", y+i, y+i);

    sort(y+1, y+n+1);
    memset(ff, 0, sizeof ff);
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=k; j++)
      {
        int lo = 1, hi = i;
        while( lo<=hi )
        {
          int mid = lo+(hi-lo)/2;
          if( y[mid]<y[i]-w ) lo = mid+1;
          else hi = mid-1;
        }
        ff[i][j] = max( i-lo+1 + ff[lo-1][j-1], ff[i-1][j] );
      }
    }
    printf("Case %d: %d\n", ++caseno, ff[n][k]);
  }
  return 0;
}
