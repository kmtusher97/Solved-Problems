#include <bits/stdc++.h>
using namespace std;

int chessBoard[10][10];
int dx[] = { -2, -1, -2, -1, 2, 1, 1, 2 };
int dy[] = { 1, 2, -1, -2, -1, -2, 2, 1 };

void bfs(int u, int v)
{
    queue<int> q;
    q.push(u), q.push(v);
    chessBoard[u][v] = 0;

    while( !q.empty() ) {
        u = q.front(), q.pop();
        v = q.front(), q.pop();
        for(int i=0; i<8; i++) {
            int x = dx[i] + u;
            int y = dy[i] + v;
            if( x>0 && y>0 && x<=8 && y<=8 && chessBoard[x][y] == -1 ) {
                q.push(x), q.push(y);
                chessBoard[x][y] = chessBoard[u][v] + 1;
            }
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    string line, a, b;
    int x, y, x1, y1, moves;
    while( getline(cin, line) ) {
        stringstream ss(line);
        ss >> a >> b;
        x = a[0] - 96, y = a[1] - 48;
        x1 = b[0] - 96, y1 = b[1] - 48;

        memset( chessBoard, -1, sizeof chessBoard );
        bfs(x, y);
        moves = chessBoard[x1][y1];
        cout << "To get from " << a << " to " << b << " takes " << moves << " knight moves." << endl;
    }
}
