/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
#define MX_N 412345
int n, Q, nd, prnt[MX_N], cnt[MX_N];
intl sum[MX_N];
map<int, int> mp;

int root( int u ) {
  while( prnt[u] != u ) {
    prnt[u] = prnt[prnt[u]];
    u = prnt[u];
  }
  return prnt[u];
}

int main() {
  while( scanf("%d %d", &n, &Q) == 2 ) {
    nd = n + 2, mp.clear();
    for(int i = 0; i < MX_N; i++)
      prnt[i] = sum[i] = i, cnt[i] = 1;
    while( Q-- ) {
      int t, u, v;
      scanf("%d %d", &t, &u);
      if( t == 1 ) {
        scanf("%d", &v);
        int x = u;
        int y = v;
        if( mp.find(x) != mp.end() ) u = mp[u];
        if( mp.find(y) != mp.end() ) v = mp[v];
        if( root( u ) != root( v ) ) {
          u = root( u );
          v = root( v );
          sum[prnt[v]] += sum[prnt[u]];
          cnt[prnt[v]] += cnt[prnt[u]];
          prnt[u] = prnt[v];
        }
      }
      else if( t == 2 ) {
        scanf("%d", &v);
        int x = u;
        int y = v;
        if( mp.find(x) != mp.end() ) u = mp[u];
        if( mp.find(y) != mp.end() ) v = mp[v];
        if( root( u ) != root( v ) ) {
          u = root( u );
          v = root( v );
          sum[prnt[u]] -= x;
          cnt[prnt[u]]--;
          mp[x] = ++nd, sum[nd] = x;
          u = nd;
          sum[prnt[v]] += x;
          cnt[prnt[v]] ++;
          prnt[u] = prnt[v];
        }
      }
      else {
        if( mp.find(u) != mp.end() ) u = mp[u];
        u = root( u );
        printf("%d %lld\n", cnt[prnt[u]], sum[prnt[u]]);
      }
    }
  }
  return 0;
}
