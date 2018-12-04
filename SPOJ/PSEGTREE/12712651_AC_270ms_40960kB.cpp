/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 2123456;
int n, Q;
static int nd = 1;
vector<int> head;

struct _node
{
  int lft, rgt, info;

  _node() : lft(0), rgt(0), info(0) { }
} tree[MX];

void _insert( int node, int pre, int lo, int hi, int pos, int v )
{
  if( lo==hi )
  {
    tree[node].info = tree[pre].info+v;
    return;
  }

  int mid = lo+(hi-lo)/2, lf = tree[node].lft, rt = tree[node].rgt;
  if( pos<=mid )
  {
    if( lf==0 ) lf = ++nd;
    tree[node].lft = lf;
    tree[node].rgt = tree[pre].rgt;
    _insert( lf, tree[pre].lft, lo, mid, pos, v );
  }
  else
  {
    if( rt==0 ) rt = ++nd;
    tree[node].lft = tree[pre].lft;
    tree[node].rgt = rt;
    _insert( rt, tree[pre].rgt, mid+1, hi, pos, v );
  }

  tree[node].info = tree[tree[node].lft].info + tree[tree[node].rgt].info;
}

int _query( int node, int lo, int hi, int l, int r )
{
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node].info;

  int mid = lo+(hi-lo)/2, lf = tree[node].lft, rt = tree[node].rgt;
  int pp = _query( lf, lo, mid, l, r );
  int qq = _query( rt, mid+1, hi, l ,r );
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
