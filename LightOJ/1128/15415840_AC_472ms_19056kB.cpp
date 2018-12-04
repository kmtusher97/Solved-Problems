/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define MXLOG 18
#define MX_N 100002
int n, Q, vlu[MX_N];
int par[MX_N][MXLOG];
vi G[MX_N];

void dfs( int u, int p ) {
  par[u][0] = p;
  for(int i = 1; i < MXLOG; i++)
    par[u][i] = par[par[u][i - 1]][i - 1];

  for(int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    dfs( v, u );
  }
}

int query( int u, int k ) {
  for(int i = MXLOG - 1; i >= 0; i--) {
    if( !par[u][i] ) continue;
    if( vlu[par[u][i]] >= k ) u = par[u][i];
  }
  return u;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &Q);
    for(int i = 0; i <= n; i++) {
      G[i].clear();
      for(int j = 0; j < MXLOG; j++)
        par[i][j] = 0;
    }
    vlu[0] = -1, vlu[1] = 1;
    for(int i = 2, p; i <= n; i++) {
      scanf("%d %d", &p, vlu + i);
      G[p + 1].push_back(i);
    }
    dfs( 1, 0 );
    printf("Case %d:\n", ++caseno);
    for(int i = 0, v, k; i < Q; i++) {
      scanf("%d %d", &v, &k);
      int res = query( v + 1, k );
      printf("%d\n", res - 1);
    }
  }
  return 0;
}
