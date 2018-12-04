/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 20005
int n, m;
vector<int> G[MX_N];

static int clk;
int dfs_num[MX_N], dfs_low[MX_N], visited[MX_N];
int grp_of[MX_N], indegree[MX_N], outdegree[MX_N];
vector<int> S, R;

void sccTarjan( int u ) {
  dfs_low[u] = dfs_num[u] = ++clk;
  visited[u] = true;
  S.push_back(u);

  for(int i=0; i<G[u].size(); i++) {
    int v = G[u][i];
    if( !dfs_num[v] ) sccTarjan( v );
    if( visited[v] )
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if( dfs_low[u]==dfs_num[u] ) {
    while( true ) {
      int v = S.back(); S.pop_back();
      grp_of[v] = u;
      visited[v] = 0;
      if( u==v ) break;
    }
    R.push_back( u );
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n+2; i++) {
      G[i].clear();
      dfs_low[i] = dfs_num[i] = visited[i] = 0;
      grp_of[i] = i, indegree[i] = outdegree[i] = 0;
    }
    for(int i=0, u, v; i<m; i++) {
      scanf("%d %d", &u, &v);
      G[u].push_back(v);
    }

    S.clear(), R.clear(), clk = 0;
    for(int i=1; i<=n; i++)
      if( !dfs_num[i] ) sccTarjan( i );

    for(int i=1; i<=n; i++)
    for(int j=0; j<G[i].size(); j++) {
      int v = G[i][j];
      if( grp_of[v]==grp_of[i] ) continue;
      outdegree[grp_of[i]]++;
      indegree[grp_of[v]]++;
    }

    int a = 0, b = 0;
    for(int i=0; i<R.size(); i++) {
      if( !indegree[R[i]] ) a++;
      if( !outdegree[R[i]] ) b++;
    }
    
    int res = (R.size()==1) ? 0 : max(a, b);
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}

