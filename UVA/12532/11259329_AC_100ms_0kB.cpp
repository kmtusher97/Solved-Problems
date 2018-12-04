#include <bits/stdc++.h>
using namespace std;

const int MX = 112345;
int tree[3*MX];

void build( int node, int lo, int hi )
{
  if( lo == hi )
  {
    int x;
    scanf("%d", &x);
    if( x > 0 ) tree[node] = 1;
    else if( x < 0 ) tree[node] = -1;
    else tree[node] = 0;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = tree[lft] * tree[rgt];
}

void update( int node, int lo, int hi, int pos, int v )
{
  if( lo == hi )
  {
    if( v > 0 ) tree[node] = 1;
    else if( v < 0 ) tree[node] = -1;
    else tree[node] = 0;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( pos <= mid )
  {
    update( lft, lo, mid, pos, v );
  }
  else
  {
    update( rgt, mid+1, hi, pos, v );
  }
  tree[node] = tree[lft] * tree[rgt];
}

int query( int node, int lo, int hi, int l, int r )
{
  if( lo >= l && hi <= r )
  {
    return tree[node];
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( r <= mid )
  {
    return query( lft, lo, mid, l, r );
  }
  else if( l > mid )
  {
    return query( rgt, mid+1, hi, l, r );
  }
  else
  {
    return query( lft, lo, mid, l, r ) * query( rgt, mid+1, hi, l ,r );
  }
}

int main()
{
  int n, Q;
  while( ~scanf("%d %d", &n, &Q) )
  {
    build( 1, 1, n );
    while( Q-- )
    {
      char ch[2];
      int a, b;
      scanf("%s %d %d", ch, &a, &b);
      if( ch[0] == 'C' )
      {
        update( 1, 1, n, a, b );
      }
      else
      {
        int ans = query( 1, 1, n, a, b );
        if( ans == 0 ) printf("0");
        else if( ans == 1 ) printf("+");
        else printf("-");
      }
    }
    printf("\n");
  }
  return 0;
}
