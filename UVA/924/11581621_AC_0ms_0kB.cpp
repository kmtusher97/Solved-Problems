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

const int MX = 2567;
int level[MX], day[MX];
vi adj[MX];

void BFS( int s ) {
  memset(level, -1, sizeof level);
  memset(day, 0, sizeof day);
  qi q; q.push(s), level[s] = 0;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=adj[u].size(); i<sz; i++) {
      int v = adj[u][i];
      if( level[v]==-1 ) {
        level[v] = level[u]+1;
        ++day[level[v]], q.push(v);
      }
    }
  }
}

int main() {
  int n, cases;
  scanf("%d", &n);
  for(int i=0, m; i<n; i++) {
    scanf("%d", &m);
    for(int j=0, x; j<m; j++) {
      scanf("%d", &x);
      adj[i].pb(x);
    }
  }

  scanf("%d", &cases);
  while( cases-- ) {
    int nd;
    scanf("%d", &nd);
    BFS( nd );
    int mx = -1, d = -1;
    for(int i=0; i<=n; i++) {
      if( mx < day[i] ) d = i, mx = day[i];
    }
    if( mx == 0 ) {
      printf("0\n");
      continue;
    }
    printf("%d %d\n", day[d], d);
  }
  return 0;
}
