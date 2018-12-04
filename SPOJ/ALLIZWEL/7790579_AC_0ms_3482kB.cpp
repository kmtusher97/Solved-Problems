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

void dfs(int a, int b, int k)
{
    if(s[a][b] != ss[k]) return;
    if(k == 9) { chk=true; return; }

    for(int i=0; i<8; i++) {
        int x=a+dx[i], y=b+dy[i];
        if( (x>=0 && y>=0) && (x<r && y<c) && !vis[x][y] ) {
            vis[x][y]=true;
            dfs(x, y, k+1);
            vis[x][y]=false;
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int tc, t=0, i, j, k;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &r, &c);
        for(i=0; i<r; i++)
            cin >> s[i];

        for(i=0, chk=false; i<r; i++) {
            for(j=0; j<c; j++){
                if(s[i][j] == 'A') {
                    unvis();
                    dfs(i, j, 0);
                }
            }
            if(chk) break;
        }

        if(chk) printf("YES\n");
        else printf("NO\n");
    }
}
