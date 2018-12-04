/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 212345;
int n, Q;
intl tree[MX];

void update( int id, intl v )
{
  for(; id<=n+5; id+=(id&-id))
  {
    tree[id] += v;
  }
}

intl query( int id )
{
  intl sm = 0;
  for(; id>0; id-=(id&-id))
  {
    sm += tree[id];
  }
  return sm;
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &Q);
    for(int i=1, x; i<=n; i++)
    {
      scanf("%d", &x);
      update( i, x );
    }
    printf("Case %d:\n", ++caseno);
    while( Q-- )
    {
      int t, i;
      scanf("%d %d", &t, &i), i++;
      if( t==1 )
      {
        intl res = query( i ) - query( i-1 );
        update( i, -res );
        printf("%lld\n", res);
      }
      else if( t==2 )
      {
        int v;
        scanf("%d", &v);
        update( i, v );
      }
      else
      {
        int j;
        scanf("%d", &j), j++;
        intl res = query( j ) - query( i-1 );
        printf("%lld\n", res);
      }
    }
    memset(tree, 0, sizeof tree);
  }
  return 0;
}
