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

string land[25];
int r, c, cnt;
int dx[5] = { 0, 0, -1, 1 }, dy[5] = { -1, 1, 0, 0 };

void fldFill(int i, int j)
{
    if( i<0 || j<0 || i>=r || j>=c ) return;
    if( land[i][j] == '#' ) return;
    if( land[i][j] == '@' || land[i][j] == '.' ) land[i][j] = '#', cnt++;

    for(int k=0; k<4; k++) {
        fldFill(i+dx[k], j+dy[k]);
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno=0, i, j;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d", &c, &r);
        for(i=0; i<r; i++) {
            cin >> land[i];
        }
        for(i=0, cnt=0; i<r; i++) {
        for(j=0; j<c; j++) {
            if( land[i][j] == '@' ) fldFill(i, j);
        }
        }
        printf("Case %d: %d\n", ++caseno, cnt);
    }
}
