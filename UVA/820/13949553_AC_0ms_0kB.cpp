/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */

#include <bits/stdc++.h>
using namespace std;

struct maxFlow_dinic
{
  static const int MX_N = 223;
  int nodes, src, dest, dist[MX_N], work[MX_N];

  struct edge
  {
    int to, rev, f, cap;
    edge() { to = rev = f = cap = 0; }
    edge( int _t, int _r, int _f, int _c )
    {
      to = _t, rev = _r, f = _f, cap = _c;
    }
  };
  vector<edge> G[MX_N];

  void init( int _n )
  {
    nodes = _n;
    for(int i=0; i<MX_N; i++) G[i].clear();
  }

  void add_edge( int i, int j, int k )
  {
    edge p = edge(j, G[j].size(), 0, k);
    edge q = edge(i, G[i].size(), 0, k);
    G[i].push_back(p);
    G[j].push_back(q);
  }

  bool bfs()
  {
    memset(dist, -1, sizeof dist);
    queue<int> Q;
    Q.push(src), dist[src] = 0;

    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      for(int i=0; i<(int)G[u].size(); i++)
      {
        edge& e = G[u][i];
        int v = e.to;
        if( dist[v]==-1 && e.f<e.cap )
        {
          dist[v] = dist[u] + 1;
          Q.push(v);
        }
      }
    }
    return ~dist[dest];
  }

  int dfs( int u, int f )
  {
    if( u==dest ) return f;
    for(int i=work[u]; i<(int)G[u].size(); i++)
    {
      edge& e = G[u][i];
      int v = e.to;
      if( e.f>=e.cap ) continue;
      if( dist[v]==dist[u] + 1 )
      {
        int _f = dfs( v, min(f, e.cap-e.f) );
        if( _f>0 )
        {
          e.f += _f;
          G[v][e.rev].f -= _f;
          return _f;
        }
      }
    }
    return 0;
  }

  int maxFlow( int s, int d )
  {
    src = s, dest = d;
    int ret = 0;
    while( bfs() )
    {
      memset(work, 0, sizeof work);
      while( int tmp = dfs( src, INT_MAX ) )
      {
        ret += tmp;
      }
    }
    return ret;
  }
} flow;

int main()
{
  int n, m, s, t, caseno = 0;
  while( scanf("%d", &n) && n )
  {
    scanf("%d %d %d", &s, &t, &m);
    flow.init( n );
    for(int i=1, u, v, c; i<=m; i++)
    {
      scanf("%d %d %d", &u, &v, &c);
      flow.add_edge( u, v, c );
    }
    printf("Network %d\n", ++caseno);
    printf("The bandwidth is %d.\n\n", flow.maxFlow( s, t ));
  }
  return 0;
}
