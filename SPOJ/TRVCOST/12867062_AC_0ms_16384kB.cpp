/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const intl MX = 502;
int n, src, Q, cost[MX];
vector<pii> g[MX];

bool operator < ( pii a, pii b ) { return a.S>b.S; }

void dijkstra()
{
  for(int i=0; i<=MX; i++) cost[i] = INT_MAX;
  priority_queue<pii> pq; pq.push(pii(src, 0));
  cost[src] = 0;

  while( !pq.empty() )
  {
    pii u = pq.top(); pq.pop();

    if( u.S!=cost[u.F] ) continue;

    for(int i=0; i<g[u.F].size(); i++)
    {
      pii v = g[u.F][i];
      if( cost[v.F]>u.S+v.S )
      {
        cost[v.F] = u.S+v.S;
        pq.push(pii(v.F, cost[v.F]));
      }
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n;
  for(int i=0, a, b, w; i<n; i++)
  {
    cin>>a>>b>>w;
    g[a].push_back(pii(b, w));
    g[b].push_back(pii(a, w));
  }
  cin>>src;
  dijkstra();
  cin>>Q;
  while( Q-- )
  {
    int dst;
    cin>>dst;
    if( cost[dst]==INT_MAX ) cout<<"NO PATH"<<endl;
    else cout<<cost[dst]<<endl;
  }
  return 0;
}
