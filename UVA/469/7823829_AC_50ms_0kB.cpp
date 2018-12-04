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
#include <list>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 40000
#define MX 500000
#define EPS 1e-9

//int dx4[] = { 0, 0, 1, -1 };
//int dy4[] = { 1, -1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int n, m;
string s, graph[110];
bool vis[105][105];

int bfs(int i, int j, char ch)
{
    queue<int> q;
    q.push(i), q.push(j);
    memset(vis, 0, sizeof vis);
    vis[i][j] = 1;
    int lev = 1;

    while( !q.empty() ) {
        i = q.front(), q.pop();
        j = q.front(), q.pop();
        vis[i][j] = 1;
        int k, x, y;
        for(k=0; k<8; k++) {
            x = dx8[k]+i;
            y = dy8[k]+j;
            if( x>=0 && y>=0 && x<n && y<m && graph[x][y]==ch && !vis[x][y] ) {
                vis[x][y] = 1;
                q.push(x), q.push(y);
                lev++;
            }
        }
    }
    return lev;
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno = 0, a, b, i=0;
    scanf("%d", &cases);
    getchar();
    while( i < cases ) {
        if( !i ) getchar();
        if( i ) printf("\n");
        n=0;
        for(int i=0; i<105; i++) graph[i].clear();
        while( getline(cin, s) && s != "" ) {
            if( s[0] >= '0' && s[0] <= '9' ) {
                stringstream ss(s);
                ss >> a >> b;
                //for(int i=0; i<n; i++) cout << graph[i] << endl;
                printf("%d\n", bfs(a-1, b-1, graph[a-1][b-1]) );
            }
            else {
                graph[n++] = s;
                m = s.size();
            }
        }
        i++;
    }
}
