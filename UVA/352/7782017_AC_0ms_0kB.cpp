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

string s[30];
int dx[10]={0, 0, -1, 1, -1, 1, -1, 1}, dy[10]={-1, 1, 0, 0, 1, 1, -1, -1}, n;

void dfs(int i, int j)
{
    s[i][j]='0';

    int x, y, k;
    for(k=0; k<8; k++)
    {
        x=i+dx[k], y=j+dy[k];
        if( (x>=0 && x<n) && (y>=0 && y<n) && s[x][y]=='1' ) dfs(x, y);
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int i, j, cnt, tc=0;
    while(scanf("%d", &n)==1)
    {
        for(i=0; i<n; i++)
            cin >> s[i];

        for(i=0, cnt=0; i<n; i++)
        for(j=0; j<n; j++) {
            if(s[i][j]=='1') {
                cnt++;
                dfs(i, j);
            }
        }

        printf("Image number %d contains %d war eagles.\n", ++tc, cnt);
    }
}
