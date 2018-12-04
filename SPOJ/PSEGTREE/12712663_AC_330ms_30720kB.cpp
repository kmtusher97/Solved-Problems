/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 123456;
int n, Q;
static int nd = 1;
vector<int> head;

struct _node
{
  int lft, rgt, info;

  _node() : lft(0), rgt(0), info(0) { }
} tree[MX*10];

void _insert( int node, int pre, int lo, int hi, int pos, int v )
{
  if( lo==hi )
  {
    tree[node].info = tree[pre].info+v;
    return;
  }

  int mid = lo+(hi-lo)/2;
  if( pos<=mid )
  {
    if( tree[node].lft==0 ) tree[node].lft = ++nd;
    tree[node].rgt = tree[pre].rgt;
    _insert( tree[node].lft, tree[pre].lft, lo, mid, pos, v );
  }
  else
  {
    if( tree[node].rgt==0 ) tree[node].rgt = ++nd;
    tree[node].lft = tree[pre].lft;
    _insert( tree[node].rgt, tree[pre].rgt, mid+1, hi, pos, v );
  }

  tree[node].info = tree[tree[node].lft].info + tree[tree[node].rgt].info;
}

int _query( int node, int lo, int hi, int l, int r )
{
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node].info;

  int mid = lo+(hi-lo)/2;
  int pp = _query( tree[node].lft, lo, mid, l, r );
  int qq = _query( tree[node].rgt, mid+1, hi, l ,r );
  return pp+qq;
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n;
  for(int i=1, a; i<=n; i++)
  {
    cin>>a;
    _insert( 1, 1, 1, n, i, a );
  }
  head.push_back(1);
  cin>>Q;
  while( Q-- )
  {
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if( a==1 )
    {
      head.push_back(++nd);
      _insert( nd, head[b], 1, n, c, d );
    }
    else
    {
      int ans = _query( head[b], 1, n, c, d );
      cout<<ans<<endl;
    }
  }
  return 0;
}
