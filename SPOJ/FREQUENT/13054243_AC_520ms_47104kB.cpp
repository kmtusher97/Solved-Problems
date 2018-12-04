/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
int n, Q, a[MX];

struct Node
{
  int e, f, pe, pf, se, sf;
  Node() { e = f = pe = pf = se = sf = 0; };

} tree[MX];

Node marge( Node L, Node R )
{
  Node t;
  if( L.e==R.e ) t.e = L.e, t.f = L.f + R.f;
  else
  {
    if( L.f>R.f ) t.e = L.e, t.f = L.f;
    else t.e = R.e, t.f = R.f;
  }

  if( L.se==R.pe && L.sf+R.pf>t.f )
  {
    t.e = L.se, t.f = L.sf+R.pf;
  }

  t.pe = L.pe, t.pf = L.pf;
  t.se = R.se, t.sf = R.sf;
  if( L.pe==R.pe ) t.pf += R.pf;
  if( R.se==L.se ) t.sf += L.sf;
  return t;
}

void build( int node, int lo, int hi )
{
  if( lo==hi )
  {
    tree[node].e = tree[node].pe = tree[node].se = a[lo];
    tree[node].f = tree[node].pf = tree[node].sf = 1;
    return;
  }

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  build( lft, lo, mid );
  build( rgt, mid+1, hi );
  tree[node] = marge( tree[lft], tree[rgt] );
}

Node query( int node, int lo, int hi, int L, int R )
{
  if( lo>=L && hi<=R ) return tree[node];

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  if( R<=mid ) return query( lft, lo, mid, L, R );
  else if( L>mid ) return query( rgt, mid+1, hi, L, R );
  else
  {
    Node ll, rr;
    ll = query( lft, lo, mid, L, R );
    rr = query( rgt, mid+1, hi, L, R );
    return marge( ll, rr );
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin>>n && n )
  {
    cin>>Q;
    for(int i=1; i<=n; i++) cin>>a[i];
    build( 1, 1, n );
    while( Q-- )
    {
      int l, r;
      cin>>l>>r;
      Node ans = query( 1, 1, n, l, r );
      cout<<ans.f<<endl;
    }
  }
  return 0;
}
