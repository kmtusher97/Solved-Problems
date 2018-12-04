/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define MX_S 11234

const int MX = 11234;
int indegree[MX];
vector<string> G[MX];
map<string, int> mp;

int main()
{
  //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases, caseno = 0;
  cin>>cases;
  while( cases-- )
  {
    int m, drnk = 0;
    fill(indegree, indegree+MX, 0);
    for(int i=0; i<MX; i++) G[i].clear();
    mp.clear();
    cin>>m;
    while( m-- )
    {
      string u, v;
      cin>>u>>v;
      if( mp.find(u)==mp.end() ) mp[u] = ++drnk;
      if( mp.find(v)==mp.end() ) mp[v] = ++drnk;
      indegree[mp[v]]++;
      G[mp[u]].push_back(v);
    }

    bitset<MX_S> vis;
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=1; i<=drnk; i++)
    {
      if( indegree[i]==0 )
      {
        pq.push(i);
        vis[i] = true;
      }
    }

    int cnt = 0;
    while( !pq.empty() )
    {
      int u = pq.top(); pq.pop();
      cnt++;
      for(int i=0; i<G[u].size(); i++)
      {
        string v = G[u][i];
        if( vis[mp[v]] ) continue;
        indegree[mp[v]]--;
        if( indegree[mp[v]]==0 )
        {
          pq.push(mp[v]);
          vis[mp[v]] = true;
        }
      }
    }

    cout<<"Case "<<++caseno<<": ";
    if( cnt==mp.size() ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  return 0;
}
