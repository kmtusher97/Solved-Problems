#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1123456;
const ll modulo = 100000007;
int n, m, a[1234], b[1234];
bool vis[1234];
ll dp[1234][1234];

ll big_mod( ll b, ll p ) {
  if( p == 0 ) return 1LL;
  ll x = big_mod( b, p/2 );
  x = (x%modulo * x%modulo) % modulo;
  if( p&1 ) x = (b%modulo * x%modulo) % modulo;
  return x%modulo;
}

ll ff( int p, ll v ) {
  if( p == n ) {
    if( vis[v] ) return 1LL;
    return 0LL;
  }
  if( dp[p][v] != -1 ) return dp[p][v]%modulo;
  ll pp = ff( p+1, v^a[p] )%modulo;
  ll qq = ff( p+1, v )%modulo;
  return dp[p][v] = (pp+qq)%modulo;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    memset(vis, 0, sizeof vis);
    memset(dp, -1, sizeof dp);
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
      scanf("%d", a+i);
    }
    for(int i=0; i<m; i++) {
      scanf("%d", b+i);
      vis[b[i]] = true;
    }
    ll xx = ff(0, 0)%modulo;
    ll ans = (big_mod(2, n)%modulo - xx%modulo + modulo) % modulo;
    printf("Case %d: %lld\n", ++caseno, ans);
  }
  return 0;
}
