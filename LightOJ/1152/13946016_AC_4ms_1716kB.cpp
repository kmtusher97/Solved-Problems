/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 456

const int MX = 22, inf = 11234567;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
int n, g, r, c, mm[MX][MX][2];
char a[MX][MX];

struct hopcroftKarp
{
  int N, dist[MX_N], match[MX_N];
  vector<int> G[MX_N];

  void initialize( int x )
  {
    N = x;
    for(int i=0; i<MX_N; i++)
      match[i] = 0, G[i].clear();
  }
  bool bfs()
  {
    queue<int> Q; dist[0] = inf;
    for(int i=1; i<=N; i++)
    {
      if( match[i] ) dist[i] = inf;
      else Q.push(i), dist[i] = 0;
    }
    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      if( !u ) continue;
      for(int i=0, sz=G[u].size(); i<sz; i++)
      {
        int v = G[u][i];
        if( dist[match[v]]!=inf ) continue;
        dist[match[v]] = dist[u] + 1;
        Q.push( match[v] );
      }
    }
    return dist[0]!=inf;
  }
  bool dfs( int u )
  {
    if( u )
    {
      for(int i=0, sz=G[u].size(); i<sz; i++)
      {
        int v = G[u][i];
        if( dist[match[v]]==dist[u] + 1 )
        {
          if( dfs( match[v] ) )
          {
            match[v] = u;
            match[u] = v;
            return true;
          }
        }
      }
      dist[u] = inf;
      return false;
    }
    return true;
  }
  int maximumMatch()
  {
    int ret = 0;
    while( bfs() )
    {
      for(int i=1; i<=N; i++)
      {
        if( !match[i] && dfs( i ) ) ret++;
      }
    }
    return ret;
  }
} HP;

int main()
{
  for(int i=1; i<MX; i++)
  {
    for(int j=1; j<MX; j++)
    {
      if( i&1 ) mm[i][j][0] = (j&1) ? 1 : 0;
      else mm[i][j][0] = (j&1) ? 0 : 1;
    }
  }
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &r, &c), n = g = 0;
    getchar();
    for(int i=1, cn1=0, cn2=0; i<=r; i++)
    {
      for(int j=1; j<=c; j++)
      {
        scanf("%c", &a[i][j]);
        n += mm[i][j][0];
        mm[i][j][1] = mm[i][j][0] ? ++cn1 : ++cn2;
      }
      getchar();
    }
    HP.initialize( n );
    for(int i=1, cn1=0, cn2=0; i<=r; i++)
    {
      for(int j=1; j<=c; j++)
      {
        if( a[i][j]!='*' ) continue;
        for(int k=0; k<4; k++)
        {
          int x = i + dx[k];
          int y = j + dy[k];
          if( x<1 || y<1 || x>r || y>c || a[x][y]!='*' ) continue;
          int u = mm[i][j][1] + ( !mm[i][j][0] ? n : 0 );
          int v = mm[x][y][1] + ( !mm[x][y][0] ? n : 0 );
          if( u<=n ) HP.G[u].push_back(v);
        }
        g++;
      }
    }
    int mtch = HP.maximumMatch();
    printf("Case %d: %d\n", ++caseno, mtch + (g - 2*mtch));
  }
  return 0;
}
