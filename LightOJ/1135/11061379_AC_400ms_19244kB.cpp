#include <bits/stdc++.h>
using namespace std;

const int MX = 1123456;
int lazy[MX];

struct data {
  int e[3];
} tree[MX];

void propagate( int node, int lo, int hi ) {
  int x, y, z, t[3];
  x = (0+lazy[node])%3;
  y = (1+lazy[node])%3;
  z = (2+lazy[node])%3;
  t[0] = tree[node].e[0];
  t[1] = tree[node].e[1];
  t[2] = tree[node].e[2];
  tree[node].e[0] = t[x];
  tree[node].e[1] = t[y];
  tree[node].e[2] = t[z];
  if( lo != hi ) {
    lazy[node<<1] += lazy[node];
    lazy[(node<<1)|1] += lazy[node];
  }
  lazy[node] = 0;
}

data marge( int lft, int rgt ) {
  data tmp;
  tmp.e[0] = tree[lft].e[0] + tree[rgt].e[0];
  tmp.e[1] = tree[lft].e[1] + tree[rgt].e[1];
  tmp.e[2] = tree[lft].e[2] + tree[rgt].e[2];
  return tmp;
}

void build( int node, int lo, int hi ) {
  if( lo == hi ) {
    tree[node].e[0] = 1;
    tree[node].e[1] = tree[node].e[2] = lazy[node] = 0;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = marge( lft, rgt );
  lazy[node] = 0;
}

void update_range( int node, int lo, int hi, int l, int r ) {
  if( lazy[node] != 0 ) propagate( node, lo, hi );
  if( lo > r || hi < l ) return;
  if( lo >= l && hi <= r ) {
    ++lazy[node];
    propagate( node, lo, hi );
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  update_range( lft, lo, mid, l, r );
  update_range( rgt, mid+1, hi, l, r );
  tree[node] = marge( lft, rgt );
}

int query( int node, int lo, int hi, int l, int r ) {
  if( lazy[node] != 0 ) propagate( node, lo, hi );
  if( lo > r || hi < l ) return 0;
  if( lo >= l && hi <= r ) return tree[node].e[0];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  int p = query( lft, lo, mid, l, r );
  int q = query( rgt, mid+1, hi, l, r );
  return p+q;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    int n, Q;
    scanf("%d %d", &n, &Q);
    build( 1, 0, n-1 );
    printf("Case %d:\n", ++caseno);
    while( Q-- ) {
      int op, l, r;
      scanf("%d %d %d", &op, &l, &r);
      if( !op ) {
        update_range( 1, 0, n-1, l, r );
      }
      else {
        printf("%d\n", query( 1, 0, n-1, l, r ));
      }
    }
  }
  return 0;
}
