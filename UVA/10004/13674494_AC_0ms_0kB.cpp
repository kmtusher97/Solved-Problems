/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long intl;
typedef queue<int> qi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int MX = 213;
int n, e, color[MX];
vi g[MX];

bool bfsBicolor()
{
  memset(color, -1, sizeof color);
  qi Q; Q.push(0), color[0] = 0;

  while( !Q.empty() )
  {
    int u = Q.front(); Q.pop();
    for(int v : g[u])
    {
      if( color[v]==color[u] ) return false;
      if( color[v]==-1 )
      {
        color[v] = color[u]==1 ? 0 : 1;
        Q.push(v);
      }
    }
  }
  return true;
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin>>n && n )
  {
    cin>>e;
    for(int i=0, u, v; i<e; i++)
    {
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
    }
    if( bfsBicolor() ) cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;
    for(int i=0; i<MX; i++) g[i].clear();
  }

  return 0;
}
