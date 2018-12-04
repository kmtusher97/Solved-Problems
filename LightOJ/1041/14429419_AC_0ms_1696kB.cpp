/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

#define MX_N 102
int nodes, m, parent[MX_N];
map<string, int> ctid;

struct Edge {
  int u, v, w;
  bool operator < ( Edge o ) const { return w<o.w; }
};
vector<Edge> E;

int findRoot( int u ) {
  while( u!=parent[u] ) {
    parent[u] = parent[parent[u]];
    u = parent[u];
  }
  return u;
}

intl krushkalMST() {
  intl cost = 0LL;
  sort(E.begin(), E.end());
  for(int i=0; i<=nodes; i++)
    parent[i] = i;
  for(int i=0, cnt=0; i<E.size(); i++) {
    Edge e = E[i];
    int u = e.u;
    int v = e.v;
    if( findRoot(u)!=findRoot(v) ) {
      cost += e.w;
      u = findRoot(u);
      v = findRoot(v);
      parent[u] = parent[v];
      cnt++;
      if( cnt==nodes ) break;
    }
  }
  return cost;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &m);
    nodes = 0, E.clear(), ctid.clear();
    for(int i=0, a, b, c; i<m; i++) {
      char ct1[60], ct2[60];
      scanf("%s %s %d", ct1, ct2, &c);
      string s = ct1;
      if( ctid.find(s)==ctid.end() ) ctid[s] = ++nodes;
      a = ctid[s];
      s = ct2;
      if( ctid.find(s)==ctid.end() ) ctid[s] = ++nodes;
      b = ctid[s];
      E.push_back({a, b, c});
    }
    intl cost = krushkalMST();
    set<int> st;
    bool ok = true;
    for(int i=1; i<=nodes; i++) {
      st.insert(findRoot(parent[i]));
      if( st.size()>1 ) {
        ok = false;
        break;
      }
    }
    printf("Case %d: ", ++caseno);
    if( !ok ) printf("Impossible\n");
    else printf("%lld\n", cost);
  }
  return 0;
}

