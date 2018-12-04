/*  ~*BISMILLAHIR RAHMANIR RAHIM  */
#include <bits/stdc++.h>
using namespace std;

const int MX_N = 120;
int r, c;
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
string g[MX_N], s;
bool vis[MX_N][MX_N];

bool ok( int x, int y ) {
  return ( x >= 0 && y >= 0 && x < r && y < c && !vis[x][y] );
}

bool dfs( int ux, int uy, int id ) {
  if( g[ux][uy] != s[id] ) return false;
  if( id == 9 ) return g[ux][uy] == s[id];
  vis[ux][uy] =  true;

  bool ff = false;
  for(int i = 0; i < 8; i++) {
    int vx = ux + dx[i];
    int vy = uy + dy[i];
    if( ok( vx, vy ) ) {
      ff |= dfs( vx, vy, id + 1 );
    }
  }
  if( !ff ) vis[ux][uy] = false;
  return ff;
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
  s = "ALLIZZWELL";
  int cases;
  cin >> cases;
  while( cases-- ) {
    cin >> r >> c;
    for(int i = 0; i < r; i++)
      cin >> g[i];

    bool f = false;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if( g[i][j] == 'A' ) {
          memset(vis, 0, sizeof vis);
          f |= dfs( i, j, 0 );
        }
        if( f ) break;
      }
      if( f ) break;
    }

    if( f ) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
