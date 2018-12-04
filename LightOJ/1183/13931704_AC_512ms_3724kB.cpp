/* ~*BISMILLAHIR RAHMANIR RAHIM *~ */

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MX_N 112345

int n, Q, tree[3*MX_N][2];

void propagate( int& node, int& lo, int& hi )
{
  tree[node][0] = (hi-lo+1) * tree[node][1];
  if( lo!=hi )
  {
    tree[node<<1][1] = tree[(node<<1)|1][1] = tree[node][1];
  }
  tree[node][1] = -1;
}

void update( int node, int lo, int hi, int l, int r, int v )
{
  if( ~tree[node][1] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return;
  if( lo>=l && hi<=r )
  {
    tree[node][1] = v;
    propagate( node, lo, hi );
    return;
  }

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  update( lft, lo, mid, l, r, v );
  update( rgt, mid+1, hi, l, r, v );
  tree[node][0] = tree[lft][0] + tree[rgt][0];
}

int query( int node, int lo, int hi, int l, int r )
{
  if( ~tree[node][1] ) propagate( node, lo, hi );
  if( lo>r || hi<l ) return 0;
  if( lo>=l && hi<=r ) return tree[node][0];

  int mid = lo+(hi-lo)/2, lft = node<<1, rgt = lft|1;
  int L = query( lft, lo, mid, l, r );
  int R = query( rgt, mid+1, hi, l, r );
  return L + R;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &Q);
    memset(tree, 0, sizeof tree);
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      int t, l, r, v;
      scanf("%d %d %d", &t, &l, &r);
      if( t==1 )
      {
        scanf("%d", &v);
        update( 1, 0, n-1, l, r, v );
      }
      else
      {
        int res_n = query( 1, 0, n-1, l, r ), res_d = r-l+1;
        int gcd = __gcd( res_n, res_d );
        printf("%d", res_n/gcd);
        if( res_d/gcd!=1 ) printf("/%d", res_d/gcd);
        printf("\n");
      }
    }
  }
  return 0;
}
