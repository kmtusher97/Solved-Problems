/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;

const int MX = 112345;
intl n, Q, tree[3*MX], lazy[3*MX];

void propagate( int node, int lo, int hi )
{
  tree[node] = (hi-lo+1)*lazy[node];
  if( lo!=hi )
  {
    lazy[node<<1] = lazy[node];
    lazy[(node<<1)|1] = lazy[node];
  }
  lazy[node] = -1;
}

void update( int node, int lo, int hi, int l, int r, intl v )
{
  if( ~lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return;
  if( lo>=l && hi<=r )
  {
    lazy[node] = v;
    propagate( node, lo, hi );
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  update( lft, lo, mid, l, r, v );
  update( rgt, mid+1, hi, l, r, v );
  tree[node] = tree[lft] + tree[rgt];
}

intl query( int node, int lo, int hi, int l, int r )
{
  if( ~lazy[node] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  intl p = query( lft, lo, mid, l, r );
  intl q = query( rgt, mid+1, hi, l, r );
  return p+q;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%lld %lld", &n, &Q);
    for(int i=0; i<3*MX; i++) tree[i] = 0, lazy[i] = -1;
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      int t, l, r, v;
      scanf("%d %d %d", &t, &l, &r);
      if( t==1 )
      {
        scanf("%d", &v);
        update( 1, 0, n-1, l, r, v );
      }
      else
      {
        intl nmtr = query( 1, 0, n-1, l, r ), dnmtr = r-l+1;
        intl gcd = __gcd(nmtr, dnmtr);
        printf("%lld", nmtr/gcd);
        if( dnmtr/gcd!=1 ) printf("/%lld", dnmtr/gcd);
        printf("\n");
      }
    }
  }
  return 0;
}
