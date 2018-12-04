/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 102;
int n, w, k, y[MX], ff[MX][MX];

int dp( int i, int j )
{
  if( i>n ) return 0;
  if( ff[i][j]!=-1 ) return ff[i][j];

  int tmp = 0;
  if( j>0 )
  {
    int lo = i, hi = n;
    while( lo<=hi )
    {
      int mid = lo+(hi-lo)/2;
      if( y[mid]>y[i]+w ) hi = mid-1;
      else lo = mid+1;
    }
    tmp = lo-i + dp( lo, j-1 );
  }
  return ff[i][j] = max( tmp, dp( i+1, j ) );
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &n, &w, &k);
    for(int i=1; i<=n; i++) scanf("%d %d", y+i, y+i);

    sort(y+1, y+n+1);
    memset(ff, -1, sizeof ff);
    printf("Case %d: %d\n", ++caseno, dp( 1, k ));
  }
  return 0;
}
