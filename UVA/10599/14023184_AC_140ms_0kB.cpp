/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;
#define MX_N 105

int r, c, grd[MX_N][MX_N], ff1[MX_N][MX_N];
intl ff2[MX_N][MX_N];

void dfs( int x, int y ) {
  if( x<1 || y<1 ) return;

  if( ff1[x-1][y]>ff1[x][y-1] ) dfs( x-1, y );
  else dfs( x, y-1 );
  if( grd[x][y] ) printf(" %d", (x-1)*c + y);
}

int main() {
  int caseno = 0;
  while( ~scanf("%d %d", &r, &c) && ~r ) {
    for(int i=0; i<=r; i++)
      for(int j=0; j<=c; j++)
        grd[i][j] = ff1[i][j] = ff2[i][j] = 0;

    int x, y;
    while( ~scanf("%d %d", &x, &y) && x ) grd[x][y]++;
    for(int i=1; i<=r; i++)
      for(int j=1; j<=c; j++)
        ff1[i][j] = grd[i][j] + max(ff1[i-1][j], ff1[i][j-1]);

    for(int i=1; i<=r; i++)
      for(int j=1; j<=c; j++)
        if( ff1[i][j]==grd[i][j] ) ff2[i][j] = 1;

    for(int i=1; i<=r; i++)
      for(int j=1; j<=c; j++)
        for(int k=0; k<=i; k++)
          for(int l=0; l<=j; l++) {
            if( (k==i && l==j) || !grd[k][l] ) continue;
            if( ff1[i][j]==grd[i][j]+ff1[k][l] ) ff2[i][j] += ff2[k][l];
          }

    intl res = ff1[r][c], cnt = ff2[r][c];
    printf("CASE#%d: %lld %lld", ++caseno, res, cnt);
    dfs( r, c );
    printf("\n");
  }
  return 0;
}
