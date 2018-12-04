/* ~*BISMILLAHIR RAHMANIR RAHIM*~ */
#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX_N = 300050;
int n, m, nd, prnt[MX_N], cnt[MX_N];
intl sum[MX_N];
map<int, int> mp;

int root( int u ) {
  while( u != prnt[u] ) {
    prnt[u] = prnt[prnt[u]];
    u = prnt[u];
  }
  return prnt[u];
}

int main() {
  while( ~scanf("%d %d", &n, &m) ) {
    nd = n, mp.clear();
    for(int i = 0; i < MX_N; i++)
      prnt[i] = sum[i] = i, cnt[i] = 1;

    while( m-- ) {
      int t, p, q;
      scanf("%d %d", &t, &p);
      if( t == 1 ) {
        scanf("%d", &q);
        if( mp.find(p) != mp.end() ) p = mp[p];
        if( mp.find(q) != mp.end() ) q = mp[q];
        int u = p, v = q;
        p = root( p );
        q = root( q );
        if( p != q ) {
          cnt[prnt[p]] += cnt[prnt[q]];
          sum[prnt[p]] += sum[prnt[q]];
          prnt[q] = prnt[p];
        }
      }
      else if( t == 2 ) {
        scanf("%d", &q);
        int u = p, v = q;
        if( mp.find(p) != mp.end() ) p = mp[p];
        if( mp.find(q) != mp.end() ) q = mp[q];
        p = root( p );
        q = root( q );
        if( p != q ) {
          cnt[prnt[p]]--, sum[prnt[p]] -= u;
          mp[u] = ++nd, cnt[nd] = 1, sum[nd] = u;
          cnt[prnt[q]]++, sum[prnt[q]] += u, prnt[nd] = prnt[q];
        }
      }
      else {
        if( mp.find(p) != mp.end() ) p = mp[p];
        p = root(p);
        printf("%d %lld\n", cnt[prnt[p]], sum[prnt[p]]);
      }
    }
  }
  return 0;
}