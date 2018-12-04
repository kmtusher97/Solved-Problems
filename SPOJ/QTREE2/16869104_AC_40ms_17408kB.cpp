/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
#define MX_N 10005
#define LG 15
int n, D[MX_N];
vector<pii> G[MX_N];

/*--------LCA--------*/
int H[MX_N], P[MX_N][LG];

void dfs( int u = 1, int p = 0, int c = 0 ) {
  H[u] = H[p] + 1;
  P[u][0] = p, D[u] = c;

  for(int i = 1; i < LG; i++)
    P[u][i] = P[P[u][i - 1]][i - 1];

  for(auto& v : G[u])
    if( v.F != p )
      dfs( v.F, u, c + v.S );
}

int LCA( int u, int v ) {
  if( H[u] < H[v] ) swap(u, v);

  for(int i = LG - 1; i >= 0; i--)
    if( H[P[u][i]] >= H[v] )
      u = P[u][i];

  if( u == v ) return u;

  for(int i = LG - 1; i >= 0; i--)
    if( P[v][i] != P[u][i] )
      u = P[u][i], v = P[v][i];

  return P[u][0];
}

int KthPar( int k, int u ) {
  for(int i = LG - 1; i >= 0; i--)
    if( (1 << i) <= k )
      u = P[u][i], k -= (1 << i);

  return u;
}
/*--------------------*/

int QryDist( int u, int v ) {
  int lca = LCA( u, v );
  int ret = D[u] + D[v] - (2 * D[lca]);
  return ret;
}

int QryKthP( int k, int u, int v ) {
  int lca = LCA( u, v );
  if( H[u] - H[lca] + 1 >= k )
    return KthPar( k - 1, u );

  k -= (H[u] - H[lca]);
  k = (H[v] - H[lca] + 1) - k;
  return KthPar( k, v );
}

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    memset(P[1], 0, sizeof P[1]);
    for(int i = 1; i <= n; i++)
      G[i].clear(), D[i] = 0;

    for(int i = 1, u, v, w; i < n; i++) {
      scanf("%d %d %d", &u, &v, &w);
      G[u].push_back({v, w});
      G[v].push_back({u, w});
    }

    dfs();

    char op[10];
    while( ~scanf("%s", op) and op[1] != 'O' ) {
      int k, x, y;
      if( op[0] == 'D' ) {
        scanf("%d %d", &x, &y);
        printf("%d\n", QryDist( x, y ));
      }
      else {
        scanf("%d %d %d", &x, &y, &k);
        printf("%d\n", QryKthP( k, x, y ));
      }
    }
  }
  return 0;
}
