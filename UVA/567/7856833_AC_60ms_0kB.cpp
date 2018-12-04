#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef queue<int> qi;

#define VISITED 1
#define UNVISITED 0

vi adjcnt[30];
bool vis[30], chk;
int level[30];

int bfs(int u, int destination)
{
    int i, v, sz;
    qi myq;
    myq.push(u);
    memset( vis, UNVISITED, sizeof vis );
    memset( level, 0, sizeof level );
    vis[u] = VISITED;
    chk = false;

    while( !myq.empty() ) {
        u = myq.front();
        myq.pop();
        sz = adjcnt[u].size();
        for(i=0; i<sz; i++) {
            v = adjcnt[u][i];
            if( !vis[v] ) {
                myq.push(v);
                vis[v] = VISITED;
                level[v] = level[u] + 1;
            }
            if( v == destination ) { chk = true; break; }
        }
        if( chk ) break;
    }

    return level[destination];
}

void clearList() { for(int i=0; i<22; i++) adjcnt[i].clear(); }

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, N = 19, n, i, j, a, b;

    while( scanf("%d", &a) == 1 ) {
        n = a;
        clearList();
        while( n-- ) {
            scanf("%d", &b);
            adjcnt[1].push_back(b);
            adjcnt[b].push_back(1);
        }
        for(i=2; i<=19; i++) {
            scanf("%d", &n);
            while( n-- ) {
                scanf("%d", &b);
                adjcnt[i].push_back(b);
                adjcnt[b].push_back(i);
            }
        }
        scanf("%d", &cases);
        printf("Test Set #%d\n", ++caseno);
        while( cases-- ) {
            scanf("%d %d", &a, &b);
            printf("%2d to %2d:%2d\n", a, b, bfs(a, b));
        }
        if( caseno ) printf("\n");
    }
}
