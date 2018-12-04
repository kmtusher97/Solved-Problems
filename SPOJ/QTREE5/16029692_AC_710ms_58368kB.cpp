/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
#define inf 1e7
#define MX_N 100005

int clr[MX_N];
vi G[MX_N];

/*----------Centroid Decomposition-----------*/
int tot, sz[MX_N], P[MX_N];
int L[MX_N], D[20][MX_N];
bool Cntroid[MX_N];

multiset<int> res[MX_N];

void dfs( int u, int p = -1 ) {
  ++tot, sz[u] = 1;

  for(auto& v : G[u])
    if( v != p and !Cntroid[v] )
      dfs( v, u ), sz[u] += sz[v];
}

int get_Centroid( int u, int p = -1 ) {
  for(auto& v : G[u])
    if( v != p and !Cntroid[v] and sz[v] > tot / 2 )
      return get_Centroid( v, u );

  return u;
}

void dfs_dist( int u, int lvl, int d = 0, int p = -1 ) {
  D[lvl][u] = d;
  for(auto& v : G[u])
    if( v != p and !Cntroid[v] )
      dfs_dist( v, lvl, d + 1, u );
}

void decompose( int u = 1, int p = -1, int lvl = 0 ) {
  tot = 0, dfs( u );
  int center = get_Centroid( u );
  dfs_dist( center, lvl );

  P[center] = p;
  L[center] = lvl;
  Cntroid[center] = 1;

  for(auto& v : G[center])
    if( !Cntroid[v] )
      decompose( v, center, lvl + 1 );
}

void update( int u, bool t ) {
  for(int p = u, lvl = L[u]; ~p; p = P[p], --lvl) {
    if( t )
      res[p].insert(D[lvl][u]);
    else {
      auto it = res[p].find(D[lvl][u]);
      if( it != res[p].end() )
        res[p].erase(it);
    }
  }
}

int query( int u ) {
  int ret = inf;
  for(int p = u, lvl = L[u]; ~p; p = P[p], --lvl)
    ret = min(ret, *(res[p].begin()) + D[lvl][u]);

  return ret == inf ? -1 : ret;
}
/*-------------------------------------------*/

int main() {
  int n, q;
  scanf("%d", &n);
  for(int i = 1, u, v; i < n; i++) {
    scanf("%d %d", &u, &v);
    G[u].pb(v), G[v].pb(u);
  }

  for(int i = 0; i < MX_N; i++)
    res[i].insert(inf);

  decompose();

  scanf("%d", &q);
  for(int i = 1, t, u; i <= q; i++) {
    scanf("%d %d", &t, &u);
    if( !t )
      update( u, clr[u] ^ 1 ), clr[u] ^= 1;
    else
      printf("%d\n", query( u ));
  }
  return 0;
}
