/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 202
int m, w, match[MX_N], cnt[MX_N];
int L[MX_N][MX_N], R[MX_N][MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases), getchar();
  while( cases-- ) {
    scanf("%d", &m), w = m;
    queue<int> Q;
    memset(L, 0, sizeof L);
    memset(R, 0, sizeof R);
    memset(cnt, 0, sizeof cnt);
    memset(match, 0, sizeof match);

    for(int i=1; i<=m; i++) {
      for(int j=1; j<=w; j++) {
        scanf("%d", &L[i][j]);
      }
      Q.push(i);
    }

    for(int i=1; i<=w; i++) {
      for(int j=1, x; j<=m; j++) {
        scanf("%d", &x);
        R[x][i+m] = j;
      }
    }

    while( !Q.empty() ) {
      int lhs = Q.front(); Q.pop();
      int rhs = L[lhs][++cnt[lhs]];
      int lhs1 = match[rhs];
      if( lhs1 && R[lhs][rhs]>R[lhs1][rhs] ) Q.push(lhs);
      else {
        match[lhs] = rhs;
        match[rhs] = lhs;
        if( lhs1 ) Q.push( lhs1 );
        match[lhs1] = 0;
      }
    }

    printf("Case %d:", ++caseno);
    for(int i=1; i<=m; i++) printf(" (%d %d)", i, match[i]);
    printf("\n");
  }
  return 0;
}


