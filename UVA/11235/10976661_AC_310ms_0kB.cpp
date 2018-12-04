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
int a[MX];

struct data {
  int mst_frqnt, mf_frq;
  int prfx, p_frq;
  int sufx, s_frq;

  void reset( int x ) {
    mst_frqnt = prfx = sufx = x;
    mf_frq = p_frq = s_frq = 1;
  }
} tree[3*MX];

data marge( data lft, data rgt ) {
  data prnt;
  int l_frq = lft.mf_frq;
  int r_frq = rgt.mf_frq;
  if( lft.mst_frqnt == rgt.prfx ) l_frq += rgt.p_frq;
  if( rgt.mst_frqnt == lft.sufx ) r_frq += lft.s_frq;
  if( l_frq > r_frq ) {
    prnt.mst_frqnt = lft.mst_frqnt;
    prnt.mf_frq = l_frq;
  }
  else {
    prnt.mst_frqnt = rgt.mst_frqnt;
    prnt.mf_frq = r_frq;
  }
  if( lft.sufx == rgt.prfx && lft.s_frq+rgt.p_frq > prnt.mf_frq ) {
    prnt.mst_frqnt = lft.sufx, prnt.mf_frq = lft.s_frq+rgt.p_frq;
  }
  prnt.prfx = lft.prfx, prnt.p_frq = lft.p_frq;
  prnt.sufx = rgt.sufx, prnt.s_frq = rgt.s_frq;
  if( lft.prfx == rgt.prfx ) prnt.p_frq += rgt.p_frq;
  if( rgt.sufx == lft.sufx ) prnt.s_frq += lft.s_frq;
  return prnt;
}

void build( int node, int lo, int hi ) {
  if( lo == hi ) {
    tree[node].reset( a[lo] );
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = marge( tree[lft], tree[rgt] );
}

data query( int node, int lo, int hi, int l, int r ) {
  if( lo >= l && hi <= r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( r <= mid ) return query( lft, lo, mid, l, r );
  else if( l > mid ) return query( rgt, mid+1, hi, l, r );
  return marge( query( lft, lo, mid, l, r ), query( rgt, mid+1, hi, l, r ) );
}

int main() {
  int n, Q;
  while( scanf("%d", &n) && n ) {
    scanf("%d", &Q);
    for(int i=1; i<=n; i++) {
      scanf("%d", a+i);
    }
    build( 1, 1, n );
    while( Q-- ) {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", query( 1, 1, n, l, r ).mf_frq);
    }
  }
  return 0;
}
