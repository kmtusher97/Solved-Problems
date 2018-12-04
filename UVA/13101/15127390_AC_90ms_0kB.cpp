/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

struct hvyLgtDcmpzn {
        static const int MX_N = 50005;
        int n, POS, ID, vlu[MX_N];
        int P[MX_N], B[MX_N], sz[MX_N], H[MX_N];
        int cID[MX_N], cPos[MX_N], cHd[MX_N];
        int ara[MX_N], tree[MX_N * 4];
        vector<int> G[MX_N];

        void init( int _n ) {
          n = _n, POS = 0, ID = 1;
          for(int i = 0; i < MX_N; i++)
            G[i].clear(), P[i] = cHd[i] = B[i] = -1;
        }

        void dfs( int u, int p ) {
          P[u] = p, sz[u] = 1;
          H[u] = H[p] + 1;
          int mx = -1;
          for(int v : G[u])
            if( v != p ) {
              dfs( v, u ), sz[u] += sz[v];
              if( mx < sz[v] )
                mx = sz[v], B[u] = v;
            }
        }

        void decompose( int u, int p ) {
          cID[u] = ID, cPos[u] = ++POS, ara[POS] = vlu[u];
          if( cHd[ID] == -1 )
            cHd[ID] = u;
          if( ~B[u] )
            decompose( B[u], u );

          for(int v : G[u])
            if( v != p && v != B[u] )
              ID++, decompose( v, u );
        }

        void build( int node, int lo, int hi ) {
          if( lo == hi ) {
            tree[node] = ara[lo];
            return;
          }
          int mid = lo + (hi - lo) / 2, lft = node << 1, rgt = lft | 1;
          build( lft, lo, mid );
          build( rgt, mid + 1, hi );
          tree[node] = __gcd( tree[lft], tree[rgt]);
        }

        void update( int node, int lo, int hi, int pos, int v ) {
          if( lo == hi ) {
            tree[node] = v;
            return;
          }
          int mid = lo + (hi - lo) / 2, lft = node << 1, rgt = lft | 1;
          if( pos <= mid ) update( lft, lo, mid, pos, v );
          else update( rgt, mid + 1, hi, pos, v );
          tree[node] = __gcd( tree[lft], tree[rgt]);
        }

        int query( int node, int lo, int hi, int L, int R ) {
          if( lo > R || hi < L ) return 0;
          if( lo >= L && hi <= R ) return tree[node];
          int mid = lo + (hi - lo) / 2, lft = node << 1, rgt = lft | 1;
          int pp = query( lft, lo, mid, L, R );
          int qq = query( rgt, mid + 1, hi, L, R );
          return __gcd( pp, qq );
        }

        void updateHLD( int u, int x ) {
          update( 1, 1, POS, cPos[u], x );
        }

        int queryHLD( int u, int v ) {
          int ret = 0, cur;
          while( cID[u] != cID[v] ) {
            int hu = cHd[cID[u]];
            int hv = cHd[cID[v]];

            if( H[hu] > H[hv] )
              cur = query( 1, 1, POS, cPos[hu], cPos[u] ), u = P[hu];
            else
              cur = query( 1, 1, POS, cPos[hv], cPos[v] ), v = P[hv];

            ret = __gcd(ret, cur);
          }
          int L = cPos[u], R = cPos[v];
          cur = query( 1, 1, POS, min(L, R), max(L, R) );
          return __gcd(ret, cur);
        }
} hld;

int main() {
  int n, Q;
  while( ~scanf("%d", &n) ) {
    hld.init( n );
    for(int i = 1; i <= n; i++)
      scanf("%d", hld.vlu + i);
    for(int i = 1, u, v; i < n; i++) {
      scanf("%d %d", &u, &v), ++u, ++v;
      hld.G[u].push_back(v);
      hld.G[v].push_back(u);
    }
    hld.dfs( 1, 0 );
    hld.decompose( 1, 0 );
    hld.build( 1, 1, hld.POS );
    scanf("%d", &Q);
    while( Q-- ) {
      int o, l, r;
      scanf("%d %d %d", &o, &l, &r);
      if( o == 1 )
        printf("%d\n", hld.queryHLD( l + 1, r + 1 ));
      else
        hld.updateHLD( l + 1, r );
    }
  }
  return 0;
}
