#include <bits/stdc++.h>
using namespace std;

int m, n, a, b, c;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
string graph[25];

void bfs(int x, int y)
{
    int level[m+1][n+1], vis[m+1][n+1], i, j, k;
    memset(level, 0, sizeof level);
    memset(vis, 0, sizeof vis);

    queue<int> q;
    q.push(x), q.push(y);
    vis[x][y] = 1;

    while( !q.empty() ) {
        x = q.front(), q.pop();
        y = q.front(), q.pop();
        for(k=0; k<4; k++) {
            i = dx[k]+x;
            j = dy[k]+y;
            if( i>=0 && j>=0 && i<m && j<n && !vis[i][j] ) {
                if( graph[i][j] == '.' ) {
                    q.push(i), q.push(j);
                    vis[i][j] = 1;
                    level[i][j] = level[x][y] + 1;
                }
                else if( graph[i][j] == 'a' ) {
                    q.push(i), q.push(j);
                    vis[i][j] = 1;
                    level[i][j] = level[x][y] + 1;
                    a = level[i][j];
                }
                else if( graph[i][j] == 'b' ) {
                    q.push(i), q.push(j);
                    vis[i][j] = 1;
                    level[i][j] = level[x][y] + 1;
                    b = level[i][j];
                }
                else if( graph[i][j] == 'c' ) {
                    q.push(i), q.push(j);
                    vis[i][j] = 1;
                    level[i][j] = level[x][y] + 1;
                    c = level[i][j];
                }
            }
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno=0, i, j;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &m, &n);
        for(i=0; i<m; i++) { cin >> graph[i]; }
        for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            if( graph[i][j] == 'h' ) { bfs(i, j); break; }
        }
        }
        int mx = max(a, b);
        mx = max(mx, c);
        printf("Case %d: %d\n", ++caseno, mx);
    }
}
