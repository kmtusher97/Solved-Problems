/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

#define MX_N 112

typedef long long intl;

intl r, c, res, g[MX_N][MX_N], ff1[MX_N][MX_N], ff2[MX_N][MX_N];
vector<int> path;

intl dp1( int i, int j )   /*get maximum result*/
{
    if( i>r || j>c ) return 0LL;
    if( i==r && j==c ) return ff1[i][j] = g[i][j];
    intl& ret = ff1[i][j];
    if( ~ret ) return ret;

    return ff1[i][j] = g[i][j] + max( dp1( i+1, j ), dp1( i, j+1 ) );
}

void dfs( int i, int j )
{
    if( i>r || j>c ) return;
    if( g[i][j] ) path.push_back( c*(i-1)+j );

    if( ff1[i+1][j]>ff1[i][j+1] ) dfs( i+1, j );
    else dfs( i, j+1 );
}

intl dp2( int x, int y )   /*count number of ways to get maximum res*/
{
    if( ff1[x][y]==g[x][y] ) return ff2[x][y] = 1LL;
    intl& ret = ff2[x][y];
    if( ~ret ) return ret;

    ret = 0;
    for(int i=x; i<=r; i++)
    {
        for(int j=y; j<=c; j++)
        {
            if( (i==x && j==y) || !g[i][j] ) continue;
            if( ff1[x][y]==ff1[i][j]+g[x][y] ) ret += dp2( i, j );
        }
    }
    return ff2[x][y] = ret;
}

int main()
{
    int caseno = 0;
    while( ~scanf("%lld %lld", &r, &c) && ~r && ~c )
    {
        memset(ff1, -1, sizeof ff1);
        memset(ff2, -1, sizeof ff2);
        memset(g, 0, sizeof g), path.clear();
        int x, y;
        while( ~scanf("%d %d", &x, &y) && x )
            g[x][y]++;

        intl res = dp1( 1, 1 );
        intl cnt = dp2( 1, 1 );
        dfs( 1, 1 );
        printf("CASE#%d: %lld %lld", ++caseno, res, cnt);
        for(int p : path) printf(" %d", p);
        printf("\n");
    }
    return 0;
}
