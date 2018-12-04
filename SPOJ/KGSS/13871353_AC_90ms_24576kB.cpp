/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 212345;
intl n, Q, a[MX];

struct Node
{
  intl mx, res;
  Node() { mx = res = 0; }
  Node( intl x ) { mx = res = x; }
} tree[MX*2];

Node marge( Node a, Node b )
{
  Node tmp;
  tmp.mx = max( a.mx, b.mx );
  tmp.res = max( a.mx+b.mx, max( a.res, b.res ) );
  return tmp;
}

void build( int node, int lo, int hi )
{
  if( lo==hi )
  {
    tree[node].mx = tree[node].res = a[lo];
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = marge( tree[lft], tree[rgt] );
}

void update( int node, int lo, int hi, int pos, intl v )
{
  if( lo==hi )
  {
    tree[node].mx = tree[node].res = v;
    return;
  }
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( pos<=mid ) update( lft, lo, mid, pos, v );
  else update( rgt, mid+1, hi, pos, v );
  tree[node] = marge( tree[lft], tree[rgt] );
}

Node query( int node, int lo, int hi, int l, int r )
{
  if( lo>r || hi<l ) return Node( -1e12 );
  if( lo>=l && hi<=r ) return tree[node];
  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( r<=mid ) return query( lft, lo, mid, l, r );
  else if( l>mid ) return query( rgt, mid+1, hi, l, r );
  else
  {
    return marge( query( lft, lo, mid, l, r ), query( rgt, mid+1, hi, l, r ) );
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n;
  for(int i=1; i<=n; i++) cin>>a[i];
  build( 1, 1, n );
  cin>>Q;
  while( Q-- )
  {
    string t;
    intl l, r;
    cin>>t>>l>>r;
    if( t=="U" )
    {
      update( 1, 1, n, l, r );
    }
    else
    {
      cout<<query( 1, 1, n, l, r ).res<<endl;
    }
  }
  return 0;
}
