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

const int MX = 123456;
intl tree[3*MX], lazy[3*MX];

void build( int node, int lo, int hi ) {
  if( lo==hi ) tree[node] = lazy[node] = 0LL;
  else {
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    build( lft, lo, mid );
    build( rgt, mid+1, hi );
    tree[node] = lazy[node] = 0LL;
  }
}

void propagate( int node, int lo, int hi ) {
  tree[node] += ( (hi-lo+1) * lazy[node] );
  if( lo!=hi ) {
    lazy[node<<1] += lazy[node];
    lazy[(node<<1)|1] += lazy[node];
  }
  lazy[node] = 0LL;
}

void update_range( int node, int lo, int hi, int l, int r, int v ) {
  if( lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return;
  if( lo>=l && hi<=r ) {
    lazy[node] += v;
    propagate( node, lo, hi );
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  update_range( lft, lo, mid, l, r, v );
  update_range( rgt, mid+1, hi, l, r, v );
  tree[node] = tree[lft] + tree[rgt];
}

intl query( int node, int lo, int hi, int l, int r ) {
  if( lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return 0LL;
  if( lo>=l && hi<=r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  intl p = query( lft, lo, mid, l, r );
  intl q = query( rgt, mid+1, hi, l, r );
  return p+q;
}

int main() {
  int cases, caseno = 0, n, Q;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &Q);
    build( 1, 0, n-1 );
    printf("Case %d:\n", ++caseno);
    while( Q-- ) {
      int o, x, y, v;
      scanf("%d %d %d", &o, &x, &y);
      if( !o ) {
        scanf("%d", &v);
        update_range( 1, 0, n-1, x, y, v );
      }
      else {
        intl sum = query( 1, 0, n-1, x, y );
        printf("%lld\n", sum);
      }
    }
  }
  return 0;
}

