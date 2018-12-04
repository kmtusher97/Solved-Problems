/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 502
int n, m, U[MX_N][MX_N], R[MX_N][MX_N], ff[MX_N][MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) scanf("%d", &U[i][j]);
    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) scanf("%d", &R[i][j]);

    for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) U[i][j] += U[i][j-1];
    for(int j=1; j<=m; j++)
      for(int i=1; i<=n; i++) R[i][j] += R[i-1][j];

    memset(ff, 0, sizeof ff);
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
        ff[i][j] = max( U[i][j] + ff[i-1][j], R[i][j] + ff[i][j-1] );
      }
    }
    printf("Case %d: %d\n", ++caseno, ff[n][m]);
  }
  return 0;
}
