/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 2123456;
int n, Q, N = 0, a[MX/10], b[MX/10];
static int nd = 0;
map<int, int> mp;
vector<int> head;

struct _node
{
  int lft, rgt, info;

  _node() : lft(0), rgt(0), info(0) { }
} tree[MX];

void _insert( int pre, int cur, int lo, int hi, int pos, int v )
{
  if( lo==hi )
  {
    tree[cur].info = tree[pre].info + v;
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

int _query( int pre, int cur, int lo, int hi, int k )
{
  if( lo==hi )
  {
    return lo;
  }

  int mid = lo+(hi-lo)/2;
  int rst = tree[tree[cur].lft].info - tree[tree[pre].lft].info;
  if( rst>=k )
  {
    return _query( tree[pre].lft, tree[cur].lft, lo, mid, k );
  }
  else
  {
    return _query( tree[pre].rgt, tree[cur].rgt, mid+1, hi, k-rst );
  }
}

int main()
{
  scanf("%d %d", &n, &Q);
  for(int i=1; i<=n; i++)
  {
    scanf("%d", a+i);
    b[i] = a[i];
  }

  sort(b+1, b+n+1);
  for(int i=1, j=0; i<=n; i++)
  {
    if( mp.find(b[i])==mp.end() )
    {
      mp[b[i]] = ++j, N = max(N, j);
    }
  }

  head.push_back(0);
  for(int i=1; i<=n; i++)
  {
    head.push_back(++nd);
    _insert( head[i-1], head[i], 1, N, mp[a[i]], 1 );
  }

  while( Q-- )
  {
    int l, r, k;
    scanf("%d %d %d", &l ,&r, &k);
    int id = _query( head[l-1], head[r], 1, N, k );
    printf("%d\n", b[id]);
  }
  return 0;
}
