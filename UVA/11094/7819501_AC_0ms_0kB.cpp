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

int dx4[] = { 0, 0, 1, -1 };
int dy4[] = { 1, -1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

string graph[30];
int m, n, cnt;

void floodfill(int i, int j, char ch)
{
    graph[i][j] = ' ';
    ++cnt;
    int x, y, k;
    for(k=0; k<8; k++) {
        x = i+dx4[k];
        y = j+dy4[k];
        if( y < 0 ) y = n-1;
        if( y == n ) y = 0;
        if( x>=0 && x<m && graph[x][y] == ch ) {
            floodfill(x, y, ch);
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int i, j, x, y, mx;
    char ch;
    while( scanf("%d %d", &m, &n) == 2) {
        for(i=0; i<m; i++) cin >> graph[i];
        scanf("%d %d", &x, &y);
        ch = graph[x][y];
        floodfill(x, y, graph[x][y]);
        mx = INT_MIN;
        for(i=0; i<m; i++) {
            for(j=0; j<n; j++) {
                cnt = 0;
                if(graph[i][j] == ch) floodfill(i, j, ch);
                mx = max(mx, cnt);
            }
        }
        printf("%d\n", mx);
    }
}
