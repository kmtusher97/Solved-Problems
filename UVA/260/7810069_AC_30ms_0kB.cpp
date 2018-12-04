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

string s[220];
int n, dx[]={ -1, -1, 0, 0, 1, 1 }, dy[]={ -1, 0, -1, 1, 0, 1 };
bool vis[220][220];

void floodFill(int i, int j, char c, char c1)
{
    s[i][j] = c1;

    int x, y, k;
    for(k=0; k<6; k++) {
        x = dx[k]+i;
        y = dy[k]+j;
        if( x>=0 && y>=0 && x<n && y<n && s[x][y] == c )
            floodFill(x, y, c, c1);
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int caseno=0, i, j;
    char ch;
    while( scanf("%d", &n) == 1, n ) {
        for(i=0; i<n; i++) cin >> s[i];
        for(i=0; i<n; i++) {
            if( s[0][i] == 'b' ) floodFill(0, i, 'b', 'B');
            if( s[i][0] == 'w' ) floodFill(i, 0, 'w', 'W');
        }

        for(i=0; i<n; i++)
            if( s[n-1][i] == 'B' ) { printf("%d B\n", ++caseno); break; }
        for(i=0; i<n; i++)
            if( s[i][n-1] == 'W' ) { printf("%d W\n", ++caseno); break; }
    }
}

