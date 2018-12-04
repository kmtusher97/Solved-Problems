/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
 
typedef pair<int, int> pii;
 
#define MX_N 502
int n, m, t, parent[MX_N], ff[MX_N];
bool visited[MX_N];
vector<pii> G[MX_N];
 
struct Edge {
  int u, v, w;
  bool operator < ( Edge o ) const { return w < o.w; }
};
vector<Edge> E;
 
int findRoot( int u ) {
  while( u!=parent[u] ) {
    parent[u] = parent[parent[u]];
    u = parent[u];
  }
  return u;
}
 
void MSTKrushkal() {
  sort(E.begin(), E.end());
  for(int i=0; i<=n; i++)
    parent[i] = i, G[i].clear();
  for(int i=0, cnt=0; i<m; i++) {
    Edge e = E[i];
    int u = e.u;
    int v = e.v;
    if( findRoot(u)!=findRoot(v) ) {
      int uu = findRoot(u);
      int vv = findRoot(v);
      parent[uu] = parent[vv];
      G[u].push_back({v, e.w});
      G[v].push_back({u, e.w});
      cnt++;
      if( cnt==n-1 ) break;
    }
  }
}
 
void dfs( int u, int c ) {
  visited[u] = true;
  ff[u] = max(ff[u], c);
 
  for(int i=0; i<G[u].size(); i++) {
    pii v = G[u][i];
    if( !visited[v.F] ) dfs( v.F, max(v.S, ff[u]) );
  }
}
 
int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    E.clear();
    for(int i=0, a, b, c; i<m; i++) {
      scanf("%d %d %d", &a, &b, &c);
      E.push_back({a, b, c});
    }
    scanf("%d", &t);
 
    MSTKrushkal();
    memset(ff, 0, sizeof ff);
    memset(visited, 0, sizeof visited);
    dfs( t, 0 );
    printf("Case %d:\n", ++caseno);
    for(int i=0; i<n; i++) {
      if( !visited[i] ) printf("Impossible\n");
      else printf("%d\n", ff[i]);
    }
  }
  return 0;
}
 