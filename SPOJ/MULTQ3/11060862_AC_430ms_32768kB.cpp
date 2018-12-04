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

data marge( data lft, data rgt ) {
  data tmp;
  tmp.e[0] = lft.e[0] + rgt.e[0];
  tmp.e[1] = lft.e[1] + rgt.e[1];
  tmp.e[2] = lft.e[2] + rgt.e[2];
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
  tree[node] = marge( tree[lft], tree[rgt] );
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
  tree[node] = marge( tree[lft], tree[rgt] );
}

data query( int node, int lo, int hi, int l, int r ) {
  if( lazy[node] != 0 ) propagate( node, lo, hi );
  if( lo >= l && hi <= r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( r <= mid ) return query( lft, lo, mid, l, r );
  else if( l > mid ) return query( rgt, mid+1, hi, l, r );
  else return marge( query( lft, lo, mid, l, r ), query( rgt, mid+1, hi, l, r ) );
}

int main() {
  int n, Q;
  scanf("%d %d", &n, &Q);
  build( 1, 0, n-1 );
  while( Q-- ) {
    int op, l, r;
    scanf("%d %d %d", &op, &l, &r);
    if( !op ) {
      update_range( 1, 0, n-1, l, r );
    }
    else {
      printf("%d\n", query( 1, 0, n-1, l, r ).e[0]);
    }
  }
  return 0;
}
