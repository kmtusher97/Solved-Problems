/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 112345;
int Q, n, tree[MX*5], lazy[MX*5];
bitset<3*MX> vis;

void propagate( int node, int lo, int hi )
{
  tree[node] = (hi-lo+1) * lazy[node];
  if( lo!=hi )
  {
    lazy[node<<1] = lazy[node];
    lazy[(node<<1)|1] = lazy[node];
  }
  lazy[node] = 0;
}

void update( int node, int lo, int hi, int l, int r, int v )
{
  if( lo>r || hi<l ) return;
  if( lazy[node] ) propagate( node, lo, hi );
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

int query( int node, int lo, int hi, int l, int r )
{
  if( lo>r || hi<l ) return 0;
  if( lazy[node] ) propagate( node, lo, hi );
  if( lo>=l && hi<=r ) return tree[node];

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  int p = query( lft, lo, mid, l, r );
  int q = query( rgt, mid+1, hi, l, r );
  return p+q;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &Q), n=MX*2;
    int color = 0;
    while( Q-- )
    {
      int l, r;
      scanf("%d %d", &l, &r);
      update( 1, 1, n, l, r, ++color );
    }
    int cnt = 0;
    for(int i=1; i<n; i++)
    {
      int res = query( 1, 1, n, i, i );
      if( res && !vis[res] ) cnt++;
      vis[res] = true;
    }
    printf("Case %d: %d\n", ++caseno, cnt);
    memset(tree, 0, sizeof tree);
    memset(lazy, 0, sizeof lazy);
    vis.reset();
  }
  return 0;
}
