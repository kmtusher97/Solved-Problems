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
const int inf = 1234567;
int adj[MX][MX];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    int n, m, s, d;
    scanf("%d %d", &n, &m);
    for(int i=0; i<=n; i++) {
      for(int j=0; j<=n; j++) if( i!=j ) {
        adj[i][j] = inf;
      }
    }
    for(int i=0, x, y; i<m; i++) {
      scanf("%d %d", &x, &y);
      adj[x][y] = adj[y][x] = 1;
    }
    scanf("%d %d", &s, &d);
    ///WARSHALL
    for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
          adj[i][j] = min( adj[i][j], adj[i][k]+adj[k][j] );
        }
      }
    }
    int cst = -1;
    for(int i=0; i<n; i++) {
      cst = max( cst, adj[s][i]+adj[i][d] );
    }
    printf("Case %d: %d\n", ++caseno, cst);
  }
  return 0;
}
