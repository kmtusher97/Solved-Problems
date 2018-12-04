/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

typedef long long intl;
#define MX_N 105

int r, c, grd[MX_N][MX_N], ff1[MX_N][MX_N];
intl ff2[MX_N][MX_N];
vector<int> path;

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
    path.clear();
    x = r, y = c;
    while( x>0 && y>0 ) {
      if( grd[x][y] ) path.push_back((x-1)*c + y);

      if( ff1[x-1][y]>ff1[x][y-1] ) x--;
      else y--;
    }
    for(int i=path.size()-1; i>=0; i--) printf(" %d", path[i]);
    printf("\n");
  }
  return 0;
}
