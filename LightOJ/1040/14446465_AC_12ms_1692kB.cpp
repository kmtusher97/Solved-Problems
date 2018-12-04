/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 52
int n, cnt, parent[MX_N];
bool vis[MX_N*MX_N];

struct Edge {
  int u, v, w;
  bool operator < ( Edge o ) const { return w<o.w; }
};
vector<Edge> E;

int root( int u ) {
  while( u!=parent[u] ) {
    parent[u] = parent[parent[u]];
    u = parent[u];
  }
  return u;
}

void krushkalMST() {
  memset(vis, 0, sizeof vis), cnt = 0;
  sort(E.begin(), E.end());
  for(int i=0; i<=n; i++)
    parent[i] = i;
  for(int i=0; i<E.size(); i++) {
    Edge e = E[i];
    int u = e.u;
    int v = e.v;
    if( root(u)!=root(v) ) {
      u = root(u);
      v = root(v);
      parent[v] = parent[u];
      vis[i] = true;
      if( ++cnt==n-1 ) break;
    }
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while(  cases-- ) {
    scanf("%d", &n);
    E.clear();
    for(int i=1; i<=n; i++)
    for(int j=1, x; j<=n; j++) {
      scanf("%d", &x);
      if( x ) E.push_back({i, j, x});
    }

    krushkalMST();
    int res = 0;
    for(int i=0; i<E.size(); i++) {
      if( !vis[i] ) res += E[i].w;
    }
    if( cnt!=n-1 ) res = -1;
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}

