/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;
typedef unsigned long long intu;

const int MX = 200;
int n, m, M[MX][MX];
string G[MX];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool valid( int x, int y )
{
  return ( x>=0 && x<n && y>=0 && y<m );
}

void bfs( int x, int y )
{
  queue<int> q;
  q.push(x), q.push(y);

  while( !q.empty() )
  {
    int ux = q.front(); q.pop();
    int uy = q.front(); q.pop();
    for(int i=0; i<4; i++)
    {
      int vx = ux+dx[i];
      int vy = uy+dy[i];
      if( valid( vx, vy ) && G[vx][vy]!='1' && M[vx][vy]>M[ux][uy]+1 )
      {
        M[vx][vy] = M[ux][uy]+1;
        q.push(vx), q.push(vy);
      }
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>G[i];

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
      {
        if( G[i][j]=='1' ) M[i][j] = 0;
        else M[i][j] = INT_MAX;
      }
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        if( G[i][j]=='0' ) continue;
        bfs( i, j );
      }
    }

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        cout<<M[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
