#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

#define VISITED 1
#define UNVISITED 0

const int MX = 123;
int dx[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int n, m;
char g[MX][MX];

void BFS( int x, int y ) {
  queue<int> q;
  q.push(x), q.push(y), g[x][y] = '*';

  while(  !q.empty() ) {
    int xx = q.front(); q.pop();
    int yy = q.front(); q.pop();
    for(int i=0; i<8; i++) {
      x = xx+dx[i], y = yy+dy[i];
      if( x>=0 && y>=0 && x<n && y<m && g[x][y]=='@' ) {
        q.push(x), q.push(y), g[x][y] = '*';
      }
    }
  }
}

int main() {
  while( ~scanf("%d %d", &n, &m) && n && m ) {
    for(int i=0; i<n; i++) {
      scanf("%s", g[i]);
    }

    int cnt = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        if( g[i][j]=='@' ) {
          BFS( i, j ), cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
