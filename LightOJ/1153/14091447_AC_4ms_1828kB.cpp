/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define inf 11234567

//struct maxFlowDinich {
    static const int MX_N = 102;
    int nodes, src, snk, dist[MX_N], start[MX_N];

    struct Edge {
      int nxt, flow, cap, rev;
    };
    vector<Edge> G[MX_N];

    void initialize( int _n ) {
      nodes = _n;
      for(int i=0; i<=nodes; i++) G[i].clear();
    }
    void addEdge( int u, int v, int w ) {
      Edge p = { v, 0, w, (int)G[v].size() };
      Edge q = { u, 0, w, (int)G[u].size() };
      G[u].push_back( p );
      G[v].push_back( q );
    }
    bool bfs() {
      memset(dist, -1, sizeof dist);
      queue<int> Q; Q.push(src), dist[src] = 0;

      while( !Q.empty() ) {
        int u = Q.front(); Q.pop();
        for(int i=0; i<(int)G[u].size(); i++) {
          Edge& e = G[u][i];
          int v = e.nxt;
          if( dist[v]==-1 && e.flow<e.cap ) {
            dist[v] = dist[u] + 1;
            Q.push(v);
          }
        }
      }
      return ~dist[snk];
    }
    int dfs( int u, int f ) {
      if( u==snk ) return f;
      for(int& i=start[u]; i<(int)G[u].size(); i++) {
        Edge& e = G[u][i];
        if( e.flow>=e.cap ) continue;
        int v = e.nxt;
        if( dist[v]==dist[u]+1 ) {
          int _f = dfs( v, min(f, e.cap-e.flow) );
          if( _f>0 ) {
            e.flow += _f;
            G[v][e.rev].cap -= _f;
            return _f;
          }
        }
      }
      return 0;
    }
    int maximumFlow( int _s, int _t ) {
      src = _s, snk = _t;
      int res = 0;
      while( bfs() ) {
        memset(start, 0, sizeof start);
        while( int f = dfs( src, inf ) )
          res += f;
      }
      return res;
    }
//} MF;

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    int n, s, t, e;
    scanf("%d %d %d %d", &n, &s, &t, &e);
    initialize( n );
    for(int i=1, u, v, w; i<=e; i++) {
      scanf("%d %d %d", &u, &v, &w);
      addEdge( u, v, w );
    }
    int res = maximumFlow( s, t );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
