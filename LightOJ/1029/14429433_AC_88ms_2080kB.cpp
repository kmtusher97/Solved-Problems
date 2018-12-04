/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
 
typedef long long intl;
 
#define MX_N 102
int nodes, parent[MX_N];
 
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
    scanf("%d", &nodes), E.clear();
    int a, b, c;
    while( scanf("%d %d %d", &a, &b, &c)==3 ) {
      if( !a && !b && !c ) break;
      E.push_back({a, b, c});
    }
    sort(E.begin(), E.end());
    intl cost = krushkalMST();
    sort(E.rbegin(), E.rend());
    cost += krushkalMST();
 
    intl gcd = __gcd(cost, 2LL), dnm, nm;
    dnm = cost/gcd;
    nm = 2LL/gcd;
    printf("Case %d: %lld", ++caseno, dnm);
    if( nm>1 ) printf("/%lld\n", nm);
    else printf("\n");
  }
  return 0;
}