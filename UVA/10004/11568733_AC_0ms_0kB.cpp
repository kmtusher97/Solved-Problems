#include <queue>
#include <cstdio>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef queue<int> qi;

const int MX = 212;
int n, m, color[MX];
vi adj[MX];

void clr_grph() {
  for(int i=0; i<MX; i++) adj[i].clear();
}

bool BFS() {
  for(int i=0; i<=n; i++) color[i] = -1;
  qi q; q.push(0), color[0] = 0;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=adj[u].size(); i<sz; i++) {
      int v = adj[u][i];
      if(color[u] == color[v] ) return false;
      if( color[v] == -1 ) {
        q.push(v);
        color[v] = !color[u];
      }
    }
  }
  return true;
}

int main() {
  while( ~scanf("%d", &n) && n ) {
    scanf("%d", &m);
    for(int i=1, x, y; i<=m; i++) {
      scanf("%d %d", &x, &y);
      adj[x].pb(y), adj[y].pb(x);
    }
    BFS() ? printf("BICOLORABLE.\n") : printf("NOT BICOLORABLE.\n");
    clr_grph();
  }
  return 0;
}
