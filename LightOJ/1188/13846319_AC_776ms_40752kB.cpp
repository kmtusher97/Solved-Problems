/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 2000002;
static int nd;
int n, Q, head[MX], last[MX];

struct Node
{
  int lft, rgt, info;
  Node() { lft = rgt = info = 0; }
  void init() { lft = rgt = info = 0; }
} tree[MX];

void Insert( int pre, int cur, int lo, int hi, int pos, int v )
{
  if( lo==hi )
  {
    tree[cur].info = tree[pre].info + v;
    return;
  }
  int mid = lo + (hi-lo)/2;
  if( pos<=mid )
  {
    if( !tree[cur].lft ) tree[cur].lft = ++nd, tree[nd].init();
    tree[cur].rgt = tree[pre].rgt;
    Insert( tree[pre].lft, tree[cur].lft, lo, mid, pos, v );
  }
  else
  {
    if( !tree[cur].rgt ) tree[cur].rgt = ++nd, tree[nd].init();
    tree[cur].lft = tree[pre].lft;
    Insert( tree[pre].rgt, tree[cur].rgt, mid+1, hi, pos, v );
  }
  tree[cur].info = tree[tree[cur].lft].info + tree[tree[cur].rgt].info;
}

int Query( int node, int lo, int hi, int L, int R )
{
  if( lo>R || hi<L ) return 0;
  if( lo>=L && hi<=R ) return tree[node].info;
  int mid = lo + (hi-lo)/2;
  int pp = Query( tree[node].lft, lo, mid, L, R );
  int qq = Query( tree[node].rgt, mid+1, hi, L, R );
  return pp+qq;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &Q);
    nd = 0;
    for(int i=1, x; i<=n; i++)
    {
      scanf("%d", &x);
      head[i] = ++nd, tree[nd].init();
      if( last[x] )
      {
        Insert( head[i-1], head[i], 1, n, last[x], -1 );
        Insert( head[i], head[i], 1, n, i, 1 );
      }
      else
      {
        Insert( head[i-1], head[i], 1, n, i, 1 );
      }
      last[x] = i;
    }
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      int l, r;
      scanf("%d %d", &l, &r);
      printf("%d\n", Query( head[r], 1, n, l, r ));
    }
    memset(last, 0, sizeof last);
  }
  return 0;
}
