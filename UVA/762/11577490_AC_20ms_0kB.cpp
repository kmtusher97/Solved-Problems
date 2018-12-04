#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

#define pb push_back

using namespace std;

typedef queue<int> qi;
typedef vector<int> vi;

const int MX = 112345;
int n, prnt[MX];
vi adj[MX];
map<string, int> nodeI;
map<int, string> nodeS;

void clean_list() {
  for(int i=0; i<MX; i++) adj[i].clear();
}

void BFS_Path( int s, int d ) {
  memset(prnt, -1, sizeof prnt);
  qi q; q.push(s), prnt[s] = s;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=adj[u].size(); i<sz; i++) {
      int v = adj[u][i];
      if( prnt[v] == -1 ) {
        prnt[v] = u, q.push(v);
      }
    }
  }
  if( prnt[d] == -1 ) {
    cout<<"No route"<<endl;
    return;
  }
  vi path;
  path.pb(d);
  while( prnt[d] != d ) {
    d = prnt[d];
    path.pb(d);
  }
  cout<<nodeS[path.back()];
  for(int i=path.size()-2; i>=0; i--) {
    cout<<" "<<nodeS[path[i]]<<endl;
    if( i>0 ) cout<<nodeS[path[i]];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases = 0;
  while( cin>>n ) {
    string x, y;
    int nd = 0;
    for(int i=0; i<n; i++) {
      cin>>x>>y;
      if( nodeI.find(x) == nodeI.end() ) {
        nodeI[x] = ++nd, nodeS[nd] = x;
      }
      if( nodeI.find(y) == nodeI.end() ) {
        nodeI[y] = ++nd, nodeS[nd] = y;
      }
      adj[nodeI[x]].pb(nodeI[y]);
      adj[nodeI[y]].pb(nodeI[x]);
    }
    cin>>x>>y;
    if( nodeI.find(x) == nodeI.end() ) {
        nodeI[x] = ++nd, nodeS[nd] = x;
    }
    if( nodeI.find(y) == nodeI.end() ) {
      nodeI[y] = ++nd, nodeS[nd] = y;
    }
    if( cases++ ) cout<<endl;
    BFS_Path( nodeI[x], nodeI[y] );
    
    clean_list(), nodeI.clear(), nodeS.clear();
  }
  return 0;
}
