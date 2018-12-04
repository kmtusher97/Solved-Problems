/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const int MX = 1123456;
int n, a[MX];

struct Node
{
  int mxsm, prfx, sufx, sm;
  Node() { mxsm = prfx = sufx = sm = 0; }
  void asign( int x ) { mxsm = prfx = sufx = sm = x; }
} tree[MX];

Node Merge( Node l, Node r )
{
  Node p;
  p.mxsm = max(l.sufx+r.prfx, max(l.mxsm, r.mxsm));
  p.sm = l.sm + r.sm;
  p.prfx = max(l.prfx, l.sm+r.prfx);
  p.sufx = max(r.sufx, r.sm+l.sufx);
  return p;
}

void build( int node, int lo, int hi )
{
  if( lo==hi )
  {
    tree[node].asign( a[lo] );
    return;
  }

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );

  tree[node] = Merge( tree[lft], tree[rgt] );
}

Node query_range( int node, int lo, int hi, int L, int R )
{
  if( lo>=L && hi<=R ) return tree[node];

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( R<=mid )
  {
    return query_range( lft, lo, mid, L, R );
  }
  else if( L>mid )
  {
    return query_range( rgt, mid+1, hi, L, R );
  }
  else
  {
    Node pp = query_range( lft, lo, mid, L, R );
    Node qq = query_range( rgt, mid+1, hi, L, R );
    return Merge( pp, qq );
  }
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
  }
  build( 1, 1, n );

  int Q, l, r;
  cin>>Q;
  while( Q-- )
  {
    cin>>l>>r;
    Node res = query_range( 1, 1, n, l, r );
    cout<<res.mxsm<<endl;
  }
  return 0;
}
