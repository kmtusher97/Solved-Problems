#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acso(-1)
#define modulo 1000003
#define MX 1000000
#define EPS 1e-9

int dx[5]={0, 0, -1, 1}, dy[5]={1, -1, 0, 0}, cnt, n;
string s[120];

void dfs(int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=n || s[i][j]=='.') return;
    s[i][j]='.';

    for(int k=0; k<4; k++)
        dfs(i+dx[k], j+dy[k]);
}
main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int tc, t=0, i, j;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);

        for(i=0; i<n; i++) cin >> s[i];

        for(i=0, cnt=0; i<n; i++)
        for(j=0; j<n; j++)
            if(s[i][j]=='x') cnt++, dfs(i, j);

        printf("Case %d: %d\n", ++t, cnt);
    }
}
