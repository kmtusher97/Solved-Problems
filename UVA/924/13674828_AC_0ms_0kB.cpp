/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define VISITED 1
#define UNVISITED 0
#define pb push_back

typedef long long intl;
typedef queue<int> qi;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int MX = 2556;
int n, e, level[MX], cnt[MX];
vi g[MX];

void bfs( int src, int& M, int &D )
{
  memset(level, -1, sizeof level);
  memset(cnt, 0, sizeof cnt);
  qi Q; Q.push(src), level[src] = 0;
  int mx = 0, L = 0;
  while( !Q.empty() )
  {
    int u = Q.front(); Q.pop();
    for(int v : g[u])
    {
      if( level[v]==-1 )
      {
        level[v] = level[u]+1;
        cnt[level[v]]++, Q.push(v);
        L = max(L, level[v]);
      }
    }
  }
  for(int i=0; i<=L; i++)
  {
    if( mx<cnt[i] )
    {
      mx = M = cnt[i];
      D = i;
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin>>n )
  {
    for(int i=0, x; i<n; i++)
    {
      cin>>x;
      for(int j=0, u; j<x; j++)
      {
        cin>>u;
        g[i].pb(u);
        //g[u].pb(i);
      }
    }
    int cases;
    cin>>cases;
    while( cases-- )
    {
      int src, M = 0, D = 0;
      cin>>src;
      bfs( src, M, D);
      if( M==0 ) cout<<0<<endl;
      else cout<<M<<" "<<D<<endl;
    }
    for(int i=0; i<MX; i++) g[i].clear();
  }

  return 0;
}
