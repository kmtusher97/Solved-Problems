/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 112345;
static int node = 0;
int n, k, trie[5*MX][2][2];
bitset<25> bitk;

void Insert( int x )
{
  bitset<25> bitx = x;
  int now = 0;
  for(int i=25-1; i>=0; i--)
  {
    if( !trie[now][bitx[i]][0] )
    {
      trie[now][bitx[i]][0] = ++node;
      for(int j=0; j<2; j++)
      {
        trie[node][j][0] = trie[node][j][1] = 0;
      }
    }
    trie[now][bitx[i]][1]++;
    now = trie[now][bitx[i]][0];
  }
}

int query( int x )
{
  bitset<25> bitx = x;
  int now = 0, ret = 0;
  for(int i=25-1; i>=0; i--)
  {
    if( !bitk[i] )
    {
      now = trie[now][bitx[i]][0];
      if( !now ) return ret;
    }
    else
    {
      ret += trie[now][bitx[i]][1];
      now = trie[now][bitx[i]^1][0];
      if( !now ) return ret;
    }
  }
  return ret;
}

int main()
{
  int cases;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d", &n, &k);
    bitk = k;
    int xr = 0;
    intl res = 0LL;
    Insert( 0 );
    for(int i=0, x; i<n; i++)
    {
      scanf("%d", &x);
      xr ^= x;
      res += query( xr );
      Insert( xr );
    }
    printf("%lld\n", res);
    node = 0;
    for(int i=0; i<2; i++)
    {
      trie[0][i][0] = trie[0][i][1] = 0;
    }
  }
  return 0;
}
