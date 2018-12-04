#include <bits/stdc++.h>
using namespace std;

#define VISITED 1
#define UNVISITED 0

string line, last_line, maze[40];
bool vis[40][100];
int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int ln;

void bfs(int i, int j)
{
    int u, v, k, l, x, y;
    queue<int> q;
    q.push(i), q.push(j);
    vis[i][j] = VISITED;
    maze[i][j] = '#';

    while( !q.empty() ) {
        u = q.front(), q.pop();
        v = q.front(), q.pop();
        for(k=0; k<4; k++) {
            x = u + dx[k];
            y = v + dy[k];
            if( x>=0 && y>=0 && x<ln && y<maze[x].size() && maze[x][y]==' ' ) {
                q.push(x), q.push(y);
                maze[x][y] = '#';
            }
        }
    }

    for(k=0; k<ln; k++) cout << maze[k] << endl;
    cout << last_line << endl;
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, i, j;
    scanf("%d", &cases);
    getchar();
    while( cases-- ) {
        ln = 0;
        while( getline(cin, line) ) {
            if( line[0] != '_' ) maze[ln++] = line;
            else { last_line = line; break; }
        }
        memset( vis, 0, sizeof vis );
        for(i=0; i<ln; i++) {
        for(j=0; j<maze[i].size(); j++) {
            if( maze[i][j] == '*' ) bfs(i, j);
        }
        }
    }
}
