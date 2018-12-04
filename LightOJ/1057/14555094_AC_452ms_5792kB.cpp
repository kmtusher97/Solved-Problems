/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 22
int m, n, id, ff[1<<16][16];
int nodes[MX_N][2], dd[MX_N][MX_N], DD[MX_N][MX_N];
char G[MX_N][MX_N];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void bfs( int x, int y ) {
  for(int i=0; i<=m; i++)
    for(int j=0; j<=n; j++) dd[i][j] = 12345;
  queue<int> Q; Q.push(x), Q.push(y);
  dd[x][y] = 0;

  while( !Q.empty() ) {
    int ux = Q.front(); Q.pop();
    int uy = Q.front(); Q.pop();
    for(int i=0; i<8; i++) {
      int vx = ux+dx[i];
      int vy = uy+dy[i];
      if( vx<0 || vx>m || vy<0 || vy>n || dd[vx][vy]<=dd[ux][uy]+1 ) continue;
      dd[vx][vy] = dd[ux][uy]+1;
      Q.push(vx), Q.push(vy);
    }
  }
}

int dfs_Bt( int mask, int last ) {
  if( mask==(1<<(id+1))-1 ) return DD[0][last];
  int& ret = ff[mask][last];
  if( ret ) return ret;

  ret = 123456;
  for(int i=0; i<=id; i++) {
    if( mask&(1<<i) ) continue;
    ret = min(ret, DD[last][i] + dfs_Bt( mask|(1<<i), i ));
  }
  return ff[mask][last] = ret;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &m, &n);
    for(int i=0; i<m; i++)
      scanf("%s", G[i]);
    id = 0;
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
        if( G[i][j]=='g' ) nodes[++id][0] = i, nodes[id][1] = j;
        else if( G[i][j]=='x' ) nodes[0][0] = i, nodes[0][1] = j;
      }
    }
    
    for(int i=0; i<=id; i++) {
      bfs( nodes[i][0], nodes[i][1] );
      for(int j=0; j<=id; j++) {
        DD[i][j] = DD[j][i] = dd[nodes[j][0]][nodes[j][1]];
      }
    }
    
    memset(ff, 0, sizeof ff);
    int res = dfs_Bt( 0, 0 );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}

