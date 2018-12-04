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

const int MX = 1123456;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
pii pos[30];
int vis[12][12];
char g[12][12];

int BFS( int n, int x, int y, int d1, int d2 ) {
  memset(vis, -1, sizeof vis);
  qi q; q.push(x), q.push(y), vis[x][y] = 0;
  g[x][y] = '.';

  while( !q.empty() ) {
    int xx = q.front(); q.pop();
    int yy = q.front(); q.pop();
    for(int i=0; i<4; i++) {
      x = xx+dx[i];
      y = yy+dy[i];
      if( x>=0 && y>=0 && x<n && y<n && ( g[x][y]=='.' || (x==d1 && y==d2) ) && vis[x][y]==-1 ) {
        vis[x][y] = vis[xx][yy]+1,
        q.push(x), q.push(y);
      }
    }
  }

  return vis[d1][d2];
}

int main() {
  int cases, caseno = 0, n;
  scanf("%d", &cases);
  while( cases-- ) {
    memset(pos, -1, sizeof pos);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
      scanf("%s", g[i]);
      for(int j=0; j<n; j++) if( g[i][j]>='A' && g[i][j]<='Z' ) {
        pos[g[i][j]-64] = mk_pr(i, j);
      }
    }
    printf("Case %d: ", ++caseno);
    int cst = 0;
    for(int i=2; pos[i].first!=-1 && i<=26; i++) {
      int cc = BFS( n, pos[i-1].first, pos[i-1].second, pos[i].first, pos[i].second );
      if( cc == -1 ) {
        printf("Impossible\n"), cst = -1;
        break;
      }
      cst += cc;
    }
    if( cst==-1 ) continue;
    printf("%d\n", cst);
  }
  return 0;
}
