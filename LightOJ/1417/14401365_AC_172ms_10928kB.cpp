/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 50005
int nodes, ff[MX_N];
vector<int> G[MX_N], G1[MX_N];

static int clk;
int dfs_num[MX_N], dfs_low[MX_N], scc_sz[MX_N], scc[MX_N];
bool visited[MX_N];
vector<int> S, R;

void sccTarjan( int u ) {
  dfs_low[u] = dfs_num[u] = ++clk;
  S.push_back(u);
  visited[u] = true;

  for(int i=0; i<G[u].size(); i++) {
    int v = G[u][i];
    if( !dfs_num[v] ) sccTarjan( v );
    if( visited[v] )
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if( dfs_low[u]==dfs_num[u] ) {
    R.push_back(u);
    while( true ) {
      int v = S.back(); S.pop_back();
      visited[v] = false;
      scc[v] = u, scc_sz[u]++;
      if( u==v ) break;
    }
  }
}

int dfs1( int u ) {
  if( ff[u] ) return ff[u];

  int ret = scc_sz[u];
  for(int i=0; i<G1[u].size(); i++) {
    int v = G1[u][i];
    ret += dfs1( v );
  }
  return ff[u] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &nodes);
    for(int i=0; i<=nodes; i++) {
      G[i].clear(), G1[i].clear();
      dfs_low[i] = dfs_num[i] = visited[i] = 0;
      scc[i] = i, scc_sz[i] = ff[i] = 0;
    }
    for(int i=0, u, v; i<nodes; i++) {
      scanf("%d %d", &u, &v);
      G[u].push_back(v);
    }

    clk = 0, R.clear(), S.clear();
    for(int i=1; i<=nodes; i++)
      if( !dfs_num[i] ) sccTarjan( i );

    for(int u=1; u<=nodes; u++)
    for(int i=0; i<G[u].size(); i++) {
      int v = G[u][i];
      if( scc[u]==scc[v] ) continue;
      G1[scc[u]].push_back(scc[v]);
    }

    for(int i=0; i<R.size(); i++) {
      int u = R[i];
      if( ff[u] ) continue;
      dfs1( u );
    }
    int mx = 0, id, res;
    for(int i=0; i<R.size(); i++) {
      if( ff[R[i]]>mx ) mx = ff[R[i]], id = R[i];
    }
    res = id;
    for(int i=1; i<=nodes; i++) {
      if( scc[i]==id ) res = min(res, i);
    }
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}

