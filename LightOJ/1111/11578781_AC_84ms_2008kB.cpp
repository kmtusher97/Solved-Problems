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

const int MX = 11234;
int n, m, k, pplsn[MX];
bool vis[MX];
vi adj[MX];

void clr_list() {
  memset(pplsn, 0, sizeof pplsn);
  for(int i=0; i<MX; i++) adj[i].clear();
}

bool BFS( int x ) {
  memset(vis, false, sizeof vis);
  qi q; q.push(x), vis[x] = true;
  int cnt = pplsn[x];

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=adj[u].size(); i<sz; i++) {
      int v = adj[u][i];
      if( !vis[v] ) {
        vis[v] = true, q.push(v), cnt += pplsn[v];
      }
    }
  }

  return cnt==k ? true : false;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d %d", &k, &n, &m);
    for(int i=1, a; i<=k; i++) {
      scanf("%d", &a);
      pplsn[a]++;
    }
    for(int i=1, x, y; i<=m; i++) {
      scanf("%d %d", &x, &y);
      adj[y].pb(x);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++) {
      if( BFS( i ) ) cnt++;
    }
    printf("Case %d: %d\n", ++caseno, cnt);
    clr_list();
  }
  return 0;
}
