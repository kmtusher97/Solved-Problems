/*  ~*BISMILLAHIR RAHMARNIR RAHIM *~  */
#include <bits/stdc++.h>
using namespace std;

#define inf 11234567
#define MX 105
static int nd;
int N, M, B, D, source, sink;
struct data {
  int cap, in, out;
} info[MX];

struct dinich_MaxFlow {
        static const int MX_N = 208;
        int nodes, src, snk, dist[MX_N], start[MX_N];
        struct Edge { int u, v, f, c; };
        vector<Edge> E;
        vector<int> G[MX_N];

        void initialize( int _n ) {
          nodes = _n, E.clear();
          for(int i=0; i<=nodes; i++) G[i].clear();
        }

        void addEdge( int u, int v, int w ) {
          Edge p = { u, v, 0, w };
          Edge q = { v, u, 0, 0 };
          G[u].push_back(E.size()), E.push_back(p);
          G[v].push_back(E.size()), E.push_back(q);
        }

        bool bfs() {
          memset(dist, -1, sizeof dist);
          queue<int> Q; Q.push(src), dist[src] = 0;

          while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            for(int i=0; i<(int)G[u].size(); i++) {
              int id = G[u][i];
              int v = E[id].v;
              if( ~dist[v] || E[id].f==E[id].c ) continue;
              dist[v] = dist[u] + 1, Q.push(v);
            }
          }
          return ~dist[snk];
        }

        int dfs( int u, int flow ) {
          if( !flow ) return 0;
          if( u==snk ) return flow;

          for(; start[u]<(int)G[u].size(); start[u]++) {
            int id = G[u][start[u]];
            if( E[id].f==E[id].c ) continue;
            int v = E[id].v;
            if( dist[v]==dist[u] + 1 ) {
              int df = dfs( v, min(flow, E[id].c-E[id].f) );
              if( df>0 ) {
                E[id].f += df;
                E[id^1].f -= df;
                return df;
              }
            }
          }
          return 0;
        }

        int maxFlow( int _s, int _t ) {
          int ret = 0;
          src = _s, snk = _t;
          while( bfs() ) {
            memset(start, 0, sizeof start);
            while( int f = dfs( src, inf ) ) ret += f;
          }
          return ret;
        }
} FLOW;

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &N);
    source = 0, sink = N*2 + 1, nd = 0;
    FLOW.initialize( N*2 + 2 );
    for(int i=1; i<=N; i++) {
      scanf("%d", &info[i].cap);
      info[i].in = ++nd;
      info[i].out = ++nd;
      FLOW.addEdge( info[i].in, info[i].out, info[i].cap );
    }
    scanf("%d", &M);
    for(int i=0, a, b, c; i<M; i++) {
      scanf("%d %d %d", &a, &b, &c);
      FLOW.addEdge( info[a].out, info[b].in, c );
    }
    scanf("%d %d", &B, &D);
    for(int i=0, x; i<B; i++) {
      scanf("%d", &x);
      FLOW.addEdge( source, info[x].in, info[x].cap );
    }
    for(int i=0, x; i<D; i++) {
      scanf("%d", &x);
      FLOW.addEdge( info[x].out, sink, info[x].cap );
    }
    int res = FLOW.maxFlow( source, sink );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
