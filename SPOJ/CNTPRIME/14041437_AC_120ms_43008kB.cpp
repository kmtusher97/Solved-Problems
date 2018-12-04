/* BISMILLAHIR RAHMANIR RAHIM */

#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sc scanf
#define pf printf
#define pb push_back

#define F first
#define S second

typedef long long intl;
typedef unsigned long long intu;
typedef queue<int> qi;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define MX_N 112345

const int MX = 1123456;
intl n, Q, a[MX], tree[MX], lazy[MX];
bool mark[MX];

void sieve() {
  intl i, j;
  mark[0] = mark[1] = true;
  for(i=2; i<sqrt(MX); i++) if( !mark[i] ) {
    for(j=i+i; j<MX; j+=i) mark[j] = true;
  }
}

void build( int node, int lo, int hi ) {
  if( lo==hi ) {
    tree[node] = !mark[a[lo]] ? 1 : 0;
    lazy[node] = 0;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = tree[lft] + tree[rgt];
  lazy[node] = lazy[lft] = lazy[rgt] = 0;
}

void propagate( int node, int lo, int hi ) {
  if( !mark[lazy[node]] ) tree[node] = hi-lo+1;
  else tree[node] = 0;
  if( lo!=hi ) {
    int lft = node<<1, rgt = lft|1;
    lazy[lft] = lazy[rgt] = lazy[node];
  }
  lazy[node] = 0;
}

void update( int node, int lo, int hi, int l, int r, intl v ) {
  if( lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return;
  if( lo>=l && hi<=r ) {
    lazy[node] = v;
    propagate( node, lo, hi );
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  update( lft, lo, mid, l, r, v );
  update( rgt, mid+1, hi, l, r, v );
  tree[node] = tree[lft] + tree[rgt];
}

intl query( int node, int lo, int hi, int l, int r ) {
  if( lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  intl pp = query( lft, lo, mid, l, r );
  intl qq = query( rgt, mid+1, hi, l, r );
  return pp+qq;
}

int main() {
  sieve();

  int cases, caseno = 0;
  sc("%d", &cases);
  while( cases-- ) {
    sc("%lld %lld", &n, &Q);
    for(int i=1; i<=n; i++) sc("%lld", a+i);
    build( 1, 1, n );
    pf("Case %d:\n", ++caseno);
    while( Q-- ) {
      int t, l, r, x;
      sc("%d %d %d", &t, &l, &r);
      if( !t ) {
        sc("%d", &x);
        update( 1, 1, n, l, r, x );
      }
      else {
        intl res = query( 1, 1, n, l, r );
        pf("%lld\n", res);
      }
    }
  }
  return 0;
}
