/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define MX_N 100005
#define MX_LOG 17
int n, Q, h[MX_N], sp[MX_N][MX_LOG + 1][3];
vii G[MX_N];

void dfs( int u, int p, int c1, int c2 ) {
  h[u] = h[p] + 1;
  sp[u][0][1] = c1, sp[u][0][2] = c2, sp[u][0][0] = p;

  for(int i = 1; i <= MX_LOG; i++) {
    int par = sp[u][i - 1][0];
    sp[u][i][1] = max( sp[u][i - 1][1], sp[par][i - 1][1] );
    sp[u][i][2] = min( sp[u][i - 1][2], sp[par][i - 1][2] );
    sp[u][i][0] = sp[par][i-1][0];
  }

  for(int i = 0; i < (int)G[u].size(); i++) {
    pii v = G[u][i];
    if( v.F != p )
      dfs( v.F, u, v.S, v.S );
  }
}

pii queryLCA( int u, int v ) {
  if( h[u] < h[v] )
    swap(u, v);
  pii ret(0, INT_MAX);

  for(int i = MX_LOG; i >= 0; i--)
    if( h[sp[u][i][0]] >= h[v] ) {
      ret.F = max( ret.F, sp[u][i][1] );
      ret.S = min( ret.S, sp[u][i][2] );
      u = sp[u][i][0];
    }

  for(int i = MX_LOG; i >= 0; i--)
    if( sp[u][i][0] != sp[v][i][0] ) {
      ret.F = max( ret.F, max( sp[u][i][1], sp[v][i][1] ) );
      ret.S = min( ret.S, min( sp[u][i][2], sp[v][i][2] ) );
      u = sp[u][i][0], v = sp[v][i][0];
    }

  if( u != v ) {
    ret.F = max( ret.F, max( sp[u][0][1], sp[v][0][1] ) );
    ret.S = min( ret.S, min( sp[u][0][2], sp[v][0][2] ) );
    u = sp[u][0][0], v = sp[v][0][0];
  }

  return ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
      G[i].clear();
      for(int j = 0; j <= MX_LOG; j++)
        sp[i][j][0] = sp[i][j][1] = 0, sp[i][j][2] = INT_MAX;
    }
    for(int i = 2, a[3]; i <= n; i++) {
      scanf("%d %d %d", a, a + 1, a + 2);
      G[a[0]].push_back({a[1], a[2]});
      G[a[1]].push_back({a[0], a[2]});
    }

    dfs( 1, 0, 0, INT_MAX );

    scanf("%d", &Q);
    printf("Case %d:\n", ++caseno);
    while( Q-- ) {
      int a, b;
      scanf("%d %d", &a, &b);
      pii res = queryLCA( a, b );
      printf("%d %d\n", res.S, res.F);
    }
  }
  return 0;
}
