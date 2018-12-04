#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef queue<int> qi;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;

const int MX = 123;
bool vis[MX];
vi adj[MX], tp;

void clr() {
  for(int i=0; i<MX; i++) adj[i].clear();
}

void DFS( int u ) {
  vis[u] = true;
  for(int i=0, sz=adj[u].size(); i<sz; i++) {
    if( !vis[adj[u][i]] ) DFS( adj[u][i] );
  }
  tp.pb(u);
}

int main() {
  //freopen("output.txt", "w", stdout);
  int n, m;
  while( ~scanf("%d %d", &n, &m) && n ) {
    for(int i=0, x, y; i<m; i++) {
      scanf("%d %d", &x, &y);
      adj[x].pb(y);
    }
    for(int i=1; i<=n; i++) if( !vis[i] ) {
      DFS( i );
    }
    for(int i=tp.size()-1; i>0; i--) printf("%d ", tp[i]);
    printf("%d\n", tp[0]);
    memset(vis, false, sizeof vis);
    tp.clear(), clr();
  }
  return 0;
}
