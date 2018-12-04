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

const int MX = 5020, lg=15;
int n, lvl[MX], prnt[MX], sp[MX][lg];
vi g[MX];

void clr_grph() {
  for(int i=0; i<MX; i++) g[i].clear();
}

void bfs() {
  memset(lvl, -1, sizeof lvl);
  qi q; q.push(1), lvl[1] = 0, prnt[1] = -1;

  while( !q.empty() ) {
    int u = q.front(); q.pop();
    for(int i=0, sz=g[u].size(); i<sz; i++) {
      int v = g[u][i];
      if( lvl[v]==-1 ) {
        lvl[v] = lvl[u]+1;
        q.push(v), prnt[v] = u;
      }
    }
  }
}

void sprc_tbl() {
  memset(sp, -1, sizeof sp);
  for(int i=1; i<=n; i++) {
    sp[i][0] = prnt[i];
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<lg; j++) {
      sp[i][j] = sp[sp[i][j-1]][j-1];
    }
  }
}

int LCA( int x, int y ) {
  for(int i=lg-1; i>=0; i--) {
    if( lvl[x]-(1<<i)>=lvl[y] ) x = sp[x][i];
  }
  if( x==y ) return x;

  for(int i=lg-1; i>=0; i--) {
    if( sp[x][i]!=-1 && sp[x][i]!=sp[y][i] ) {
      x = sp[x][i], y = sp[y][i];
    }
  }

  return prnt[x];
}

int kth_prnt( int x, int k ) {
  for(int i=lg-1; i>=0; i--) {
    if( k>=(1<<i) ) {
      k -= (1<<i), x = sp[x][i];
    }
  }
  return x;
}

int main() {
  while( scanf("%d", &n) && n!=0 ) {
    for(int i=1, x, y; i<n; i++) {
      scanf("%d %d", &x, &y);
      g[x].pb(y);
      g[y].pb(x);
    }

    bfs();
    sprc_tbl();

    int Q, a, b;
    scanf("%d", &Q);
    while( Q-- ) {
      scanf("%d %d", &a, &b);
      if( lvl[a]<lvl[b] ) swap(a, b);
      int lca = LCA(a, b);
      //cout<<lca<<endl;
      int d = lvl[a]-lvl[lca];
      d += lvl[b]-lvl[lca];

      if( d%2==0 ) {
        int k = kth_prnt( a, d/2 );
        //cout<<a<<"'s "<<(d/2)<<"th parent "<<k<<endl;
        printf("The fleas meet at %d.\n", k);
      }
      else {
        int k1 = kth_prnt( a, d/2 );
        //cout<<a<<"'s "<<(d/2)<<"th parent "<<k1<<endl;
        int k2 = kth_prnt( a, d/2+1 );
        //cout<<a<<"'s "<<(d/2+1)<<"th parent "<<k2<<endl;
        if( k1>k2 ) swap(k1, k2);
        printf("The fleas jump forever between %d and %d.\n", k1, k2);
      }
    }

    clr_grph();
  }
}
