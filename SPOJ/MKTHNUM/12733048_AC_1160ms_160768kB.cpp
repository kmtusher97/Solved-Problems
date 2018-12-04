/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 11234567;
int n, Q, N, a[MX/10], b[MX/10];
static int nd = 0;
map<int, int> mp;
vector<int> head;

struct _node
{
  int lft, rgt, info;

  _node() : lft(0), rgt(0), info(0) { }
} tree[MX];

void _insert( int cur, int pre, int lo, int hi, int pos, int v )
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
    _insert( tree[cur].lft, tree[pre].lft, lo, mid, pos, v );
  }
  else
  {
    if( tree[cur].rgt==0 ) tree[cur].rgt = ++nd;
    tree[cur].lft = tree[pre].lft;
    _insert( tree[cur].rgt, tree[pre].rgt, mid+1, hi, pos, v );
  }
  tree[cur].info = tree[tree[cur].lft].info + tree[tree[cur].rgt].info;
}

int _query( int l, int r, int lo, int hi, int k )
{
  if( lo==hi )
  {
    return lo;
  }

  int mid = lo+(hi-lo)/2;
  int dif = tree[tree[r].lft].info - tree[tree[l].lft].info;
  if( dif>=k )
  {
    return _query( tree[l].lft, tree[r].lft, lo, mid, k );
  }
  else
  {
    return _query( tree[l].rgt, tree[r].rgt, mid+1, hi, k-dif );
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
      mp[b[i]] = ++j;
      N = max(j, N);
    }
  }

  head.push_back(0);
  for(int i=1; i<=n; i++)
  {
    head.push_back( ++nd );
    _insert( head[i], head[i-1], 1, N, mp[a[i]], 1 );
  }

  while( Q-- )
  {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    int id = _query( head[l-1], head[r], 1, N, k );
    printf("%d\n", b[id]);
  }
  return 0;
}
