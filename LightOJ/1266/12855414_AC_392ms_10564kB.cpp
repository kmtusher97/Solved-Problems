/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;
typedef pair<int, int> pii;

const int MX = 1005;
int Q;
intl BIT[MX][MX];
bool mark[MX][MX];

void update( int x, int y, int v )
{
  for(int i=x; i<MX; i+=(i&-i))
  {
    for(int j=y; j<MX; j+=(j&-j))
    {
      BIT[i][j] += v;
    }
  }
}

intl query( int x, int y )
{
  intl sm = 0LL;
  for(int i=x; i>0; i-=(i&-i))
  {
    for(int j=y; j>0; j-=(j&-j))
    {
      sm += BIT[i][j];
    }
  }
  return sm;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &Q);
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      int t, x, y;
      scanf("%d %d %d", &t, &x, &y);
      if( t==0 )
      {
        x++, y++;
        if( !mark[x][y] )
        {
          update( x, y, 1 );
          mark[x][y] = true;
        }
      }
      else
      {
        int x1, y1;
        scanf("%d %d", &x1, &y1);
        x++, y++, x1++, y1++;
        intl ans = query( x1, y1 ) + query( x-1, y-1);
        ans -= ( query( x-1, y1 ) + query( x1, y-1 ) );
        printf("%lld\n", ans);
      }
    }

    for(int i=0; i<MX; i++)
    {
      for(int j=0; j<MX; j++)
      {
        mark[i][j] = false; BIT[i][j] = 0;
      }
    }
  }
  return 0;
}
