/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/
#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;
int n;
vector<int> g[MX];
bitset<MX> mark;

void dfs( int u )
{
  mark[u] = true;
  for(int i=0; i<g[u].size(); i++)
  {
    int v = g[u][i];
    if( !mark[v] ) dfs( v );
  }
}

int main()
{
  int cases;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &n);
    for(int i=1, m; i<=n; i++)
    {
      scanf("%d", &m);
      for(int j=1, v; j<=m; j++)
      {
        scanf("%d", &v);
        g[v].push_back(i);
      }
    }
    int res = 0;
    for(int i=1; i<=n; i++)
    {
      mark = 0;
      dfs( i );
      if( mark.count()==n ) res++;
    }
    printf("%d\n", res);
    for(int i=0; i<MX; i++) g[i].clear();
  }
  return 0;
}
