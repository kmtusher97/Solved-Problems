/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 10002
int n, m, indegree[MX_N];
bool vis[MX_N];
vector<int> G[MX_N], T;

void topplogicalSort( int u ) {
  vis[u] = true;
  for(int i=0; i<G[u].size(); i++) {
    int v = G[u][i];
    if( !vis[v] ) topplogicalSort( v );
  }
  T.push_back( u );
}

void dfs( int u ) {
  vis[u] = true;
  for(int i=0; i<G[u].size(); i++) {
      int v = G[u][i];
      if( !vis[v] ) dfs( v );
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    for(int i=0, u, v; i<m; i++) {
      scanf("%d %d", &u, &v);
      G[u].push_back(v);
      indegree[v]++;
    }
    T.clear();
    for(int i=1; i<=n; i++) {
      if( !vis[i] ) topplogicalSort( i );
    }
    int res = 0;
    memset(vis, 0, sizeof vis);
    for(int i=T.size()-1; i>=0; i--) {
      if( !vis[T[i]] ) dfs( T[i] ), res++;
    }
    printf("Case %d: %d\n", ++caseno, res);
    for(int i=0; i<MX_N; i++) {
      G[i].clear();
      vis[i] = indegree[i] = 0;
    }
  }
  return 0;
}


