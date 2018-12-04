#include <bits/stdc++.h>
using namespace std;

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

const int MX = 56789;
int a[MX];

class _node {
private:
  int prfx, sufx, sm, mx;
public:
  _node() : prfx(0), sufx(0), sm(0), mx(0) { }
  void asign( int x ) {
    prfx = sufx = sm = mx = x;
  }
  void marge( _node a, _node b ) {
    sm = a.sm+b.sm;
    mx = max(a.sufx+b.prfx, max(a.mx, b.mx));
    prfx = max(a.prfx, a.sm+b.prfx);
    sufx = max(b.sufx, b.sm+a.sufx);
  }
  int retmax() {
    return mx;
  }
} tree[3*MX];

_node mergelr( _node l, _node r ) {
  _node tmp;
  tmp.marge( l, r );
  return tmp;
}

void build( int node, int lo, int hi ) {
  if( lo==hi ) {
    tree[node].asign(a[lo]);
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = mergelr( tree[lft], tree[rgt] );
}

void update( int node, int lo, int hi, int pos, int v ) {
  if( lo==hi ) {
    tree[node].asign(v);
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( pos<=mid ) update( lft, lo, mid, pos, v );
  else update( rgt, mid+1, hi, pos, v );
  tree[node] = mergelr( tree[lft], tree[rgt] );
}

_node query_range( int node, int lo, int hi, int l, int r ) {
  if( lo>=l && hi<=r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( r<=mid ) {
    return query_range( lft, lo, mid, l, r );
  }
  else if( l>mid ) {
    return query_range( rgt, mid+1, hi, l, r );
  }
  else {
    _node p, q;
    p = query_range( lft, lo, mid, l, r );
    q = query_range( rgt, mid+1, hi, l, r );
    return mergelr( p, q );
  }
}

int main() {
  int n,Q;
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", a+i);
  }
  build( 1, 1, n );
  //cout<<tree[6].retmax()<<endl;
  scanf("%d", &Q);
  while( Q-- ) {
    int o, x, y;
    scanf("%d %d %d", &o, &x, &y);
    if( !o ) {
      update( 1, 1, n, x, y );
    }
    else {
      _node ans;
      ans = query_range( 1, 1, n, x, y );
      printf("%d\n", ans.retmax());
    }
  }
  return 0;
}

/**
4
1 2 3 4
4
1 1 3
0 3 -3
1 2 4
1 3 3
**/
