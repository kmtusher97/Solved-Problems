#include <bits/stdc++.h>

using namespace std;

#define sc scanf
#define pf printf
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

#define read freopen("INPUT.txt", "r", stdin)
#define write freopen("OUTPUT.txt", "w", stdout)
#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MX = 200050;
int n, nw, a[MX];
intl BIT[MX];
vii b;

void update( int id, int v ) {
  while( id<=nw ) {
    BIT[id] += v;
    id += (id&-id);
  }
}

int query( int id ) {
  int sm = 0;
  while( id>=1 ) {
    sm += BIT[id];
    id -= (id&-id);
  }
  return sm;
}

int main() {
  int cases;
  sc("%d", &cases);
  while( cases-- ) {
    sc("%d", &n);
    for(int i=1; i<=n; i++) {
      sc("%d", a+i);
      b.pb( mk_pr(a[i], i) );
    }
    sort(b.begin(), b.end());
    nw = 1;
    intl ans = 0;
    a[ b[0].second ] = nw;
    for(int i=1; i<n; i++) {
      if( b[i].first!=b[i-1].first ) {
        a[b[i].second] = ++nw;
      }
      else {
        a[b[i].second] = nw;
      }
    }

    memset( BIT, 0, sizeof BIT );
    for(int i=n; i>0; i--) {
      ans += query( a[i] );
      update( a[i], 1 );
    }

    pf("%lld\n", ans);
    b.clear();
  }

  return 0;
}
