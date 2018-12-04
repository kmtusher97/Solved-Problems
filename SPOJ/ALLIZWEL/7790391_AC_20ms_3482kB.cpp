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

string s[120], ss = "ALLIZZWELL";
int r, c, cnt, dx[]= { 0, 0, -1, 1, -1, -1, 1, 1 }, dy[]= { -1, 1, 0, 0, 1, -1, -1, 1 };
bool  vis[120][120], chk;

void unvis()
{
    for(int i=0; i<=r; i++)
        for(int j=0; j<=c; j++) vis[i][j]=false;
}

void dfs(int i, int j, int k)
{
    if(s[i][j] != ss[k])
    {
        return;
    }
    if(k == 9)
    {
        chk=true;
        return;
    }
    for(int i1=0; i1<8; i1++)
    {
        int x=i+dx[i1], y=j+dy[i1];

        if( (x>=0 && x<r) && (y>=0 && y<c) && (s[i][j] == ss[k]) && !vis[x][y] )
        {
            vis[i][j]=true;
            dfs(x, y, k+1);
            vis[i][j]=false;
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int tc, t=0, i, j, k;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d", &r, &c);
        for(i=0; i<r; i++)
            cin >> s[i];

        chk=false;

        for(i=0, cnt=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(s[i][j]=='A')
                {
                    unvis();
                    dfs(i, j, 0);
                    if(chk)
                    {
                        break;
                    }
                }
            }
            if(chk) break;
        }

        if(chk) printf("YES\n");
        else printf("NO\n");
    }
}
