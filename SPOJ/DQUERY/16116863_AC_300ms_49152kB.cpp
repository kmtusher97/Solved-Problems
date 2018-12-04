/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define F first
#define S second
#define pb push_back
#define pbk pop_back

typedef long long intl;
typedef queue<int> qi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vii;

#define sc scanf
#define pf printf
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define scl1(x) scanf("%lld", &x)
#define scl2(x, y) scanf("%lld %lld", &x, &y)
#define scl3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define pf1(x) printf("%d", x)
#define pf2(x, y) printf("%d %d", x, y)
#define pf3(x, y, z) printf("%d %d %d", x, y, z)
#define pfl1(x) printf("%lld", x)
#define pfl2(x, y) printf("%lld %lld", x, y)
#define pfl3(x, y, z) printf("%lld %lld %lld", x, y, z)
#define NL printf("\n")
#define FK printf(" ")
#define bug printf("ok :: ")

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define MEM(a, x) memset(a, x, sizeof(a))
#define MEMV(a, n, x) for(int i = 0; i <= n; a[i] = x, i++)

#define For(i, a, b) for(int i = a; i <= b; i++)
#define seg_mid_L_R int mid = l + (r - l) / 2, lft = nd << 1, rgt = lft | 1

/* 6291469, 12582917, 402653189, 1610612741 */

#define READ freopen("INPUT.in", "r", stdin)
#define WRITE freopen("OUTPUT.out", "w", stdout)
#define read freopen("INPUT.txt", "r", stdin)
#define write freopen("OUTPUT.txt", "w", stdout)

#define inf 1e18
#define MOD 1e9 + 7
#define MX_N 2123456
/*---------------------------------------------------------------------------------*/
int n, sz = 0, lp[MX_N];
vi rt;

struct data {
  int l, r, v;
  data() { l = r = 0; }
};

data tt[MX_N];

void U( int p, int c, int l, int r, int ps, int v ) {
  if( l == r ) {
    tt[c].v = tt[p].v + v;
    return;
  }
  int mid = l + (r - l) / 2;
  if( ps <= mid ) {
    if( !tt[c].l ) tt[c].l = ++sz;
    tt[c].r = tt[p].r;
    U( tt[p].l, tt[c].l, l, mid, ps, v );
  }
  else {
    if( !tt[c].r ) tt[c].r = ++sz;
    tt[c].l = tt[p].l;
    U( tt[p].r, tt[c].r, mid + 1, r, ps, v );
  }
  tt[c].v = tt[tt[c].l].v + tt[tt[c].r].v;
}

int Q( int nd, int l, int r, int L, int R ) {
  if( l > R or r < L ) return 0;
  if( l >= L and r <= R ) return tt[nd].v;
  int mid = l + (r - l) / 2;
  return Q( tt[nd].l, l, mid, L, R ) + Q( tt[nd].r, mid + 1, r, L, R );
}

int main() {
  sc1(n), rt.pb(0);
  For(i, 1, n) {
    int a; sc1(a);
    rt.pb(++sz);
    if( lp[a] ) {
      U( rt[i - 1], rt[i], 1, n, lp[a], -1 );
      U( rt[i], rt[i], 1, n, i, 1 );
    }
    else
      U( rt[i - 1], rt[i], 1, n, i, 1 );
    lp[a] = i;
  }

  int m; sc1(m);
  while( m-- ) {
    int l, r;
    sc2(l, r);
    int res = Q( rt[r], 1, n, l, r );
    pf1(res), NL;
  }
  return 0;
}
