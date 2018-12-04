/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

const int MX = 2123456;
int n, Q, last_pos[MX/2];
static int nd = 0;
vi head;

struct _node
{
  int lft, rgt, info;

  _node() : lft(0), rgt(0), info(0) { }
} tree[MX];

void _insert( int pre, int cur, int lo, int hi, int pos, int v )
{
  if( lo==hi )
  {
    tree[cur].info = tree[pre].info+v;
    return;
  }

  int mid = lo+(hi-lo)/2;
  if( pos<=mid )
  {
    if( tree[cur].lft==0 ) tree[cur].lft = ++nd;
    tree[cur].rgt = tree[pre].rgt;
    _insert( tree[pre].lft, tree[cur].lft, lo, mid, pos, v );
  }
  else
  {
    if( tree[cur].rgt==0 ) tree[cur].rgt = ++nd;
    tree[cur].lft = tree[pre].lft;
    _insert( tree[pre].rgt, tree[cur].rgt, mid+1, hi, pos, v );
  }
  tree[cur].info = tree[tree[cur].lft].info + tree[tree[cur].rgt].info;
}

int _query( int node, int lo, int hi, int l, int r )
{
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node].info;

  int mid = lo+(hi-lo)/2;
  int pp = _query( tree[node].lft, lo, mid, l, r );
  int qq = _query( tree[node].rgt, mid+1, hi, l, r );
  return pp+qq;
}

int main()
{
  scanf("%d", &n);
  head.push_back(0);
  for(int i=1, a; i<=n; i++)
  {
    scanf("%d", &a);
    head.push_back(++nd);
    if( last_pos[a]!=0 )
    {
      _insert( head[i-1], head[i], 1, n, last_pos[a], -1 );
      _insert( head[i], head[i], 1, n, i, 1 );
      last_pos[a] = i;
    }
    else
    {
      last_pos[a] = i;
      _insert( head[i-1], head[i], 1, n, i, 1 );
    }
  }

  scanf("%d", &Q);
  while( Q-- )
  {
    int l, r;
    scanf("%d %d", &l, &r);
    int cnt = _query( head[r], 1, n, l, r );
    printf("%d\n", cnt);
  }
  return 0;
}