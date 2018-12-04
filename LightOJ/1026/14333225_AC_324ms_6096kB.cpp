/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;

#define MX_N 10002
int n;
vector<int> G[MX_N];
vector<pii> res;

static int clk, root, rootChild;
int dfs_num[MX_N], dfs_low[MX_N], parent[MX_N];
bool articulation_vertex[MX_N];

void articulationPointandBridge( int u ) {
  dfs_low[u] = dfs_num[u] = ++clk;
  for(int i=0; i<(int)G[u].size(); i++) {
    int v = G[u][i];
    if( !dfs_num[v] ) {
      parent[v] = u;
      if( u==root ) rootChild++;
      articulationPointandBridge( v );

      if( dfs_low[v]>=dfs_num[u] ) articulation_vertex[u] = true;
      if( dfs_low[v]>dfs_num[u] ) res.push_back({min(u, v), max(u, v)});
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    else if( v!=parent[u] )
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
  }
}

void reset() {
  clk = 0;
  for(int i=0; i<MX_N; i++) {
    G[i].clear(), dfs_low[i] = dfs_num[i] = 0;
    parent[i] = articulation_vertex[i] = 0;
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases), getchar();
  while( cases-- ) {
    getchar(), scanf("%d", &n);
    reset();
    for(int i=0, u, v, k; i<n; i++) {
      char ch;
      scanf("%d%c%c%d%c", &u, &ch, &ch, &k, &ch);
      for(int j=0; j<k; j++) {
        scanf("%d", &v);
        G[u+1].push_back(v+1);
        G[v+1].push_back(u+1);
      }
    }
    res.clear();
    for(int i=1; i<=n; i++) if( !dfs_num[i] ) {
      root = i, rootChild = 0;
      articulationPointandBridge( i );
      articulation_vertex[root] = (rootChild>1);
    }
    printf("Case %d:\n", ++caseno);
    printf("%d critical links\n", res.size());
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++)
      printf("%d - %d\n", res[i].F-1, res[i].S-1);
  }
  return 0;
}


