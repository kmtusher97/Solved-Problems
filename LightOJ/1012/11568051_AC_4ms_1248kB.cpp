#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define UNVISITED 0
#define VISITED 1

typedef queue<int> qi;

const int MX = 1123456;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
char g[23][23];
bool vis[23][23];

int main() {
	int cases, caseno = 0;
	scanf("%d", &cases);
  while( cases-- ) {
    int n, m, xx, yy;
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++) {
      scanf("%s", g[i]);
      for(int j=0; j<m; j++) {
        if( g[i][j]=='@' ) xx = i, yy = j;
      }
    }
    int cnt = 1;
    //BFS;
    memset(vis, UNVISITED, sizeof vis);
    qi q; vis[xx][yy] = VISITED;
    q.push(xx), q.push(yy);
    while( !q.empty() ) {
      xx = q.front(), q.pop();
      yy = q.front(), q.pop();
      for(int i=0; i<4; i++) {
        int x = xx+dx[i];
        int y = yy+dy[i];
        if( ( x>=0 && y>=0 && x<n && y<m ) && g[x][y]=='.' && vis[x][y]==UNVISITED ) {
          q.push(x), q.push(y);
          vis[x][y] = VISITED, cnt++;
        }
      }
    }
    printf("Case %d: %d\n", ++caseno, cnt);
  }
	return 0;
}
