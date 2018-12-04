/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 10005
static int clk;
int n, m, dfs_num[MX_N], dfs_low[MX_N], SCC[MX_N], dgree[MX_N];
bool visited[MX_N];
vector<int> G[MX_N], S, R;

void tarjanSCC( int u, int p ) {
  dfs_low[u] = dfs_num[u] = ++clk;
  S.push_back(u);
  visited[u] = true;
  for(int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    if( !dfs_num[v] )
      tarjanSCC( v, u ), dfs_low[u] = min( dfs_low[u], dfs_low[v] );
    if( visited[v] && v != p )
      dfs_low[u] = min( dfs_low[u], dfs_num[v] );
  }
  if( dfs_low[u] == dfs_num[u] ) {
    while( true ) {
      int v = S.back(); S.pop_back();
      visited[v] = false;
      SCC[v] = u;
      if( u == v ) break;
    }
    R.push_back(u);
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++) {
      G[i].clear(), dfs_low[i] = dfs_num[i] = 0;
      visited[i] = SCC[i] = dgree[i] = 0;
    }
    for(int i = 0, u, v; i < m; i++) {
      scanf("%d %d", &u, &v), u++, v++;
      G[u].push_back(v);
      G[v].push_back(u);
    }

    clk = 0, S.clear(), R.clear();
    for(int i = 1; i <= n; i++)
      if( !dfs_num[i] ) tarjanSCC( i, 0 );

    for(int u = 1; u <= n; u++) {
      for(int j = 0; j < (int)G[u].size(); j++) {
        int v = G[u][j];
        if( SCC[u] == SCC[v] ) continue;
        dgree[SCC[u]]++;
      }
    }

    int res = 0;
    for(int i = 0; i < (int)R.size(); i++)
      if( dgree[R[i]] == 1 ) res++;

    res = res / 2 + res % 2;
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}

