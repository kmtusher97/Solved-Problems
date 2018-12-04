#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef queue<int> qi;
typedef queue<pii> qii;

#define MX 1000
#define VISITED 1
#define UNVISITED 0

bool Adjcnt[MX+100][MX+100], chk;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int row, col, level[MX+100][MX+100];

int bfs(int u1, int v1, int u2, int v2)
{
    memset( level, 0, sizeof level );

    qii myque;
    pii pos, cur_pos;
    pos.first = u1, pos.second = v1;
    myque.push( pos );
    Adjcnt[u1][v1] = VISITED;
    int i, x, y, u, v;
    chk = false;

    while( !myque.empty() ) {
        pos = myque.front();
        myque.pop();
        u = pos.first;
        v = pos.second;
        for(i=0; i<4; i++) {
            x = u + dx[i];
            y = v + dy[i];
            if( x>=0 && y>=0 && x<=row && y<=col && !Adjcnt[x][y] ) {
                cur_pos.first = x;
                cur_pos.second = y;
                myque.push( cur_pos );
                Adjcnt[x][y] = VISITED;
                level[x][y] = level[u][v] + 1;
            }
            if( x == u2 && y == v2 ) { chk = true; break; }
        }
        if( chk ) break;
    }

    return level[u2][v2];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, a, b, x, y, bmb;
    while( scanf("%d %d", &row, &col) == 2 && row && col ) {
        scanf("%d", &cases);
        memset( Adjcnt, UNVISITED, sizeof Adjcnt );
        getchar();
        string line;
        while( cases-- ) {
            getline(cin, line);
            stringstream ss(line);
            ss >> a >> bmb;
            while( ss >> b ) {
                Adjcnt[a][b] = 1;
            }
        }
        scanf("%d %d %d %d", &a, &b, &x, &y);
        printf("%d\n", bfs(a, b, x, y));
    }
}
