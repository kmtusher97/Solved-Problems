/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef pair<int, int> pii;

const int MX = 21234;
int n, m, s, t, dist[MX];
vector<pii> g[MX];

void dijkstra( int src )
{
  for(int i=0; i<=n; i++) dist[i] = INT_MAX;
  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push( pii(0, src) ), dist[src] = 0;

  while( !pq.empty() )
  {
    pii u = pq.top(); pq.pop();
    if( u.F>dist[u.S] ) continue;
    for(pii v : g[u.S])
    {
      if( v.F+dist[u.S]<dist[v.S] )
      {
        dist[v.S] = v.F+dist[u.S];
        pq.push( pii(dist[v.S], v.S) );
      }
    }
  }
}

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for(int i=0; i<=n; i++) g[i].clear();
    for(int i=1, u, v, w; i<=m; i++)
    {
      scanf("%d %d %d", &u, &v, &w);
      g[u].push_back( pii(w, v) );
      g[v].push_back( pii(w, u) );
    }
    dijkstra( s );
    printf("Case #%d: ", ++caseno);
    if( dist[t]==INT_MAX ) printf("unreachable\n");
    else printf("%d\n", dist[t]);
  }
  return 0;
}
