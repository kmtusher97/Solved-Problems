#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

#define read freopen("INPUT.txt", "r", stdin)
#define write freopen("OUTPUT.txt", "w", stdout)
#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int MX = 112345, lg = 15;
int n, level[MX], sp[MX][lg];
intl dist[MX];
vii g[MX];

void clr_grph() {
  for(int i=0; i<MX; i++) g[i].clear();
}

void bfs() {
  memset(level, -1, sizeof level);
  qi q; q.push(0), level[0] = dist[0] = 0, sp[0][0] = -1;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=g[u].size(); i<sz; i++) {
      int v = g[u][i].first;
      if( level[v]==-1 ) {
        q.push(v), level[v] = level[u]+1;
        dist[v] = dist[u]+g[u][i].second;
        sp[v][0] = u;
      }
    }
  }
}

void sprc_tbl() {
  for(int j=1; j<lg; j++) {
    for(int i=0; i<n; i++) {
      sp[i][j] = sp[sp[i][j-1]][j-1];
    }
  }
}

int LCA( int a, int b ) {
  for(int i=lg-1; i>=0; i--) {
    if( level[a]-(1<<i)>=level[b] ) {
      a = sp[a][i];
    }
  }
  if( a==b ) return a;

  for(int i=lg-1; i>=0; i--) {
    if( sp[a][i]!=-1 && sp[a][i]!=sp[b][i] ) {
      a = sp[a][i], b = sp[b][i];
    }
  }
  return sp[a][0];
}

int main() {
  /// read, write;
  FasterIO
  while( cin>>n && n>0 ) {
    for(int i=1, x, c; i<n; i++) {
      cin>>x>>c;
      g[x].pb(mk_pr(i, c));
      g[i].pb(mk_pr(x, c));
    }

    bfs();
    sprc_tbl();

    int Q, a, b;
    cin>>Q;
    vector<intl> ans;
    while( Q-- ) {
      cin>>a>>b;
      if( level[a]<level[b] ) swap(a, b);
      int lca = LCA( a, b );
      intl d = dist[a]+dist[b]-(2*dist[lca]);
      ans.pb(d);
    }
    cout<<ans[0];
    for(int i=1; i<ans.size(); i++) {
      cout<<" "<<ans[i];
    }
    cout<<endl;
    clr_grph();
  }

  return 0;
}


