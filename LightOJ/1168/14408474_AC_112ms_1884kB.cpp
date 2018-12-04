/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define MX_N 1002
int w, k;
vi G[MX_N], G1[MX_N];

static int clk;
int dfs_low[MX_N], dfs_num[MX_N], scc[MX_N];
bool visited[MX_N];
vi S, R;

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
    while( true ) {
      int v = S.back(); S.pop_back();
      visited[v] = 0;
      scc[v] = u;
      if( u==v ) break;
    }
    R.push_back(u);
  }
}

void dfs( int u ) {
  visited[u] = true, clk++;

  if( G1[u].size()>1 ) clk -= MX_N;
  for(int i=0; i<G1[u].size(); i++) {
    int v = G1[u][i];
    if( visited[v] ) continue;
    dfs( v );
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    for(int i=0; i<MX_N; i++) {
      G[i].clear(), G1[i].clear();
      dfs_low[i] = dfs_num[i] = visited[i] = scc[i] = 0;
    }
    scanf("%d", &w);
    set<int> st;
    while( w-- ) {
      scanf("%d", &k);
      for(int i=0, u, v; i<k; i++) {
        scanf("%d %d", &u, &v), u++, v++;
        G[u].push_back(v);
        st.insert(u), st.insert(v);
      }
    }
    vi nodes;
    nodes.assign(st.begin(), st.end());

    clk = 0, S.clear(), R.clear();
    for(int i=0; i<nodes.size(); i++)
      if( !dfs_num[nodes[i]] ) sccTarjan( nodes[i] );

    for(int i=0; i<nodes.size(); i++) {
      int u = nodes[i];
      for(int j=0; j<G[u].size(); j++) {
        int v = G[u][j];
        if( scc[u]==scc[v] ) continue;
        G1[scc[u]].push_back(scc[v]);
      }
    }

    memset(visited, 0, sizeof visited), clk = 0;
    dfs( 1 );
    printf("Case %d: ", ++caseno);
    (clk==R.size()) ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}

