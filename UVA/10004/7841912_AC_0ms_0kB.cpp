#include <bits/stdc++.h>
using namespace std;

#define MX 250
#define COLOR1 1
#define COLOR2 2
#define VISITED 1
#define UNVISITED 0

vector<int> Adjcnt[MX];
int mark[MX], num_node, num_edge;

bool bfs()
{
    memset( mark, UNVISITED, sizeof mark ); // initially all nodes are unvisited
    int u, v, i, sz;
    bool flg = true;
    queue<int> myque;
    myque.push(0);  // starting from node 0
    mark[0] = COLOR1;  ///coloring the 1st node with color 1

    while( !myque.empty() ) {
        u = myque.front();
        myque.pop();
        sz = Adjcnt[u].size();
        for(i=0; i<sz; i++) {
            v = Adjcnt[u][i];
            if( mark[u] == mark[v] ) { flg = false; break; }  /// adjacent nodes can't have same color
            if( !mark[v] ) {
                myque.push(v);
                if( mark[u] == COLOR1 ) mark[v] = COLOR2;
                if( mark[u] == COLOR2 ) mark[v] = COLOR1;
        } }
        if( !flg ) return false;
    }

    return true;
}

void clearAdjlist() { for(int i=0; i<num_node; i++) Adjcnt[i].clear(); }

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, i, j, x, y;
    while( scanf("%d", &num_node) == 1, num_node ) {
        scanf("%d", &num_edge);
        clearAdjlist();        ///clear list
        for(i=0; i<num_edge; i++) {     ///create adjacent list
            scanf("%d %d", &x, &y);
            Adjcnt[x].push_back(y);     ///bi directional graph
            Adjcnt[y].push_back(x);
        }

        if( bfs() ) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}
