/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef pair<int, int> pii;
#define MX_N 105
int n, a[MX_N], ff[MX_N][MX_N][MX_N];
pii b[MX_N];

int dfs( int pos, int lft, int rgt ) {
  if( pos == n ) return 0;
  int& ret = ff[pos][lft][rgt];
  if( ~ret ) return ret;

  ret = 0;
  if( a[pos] >= lft && a[pos] <= rgt )
    ret = max(ret, 1 + max(dfs( pos + 1, a[pos], rgt ), dfs( pos + 1, lft, a[pos] )));
  ret = max(ret, dfs( pos + 1, lft, rgt ));
  return ff[pos][lft][rgt] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", a + i), b[i] = {a[i], i};

    sort(b, b + n);
    for(int i = 0, j = 1; i < n; i++) {
      if( i > 0 && b[i - 1].F != b[i].F ) j++;
      a[b[i].S] = j;
    }

    memset(ff, -1, sizeof ff);
    int res = dfs( 0, 0, 101 );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
