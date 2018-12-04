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

int n, ar[22][5], dp[25][5], a, b, c;
bool mark[4];

int go(int p, int q)
{
    if( p == n ) return 0;
    if( dp[p][q] != -1 ) return dp[p][q];

    int i, j1, j2, a=0, b=0;
    for(i=0; i<3; i++) {
        if( i == 0 ) j1 = 1, j2 = 2;
        else if( i == 1 ) j1 = 0, j2 = 2;
        else if( i == 2 ) j1 = 0, j2 = 1;
        a = ar[p][i] + go(p+1, j1);
        b = ar[p][i] + go(p+1, j2);
        dp[p][i] = min(a, b);
    }

    return dp[p][q];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno=0, i, j;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d", &n);
        for(i=0; i<n; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &ar[i][j]);
        }
        }
        memset( mark, 0, sizeof mark );
        memset( dp, -1, sizeof dp );
        go(0,0);
        printf("Case %d: %d\n", ++caseno, *min_element(dp[0], dp[0]+3));
        /*for(i=0; i<n; i++) {
            for(j=0; j<3; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;

        }*/
    }
}
