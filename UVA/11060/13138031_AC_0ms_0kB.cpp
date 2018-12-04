/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 123;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int caseno = 0, n;
  while( cin>>n )
  {
    int m;
    vector<string> V, T, G[n];
    vector<int> indegree(n+1, 0);
    map<string, int> mp;

    for(int i=0; i<n; i++)
    {
      string s;
      cin>>s;
      V.push_back(s);
      if( mp.find(s)==mp.end() )
      {
        mp[s] = i;
      }
    }

    cin>>m;
    while( m-- )
    {
      string u, v;
      cin>>u>>v;
      indegree[mp[v]]++;
      G[mp[u]].push_back(v);
    }

    bitset<102> vis;
    vis = 0;
    priority_queue< int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++)
    {
      if( indegree[i]==0 )
      {
        pq.push(i);
        vis[i] = true;
      }
    }

    while( !pq.empty() )
    {
      int u = pq.top(); pq.pop();
      T.push_back(V[u]);
      for(string v : G[u])
      {
        if( vis[mp[v]] ) continue;
        indegree[mp[v]]--;
        if( indegree[mp[v]]==0 )
        {
          pq.push(mp[v]);
          vis[mp[v]] = true;
        }
      }
    }

    cout<<"Case #"<<++caseno<<": Dilbert should drink beverages in this order:";
    for(string s : T) cout<<" "<<s;
    cout<<"."<<endl<<endl;
  }
  return 0;
}
