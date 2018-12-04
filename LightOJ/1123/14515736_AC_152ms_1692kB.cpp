/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

#define MX_N 202
int N, W, cost, cnt, parent[MX_N];
set<piii> E;

int root( int u ) {
  while( u!=parent[u] ) {
    parent[u] = parent[parent[u]];
    u = parent[u];
  }
  return u;
}

void krushkalMST() {
  piii bad;
  bad = {0, {0, 0}};
  cost = cnt = 0;
  for(int i=0; i<=N; i++)
    parent[i] = i;
  for(set<piii> :: iterator it=E.begin(); it!=E.end(); it++) {
    piii e = *it;
    int u = e.S.F;
    int v = e.S.S;
    if( root(u)!=root(v) ) {
      u = root(u);
      v = root(v);
      parent[u] = parent[v];
      cost += e.F, cnt++;
    }
    else bad = e;
  }
  if( bad.S.F ) E.erase(bad);
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &N, &W), E.clear();
    printf("Case %d:\n", ++caseno);
    for(int i=0, u, v, w; i<W; i++) {
      scanf("%d %d %d", &u, &v, &w);
      E.insert({w, {u, v}});
      krushkalMST();
      if( cnt!=N-1 ) printf("-1\n");
      else printf("%d\n", cost);
    }
  }
  return 0;
}
