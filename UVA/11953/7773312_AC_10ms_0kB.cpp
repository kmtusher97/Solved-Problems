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
#define PI acso(-1)
#define modulo 1000003
#define MX 1000000
#define EPS 1e-9

int dx[5]={0, 0, -1, 1}, dy[5]={1, -1, 0, 0}, cnt, n;
string s[120];
bool f;


void dfs(int i, int j);
void dfs1(int i, int j);

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
        for(j=0; j<n; j++) {
            if(s[i][j]=='x') {
                cnt++;
                dfs(i, j);
            }
            else if(s[i][j]=='@') {
                f=false;
                dfs1(i, j);
            }
        }

        printf("Case %d: %d\n", ++t, cnt);
    }
}

void dfs(int i, int j)
{
    int k, x, y;
    s[i][j]='.';
    for(k=0; k<4; k++)
    {
        x=i+dx[k], y=j+dy[k];
        if( (x>=0 && x<n) && (y>=0 && y<n) ) {
            if(s[x][y]=='x') dfs(x, y);
            if(s[x][y]=='@') {
                f=true;
                dfs1(x, y);
            }
        }
    }
}

void dfs1(int i, int j)
{
    int k, x, y;
    s[i][j]='.';
    for(k=0; k<4; k++)
    {
        x=i+dx[k], y=j+dy[k];
        if( (x>=0 && x<n) && (y>=0 && y<n) ) {
            if(s[x][y]=='@') dfs1(x, y);
            if(s[x][y]=='x') {
                if(!f) { cnt++, f=true; }
                dfs(x, y);
            }
        }
    }
}
