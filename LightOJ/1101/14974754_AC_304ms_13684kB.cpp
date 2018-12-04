/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
#define MX_N 50005
#define MX_LOG 17
int n, m, Q, prnt[MX_N];
vector<pii> G[MX_N];
struct Edge {
  int u, v, w;
  bool operator < ( Edge e ) const {
    return w < e.w;
  }
};
vector<Edge> E;

int root( int u ) {
  while(  u != prnt[u] ) {
    prnt[u] = prnt[prnt[u]];
    u = prnt[u];
  }
  return prnt[u];
}

void krushkalMST() {
  sort(E.begin(), E.end());
  for(int i = 0, cnt = 0; i < E.size(); i++) {
    Edge e = E[i];
    int u = e.u;
    int v = e.v;
    if( root(u) != root(v) ) {
      G[u].push_back({v, e.w});
      G[v].push_back({u, e.w});
      u = root(u);
      v = root(v);
      prnt[u] = prnt[v], cnt++;
    }
    if( cnt == n - 1 ) break;
  }
}

int h[MX_N], sp[MX_N][MX_LOG][2];

void dfs( int u, int p, int c ) {
  sp[u][0][1] = c, sp[u][0][0] = p;
  if( p + 1 ) h[u] = h[p] + 1;

  for(int i = 1; i < MX_LOG; i++)
    if( sp[u][i - 1][0] + 1 ) {
      sp[u][i][1] = max( sp[u][i - 1][1], sp[sp[u][i - 1][0]][i - 1][1] );
      sp[u][i][0] = sp[sp[u][i - 1][0]][i - 1][0];
    }

  for(int i = 0; i < (int)G[u].size(); i++) {
    pii v = G[u][i];
    if( v.F != p )
      dfs( v.F, u, v.S );
  }
}

int queryLCA( int u, int v ) {
  if( h[u] < h[v] )
    swap(u, v);
  int res = 0;
  for(int i = MX_LOG-1; i >= 0; i--)
    if( sp[u][i][0] + 1 && h[sp[u][i][0]] >= h[v] )
      res = max( res, sp[u][i][1] ), u = sp[u][i][0];

  if( u == v ) return res;

  for(int i = MX_LOG - 1; i >= 0; i--)
    if( sp[u][i][0] != sp[v][i][0] ) {
      res = max( res, max( sp[u][i][1], sp[v][i][1] ) );
      u = sp[u][i][0], v = sp[v][i][0];
    }

  if( u != v ) {
    res = max( res, max( sp[u][0][1], sp[v][0][1] ) );
    u = sp[u][0][0];
    v = sp[v][0][0];
  }
  return res;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++) {
      G[i].clear(), prnt[i] = i;
      for(int j = 0; j < MX_LOG; j++)
        sp[i][j][0] = sp[i][j][1] = -1;
    }
    E.clear();
    for(int i = 1, a, b, c; i <= m; i++)
      scanf("%d %d %d", &a, &b, &c), E.push_back({a, b, c});

    h[0] = h[1] = 0;
    krushkalMST();
    dfs( 1, -1, 0 );
    printf("Case %d:\n", ++caseno);
    scanf("%d", &Q);
    for(int i = 0, a, b; i < Q; i++) {
      scanf("%d %d", &a, &b);
      printf("%d\n", queryLCA( a, b ));
    }
  }
  return 0;
}
