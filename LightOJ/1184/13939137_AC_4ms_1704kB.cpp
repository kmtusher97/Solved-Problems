/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 123

const int inf = 11234567;
int m, w, mn[MX_N][3], wmn[MX_N][3];

struct hopcrofKarp
{
  int N, dist[MX_N], match[MX_N];
  vector<int> G[MX_N];

  void initialize( int x )
  {
    N = x;
    for(int i=0; i<MX_N; i++) match[i] = 0, G[i].clear();
  }
  bool bfs()
  {
    queue<int> Q; dist[0] = inf;
    for(int i=1; i<=N; i++)
    {
      if( !match[i] ) Q.push(i), dist[i] = 0;
      else dist[i] = inf;
    }
    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      for(int i=0, sz=G[u].size(); i<sz; i++)
      {
        int v = G[u][i];
        if( dist[match[v]]!=inf ) continue;
        dist[match[v]] = dist[u] + 1;
        Q.push(match[v]);
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
        if( dist[match[v]]==dist[u]+1 )
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
    int cnt = 0;
    while( bfs() )
    {
      for(int i=1; i<=N; i++)
      {
        if( !match[i] && dfs(i) ) cnt++;
      }
    }
    return cnt;
  }
} HP;

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &m, &w);
    for(int i=1; i<=m; i++)
    {
      scanf("%d %d %d", &mn[i][0], &mn[i][1], &mn[i][2]);
    }
    for(int i=1; i<=w; i++)
    {
      scanf("%d %d %d", &wmn[i][0], &wmn[i][1], &wmn[i][2]);
    }

    HP.initialize( m );
    for(int i=1; i<=m; i++)
    {
      for(int j=1; j<=w; j++)
      {
        if( mn[i][2]==wmn[j][2] && abs(mn[i][0]-wmn[j][0])<=12 && abs(mn[i][1]-wmn[j][1])<=5 )
        {
          HP.G[i].push_back(m+j);
          HP.G[m+j].push_back(i);
        }
      }
    }
    printf("Case %d: %d\n", ++caseno, HP.maximumMatch());
  }
  return 0;
}
