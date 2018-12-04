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
#define MX 1002
#define EPS 1e-9

vector<int> adjcnt[MX];
int K, N, M, city_pep[102], i, u, v, vis[MX], cnt, mark[MX];

void bfs(int node)
{
    queue<int> que;
    que.push(node);
    vis[node] = 1;
    mark[node]++;
    while( !que.empty() ) {
        int i, sz = adjcnt[node].size();
        for(i=0; i<sz; i++ ) {
            if( !vis[ adjcnt[node][i] ] ) {
                que.push( adjcnt[node][i] );
                vis[ adjcnt[node][i] ] = 1;
                mark[ adjcnt[node][i] ]++;
            }
        }
        que.pop();
        node = que.front();
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d", &K, &N, &M);
        for(i=0; i<K; i++) scanf("%d", &city_pep[i]);
        for(i=0; i<=N; i++) adjcnt[i].clear();
        while( M-- ) {
            scanf("%d %d", &u, &v);
            adjcnt[u].push_back(v);
        }
        memset(mark, 0, sizeof mark);
        for(i=0; i<K; i++) {
            memset(vis, 0, sizeof vis);
            bfs(city_pep[i]);
        }
        for(i=0, cnt=0; i<=N; i++) {
            if( mark[i] == K ) cnt++;
        }
        printf("Case %d: %d\n", ++caseno, cnt);
    }
}
