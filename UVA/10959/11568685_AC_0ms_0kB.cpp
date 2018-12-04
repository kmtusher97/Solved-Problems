#include <queue>
#include <cstdio>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef queue<int> qi;

const int MX = 1123;
const int inf = 12345678;
int level[MX];
vi adj[MX];

void clr_grph() {
  for(int i=0; i<MX; i++) adj[i].clear();
}

void BFS() {
  for(int i=0; i<MX; i++) level[i] = inf;
  qi q; q.push(0), level[0] = 0;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    int sz=adj[u].size(), mn = inf;
    for(int i=0; i<sz; i++) mn = min(mn, level[adj[u][i]] );
    if( level[u] > mn+1 ) level[u] = mn+1;
    for(int i=0; i<sz; i++) {
      int v = adj[u][i];
      if( level[v] > level[u]+1 ) {
        q.push(v);
        level[v] = level[u]+1;
      }
    }
  }
}

int main() {
  int cases, caseno = 0, n, m;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    while( m-- ) {
      int x, y;
      scanf("%d %d", &x, &y);
      adj[x].pb(y), adj[y].pb(x);
    }
    BFS();
    for(int i=1; i<n; i++) printf("%d\n", level[i]);
    if( cases ) printf("\n");
    clr_grph();
  }
  return 0;
}
