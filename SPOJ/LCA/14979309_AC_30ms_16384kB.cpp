/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 1002
#define MX_LOG 10
int n, h[MX_N], par[MX_N][MX_LOG + 1];
vector<int> G[MX_N];

void dfs( int u, int p ) {
  h[u] = h[p] + 1;
  par[u][0] = p;

  for(int i = 1; i <= MX_LOG; i++)
    par[u][i] = par[par[u][i-1]][i-1];

  for(auto v : G[u])
    if( v != p )
      dfs( v, u );
}

int queryLCA( int u, int v ) {
  if( h[u] < h[v] )
    swap( u, v );
  for(int i = MX_LOG; i >= 0; i--)
    if( h[par[u][i]] >= h[v] ) u = par[u][i];

  if( u == v ) return u;

  for(int i = MX_LOG; i >= 0; i--)
    if( par[u][i] != par[v][i] )
      u = par[u][i], v = par[v][i];


  if( u != v )
    u = par[u][0], v = par[v][0];
  return u;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i = 1, k; i <= n; i++) {
      scanf("%d", &k), G[i].clear();
      for(int j = 0, x; j < k; j++) {
        scanf("%d", &x);
        G[i].push_back(x);
      }
    }
    memset(par, 0, sizeof par);
    dfs( 1, 0 );
    printf("Case %d:\n", ++caseno);
    int Q;
    scanf("%d", &Q);
    for(int i = 0, a, b; i < Q; i++) {
      scanf("%d %d", &a, &b);
      printf("%d\n", queryLCA( a, b ));
    }
  }
  return 0;
}
