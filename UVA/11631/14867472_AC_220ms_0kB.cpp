/*  ~*BISMILLAHIR RAHMANIR RAHIM  */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long intl;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MX_N = 1123456;
int n, m, prnt[MX_N];
vector<piii> E;

bool cmp( piii a, piii b ) {
  return a.F < b.F;
}

int root( int u ) {
  while( u != prnt[u] ) {
    prnt[u] = prnt[prnt[u]];
    u = prnt[u];
  }
  return prnt[u];
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
  while( cin >> n >> m && n && m ) {
    E.clear();
    intl ttl = 0LL;
    for(int i = 0, u, v, w; i < m; i++) {
      cin >> u >> v >> w;
      u++, v++, ttl += w;
      E.push_back( { w, { u, v } } );
    }

    sort(E.begin(), E.end(), cmp);
    for(int i = 0; i <= n; i++)
      prnt[i] = i;
    intl cst = 0;

    for(int i = 0, cnt = 0; i < E.size(); i++) {
      piii e = E[i];
      int u = e.S.F;
      int v = e.S.S;
      if( root( u ) != root( v ) ) {
        u = root( u );
        v = root( v );
        prnt[u] = prnt[v];
        cst += e.F, cnt++;
      }
      if( cnt == n-1 ) break;
    }
    cout << ttl - cst << endl;
  }
  return 0;
}

