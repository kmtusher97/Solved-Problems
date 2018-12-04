/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
int n, m;
bool vis[30];
vector<int> G[30];

bool dfs( int u ) {
  vis[u] = true;
  for(int v : G[u])
    if( !vis[v] ) dfs( v );
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin >> m >> n ) {
    for(int i = 0; i < 30; i++)
      G[i].clear();
    for(int i = 1; i <= m; i++) {
      char a, b;
      cin >> a >> b;
      G[a - 96].push_back(b - 96);
    }
    for(int i = 1; i <= n; i++) {
      string a, b;
      cin >> a >> b;
      if( a.length() != b.length() ) {
        cout << "no" << endl;
        continue;
      }
      bool ok = true;
      for(int i = 0; a[i]; i++) {
        if( a[i] == b[i] ) continue;
        memset(vis, 0, sizeof vis);
        dfs( a[i] - 96 );
        bool f = vis[b[i] - 96];
        if( !f ) {
          ok = false;
          break;
        }
      }
      if( ok ) cout << "yes" << endl;
      else cout << "no" << endl;
    }
  }
  return 0;
}
