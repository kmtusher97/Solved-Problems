/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 1523456
int tree[MX_N*6], res[MX_N];

void build( int node, int lo, int hi ) {
  if( lo==hi ) {
    tree[node] = (lo&1);
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = tree[lft] + tree[rgt];
}

void update( int node, int lo, int hi, int k ) {
  if( lo==hi ) {
    tree[node] = 0;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( k<=tree[lft] ) update( lft, lo, mid, k );
  else update( rgt, mid+1, hi, k-tree[lft] );
  tree[node] = tree[lft] + tree[rgt];
}

int query( int node, int lo, int hi, int k ) {
  if( lo==hi ) return lo;
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( k<=tree[lft] ) return query( lft, lo, mid, k );
  else return query( rgt, mid+1, hi, k-tree[lft] );
}

int main() {
  build( 1, 1, MX_N );
  res[1] = 1;
  for(int i=2; i<100005; i++) {
    int tmp = query( 1, 1, MX_N, i );
    res[i] = tmp;
    for(int j=tmp; j<MX_N; j+=(tmp-1)) {
      update( 1, 1, MX_N, j );
    }
  }

  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    int n; scanf("%d", &n);
    printf("Case %d: %d\n", ++caseno, res[n]);
  }
  return 0;
}
