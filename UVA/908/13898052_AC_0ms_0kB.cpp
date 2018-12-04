/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MX = 1000005;
int n, m, k, prnt[MX];
vector<piii> edge;

int unionfind( int u )
{
  while( prnt[u]!=u )
  {
    prnt[u] = prnt[prnt[u]];
    u = prnt[u];
  }
  return u;
}

intl krushkal()
{
  intl cost = 0, cnt = 0;
  for(piii i : edge)
  {
    int u = i.S.F;
    int v = i.S.S;
    if( unionfind(u)!=unionfind(v) )
    {
      cost += i.F, cnt++;
      prnt[v] = prnt[unionfind(u)];
    }
    if( cnt==n-1 ) break;
  }
  return cost;
}

int main()
{
  int caseno = 0;
  while( scanf("%d", &n)==1 )
  {
    if( caseno++ ) printf("\n");
    intl cost1 = 0, cost2 = 0;
    for(int i=0; i<=n; i++) prnt[i] = i;
    for(int i=1, u, v, w; i<n; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      cost1 += w;
    }
    scanf("%d", &k), edge.clear();
    for(int i=1, u, v, w; i<=k; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      edge.push_back( piii(w, pii(u, v)) );
    }
    scanf("%d", &m);
    for(int i=1, u, v, w; i<=m; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      edge.push_back( piii(w, pii(u, v)) );
    }
    sort(edge.begin(), edge.end());
    cost2 = krushkal();
    printf("%lld\n%lld\n", cost1, cost2);
  }
  return 0;
}
