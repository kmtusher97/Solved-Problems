/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

#define MX_N 10002
int n, m, A, parent[MX_N];

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

intl krushkalMST() {
  intl cost = 0;
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
      parent[u] = parent[v];
      cost += e.w;
    }
  }
  return cost;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while(  cases-- ) {
    scanf("%d %d %d", &n, &m, &A);
    E.clear();
    for(int i=1, a, b, c; i<=m; i++) {
      scanf("%d %d %d", &a, &b, &c);
      if( c<A ) E.push_back({a, b, c});
    }

    intl cost = krushkalMST();
    set<int> st;
    for(int i=1; i<=n; i++) {
      st.insert(root(i));
    }
    cost += ((intl)st.size()*A);
    printf("Case %d: %lld %d\n", ++caseno, cost, st.size());
  }
  return 0;
}

