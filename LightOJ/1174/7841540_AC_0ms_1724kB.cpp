#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;

#define MX 1000
#define VISITED 1
#define UNVISITED 0

vector<int> adjcnt[MX+5];
bool vis[MX+5], flg;
int level[MX+5], fix_level[MX+5];

void bfs1(int u)
{
    int v, i, sz, l;
    memset( vis, 0, sizeof vis );
    memset( fix_level, 0, sizeof fix_level );
    queue<int> myque;
    myque.push(u);
    vis[u] = VISITED;

    while( !myque.empty() ) {
        u = myque.front();
        myque.pop();
        sz = adjcnt[u].size();
        for(i=0; i<sz; i++) {
            v = adjcnt[u][i];
            if( vis[v] == UNVISITED ) {
                myque.push(v);
                vis[v] = VISITED;
                fix_level[v] = fix_level[u] + 1;
            }
        }
    }
}

int bfs(int u, int dstntion, int lev)
{
    int v, i, sz, l;
    memset( vis, 0, sizeof vis );
    memset( level, 0, sizeof level );
    queue<int> myque;
    myque.push(u);
    vis[u] = VISITED;
    level[u] = lev;
    flg = false;

    while( !myque.empty() ) {
        u = myque.front();
        myque.pop();
        sz = adjcnt[u].size();
        for(i=0; i<sz; i++) {
            v = adjcnt[u][i];
            if( vis[v] == UNVISITED ) {
                myque.push(v);
                vis[v] = VISITED;
                l = level[v] = level[u] + 1;
                if( v == dstntion ) flg = true;
            }
        }
        if( flg ) break;
    }

    return l;
}

void clearGraph()
{
    for(int i=0; i<=MX; i++) adjcnt[i].clear();
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, i, j, x, y, n, r, ans;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &n, &r);
        clearGraph();        ///clearing adjacency list
        for(i=0; i<r; i++) {        ///adjacency list
            scanf("%d %d", &x, &y);
            adjcnt[x].push_back(y);
            adjcnt[y].push_back(x);
        }

        scanf("%d %d", &x, &y);
        bfs1(x);
        //for(i=0; i<n; i++) fix_level[i] = level[i];
        for(i=0, ans=0; i<n; i++) {
            if( i != y ) ans = max(ans, bfs(i, y, fix_level[i]));
        }
        printf("Case %d: %d\n", ++caseno, ans);
    }
}
