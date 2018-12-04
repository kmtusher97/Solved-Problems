/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<intl, intl> pii;

const int MX = 112345;
int n, K, a[MX];

struct SegmentTree
{
  intl tree[MX];
  void build( int node, int lo, int hi )
  {
    if( lo==hi )
    {
      tree[node] = a[lo];
      return;
    }
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    build( lft, lo, mid );
    build( rgt, mid+1, hi );
    tree[node] = tree[lft] & tree[rgt];
  }
  intl query( int node, int lo, int hi, int L, int R )
  {
    if( lo>R || hi<L ) return INT_MAX;
    if( lo>=L && hi<=R ) return tree[node];
    int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
    intl p = query( lft, lo, mid, L, R );
    intl q = query( rgt, mid+1, hi, L, R );
    return p&q;
  }
} sg;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>n>>K;
    for(int i=1; i<=n; i++)
    {
      cin>>a[i];
      a[n+i] = a[2*n+i] = a[i];
    }
    sg.build( 1, 1, 3*n );
    for(int i=n+1; i<=2*n; i++)
    {
      int L = max(1, i-K);
      int R = min(3*n, i+K);
      cout<<sg.query( 1, 1, 3*n, L, R );
      if( i==2*n ) cout<<endl;
      else cout<<" ";
    }
  }
  return 0;
}
