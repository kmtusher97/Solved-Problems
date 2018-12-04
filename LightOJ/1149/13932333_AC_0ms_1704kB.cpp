/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 205

int n, m, a[MX_N], b[MX_N];

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
    queue<int> Q; dist[0] = INT_MAX;
    for(int i=1; i<=N; i++)
    {
      if( !match[i] ) Q.push(i), dist[i] = 0;
      else dist[i] = INT_MAX;
    }
    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      if( !u ) continue;
      for(int i=0; i<G[u].size(); i++)
      {
        int v = G[u][i];
        if( dist[match[v]]!=INT_MAX ) continue;
        dist[match[v]] = dist[u] + 1;
        Q.push( match[v] );
      }
    }
    return dist[0]!=INT_MAX;
  }
  bool dfs( int u )
  {
    if( u )
    {
      for(int i=0; i<G[u].size(); i++)
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
      dist[u] = INT_MAX;
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
        if( !match[i] && dfs( i ) ) cnt++;
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
    scanf("%d", &n); for(int i=1; i<=n; i++) scanf("%d", a+i);
    scanf("%d", &m); for(int i=1; i<=m; i++) scanf("%d", b+i);
    HP.initialize( n );
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if( b[j]%a[i]==0 )
        {
          HP.G[i].push_back(n+j);
          HP.G[n+j].push_back(i);
        }
      }
    }
    int res = HP.maximumMatch();
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
