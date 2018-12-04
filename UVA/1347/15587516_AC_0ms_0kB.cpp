/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define MX_N 1003
const double inf = 1e15;
struct point {
  int x, y;
  point() { x = y = 0; }
  point( int _x, int _y ) : x(_x), y(_y) { }
};

double dist( point a, point b ) {
  return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

int n;
vector<point> P(MX_N);
double ff[MX_N][MX_N];

double dfs( int i, int j ) {
  if( i == n - 1 || j == n - 1 )
    return dist( P[j], P[n] ) + dist( P[i], P[n] );

  double& ret = ff[i][j];
  if( ret ) return ret;

  ret = 0;
  int k = max(i, j) + 1;
  ret = min( dist( P[i], P[k] ) + dfs( k, j ), dist( P[j], P[k] ) + dfs( i, k ) );
  return ff[i][j] = ret;
}

int main() {
  while( ~scanf("%d", &n) ) {
    for(int i = 1; i <= n; i++)
      scanf("%d %d", &P[i].x, &P[i].y);

    memset(ff, 0, sizeof ff);
    printf("%.2lf\n", dfs( 1, 1 ));
  }
  return 0;
}
