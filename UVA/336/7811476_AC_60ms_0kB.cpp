#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 1000003
#define MX 500000
#define EPS 1e-9

map<int, int> nodes, mark;
vector<int> adjcnt[40];

void bfs(queue<int> que, int ttl)
{
    int i, sz, nd = que.front(), level[50], lev = 0;
    memset(level, 0, sizeof level);
    int cnt=1;
    while( !que.empty() )
    {
        sz = adjcnt[nd].size();
        for(i=0; i<sz; i++)
        {
            if( mark.find( adjcnt[nd][i] ) == mark.end() )
            {
                lev = level[ adjcnt[nd][i] ] = level[nd]+1;
                if( lev > ttl ) break;
                else
                {
                    que.push( adjcnt[nd][i] );
                    mark[ adjcnt[nd][i] ] = 1;
                    cnt++;
                }
            }
        }
        que.pop();
        nd = que.front();
    }
    //return cnt;
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int caseno=0, N, n, i, node, ttl, a, b, p;
    while( scanf("%d", &N) == 1, N )
    {
        for(i=0; i<40; i++) adjcnt[i].clear();
        nodes.clear(), p=0;
        while( N-- )
        {
            scanf("%d %d", &a, &b);
            if( nodes.find(a) == nodes.end() ) nodes[a]=p++;
            if( nodes.find(b) == nodes.end() ) nodes[b]=p++;
            adjcnt[ nodes[a] ].push_back( nodes[b] );
            adjcnt[ nodes[b] ].push_back( nodes[a] );
        }
        while( scanf("%d %d", &node, &ttl) == 2 )
        {
            if( !ttl && !node ) break;
            queue<int> myque;
            mark.clear();
            myque.push( nodes[node] );
            mark[ nodes[node] ] = 1;
            bfs(myque, ttl);
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++caseno, ( nodes.size() - mark.size() ), node, ttl );
        }
    }
}
