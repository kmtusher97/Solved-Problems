/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef queue<int> qi;
typedef vector<int> vi;

const int inf = 11234567;
const int MX = 123;
int n, m, a[MX], b[MX];

struct Hopcroft
{
  static const int MX1 = 202;
  int N, match[MX1], dist[MX1];
  vi G[MX1];

  void initialize( int _n )
  {
    N = _n;
    for(int i=0; i<MX1; i++) match[i] = 0, G[i].clear();
  }
  bool bfs()
  {
    qi Q; dist[0] = inf;
    for(int i=1; i<=N; i++)
    {
      if( match[i]==0 ) dist[i] = 0, Q.push(i);
      else dist[i] = inf;
    }
    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      if( !u ) continue;
      for(int i=0; i<G[u].size(); i++)
      {
        int v = G[u][i];
        if( dist[match[v]]!=inf ) continue;
        dist[match[v]] = dist[u]+1, Q.push(match[v]);
      }
    }
    return dist[0]!=inf;
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
      dist[u] = inf;
      return false;
    }
    return true;
  }
  int MxBPM()
  {
    int cnt = 0;
    while( bfs() )
    {
      for(int i=1; i<=N; i++)
      {
        if( match[i]==0 && dfs( i ) ) cnt++;
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
        if( b[j]%a[i] ) continue;
        HP.G[i].pb(j+n);
        HP.G[j+n].pb(i);
      }
    }
    int res = HP.MxBPM();
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
