/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

const int MX = 60;
char grd[MX/2][MX/2];
int n, g, h, id[MX/2][MX/2], Dist[MX][MX];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int tempDist[MX/2][MX/2];

struct Hopcroft_Karp {
        static const int MX_N = 60;
        int nodes;
        int match[MX_N*2], dist[MX_N];
        vector<int> G[MX_N];

        void initialize( int _n ) {
          nodes = _n;
          memset(match, 0, sizeof match);
          for(int i=0; i<=nodes; i++) G[i].clear();
        }

        bool bfs_HP() {
          queue<int> Q; dist[0] = INT_MAX;
          for(int i=1; i<=nodes; i++) {
            if( match[i] ) dist[i] = INT_MAX;
            else Q.push(i), dist[i] = 0;
          }

          while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            if( !u ) continue;
            for(int i=0; i<(int)G[u].size(); i++) {
              int v = G[u][i];
              if( dist[match[v]]!=INT_MAX ) continue;
              dist[match[v]] = dist[u] + 1;
              Q.push(match[v]);
            } }
          return ( dist[0]!=INT_MAX );
        }

        bool dfs_HP( int u ) {
          if( u ) {
            for(int i=0; i<(int)G[u].size(); i++) {
              int v = G[u][i];
              if( dist[match[v]]==dist[u]+1 ) {
                if( dfs_HP( match[v] ) ) {
                  match[v] = u;
                  match[u] = v;
                  return true;
            } } }
            dist[u] = INT_MAX;
            return false;
          }
          return true;
        }

        int Maximum_BPM() {
          int ret = 0;
          while( bfs_HP() ) {
            for(int i=1; i<=nodes; i++)
              if( !match[i] && dfs_HP( i ) ) ret++;
          }
          return ret;
        }
} HP;

bool valid( int x, int y ) {
  return ( x>=0 && x<n && y>=0 && y<n && grd[x][y]!='#' );
}

void BFS( int x, int y ) {
  queue<int> Q; Q.push(x), Q.push(y);
  memset(tempDist, -1, sizeof tempDist);
  tempDist[x][y] = 0;

  while( !Q.empty() ) {
    int ux = Q.front(); Q.pop();
    int uy = Q.front(); Q.pop();
    for(int i=0; i<4; i++) {
      int vx = ux+dx[i];
      int vy = uy+dy[i];
      if( valid( vx, vy ) && tempDist[vx][vy]==-1 ) {
        tempDist[vx][vy] = tempDist[ux][uy] + 1;
        Q.push(vx), Q.push(vy);
        if( grd[vx][vy]=='H' ) Dist[ id[x][y] ][ id[vx][vy] ] = tempDist[vx][vy];
      } } }
}

void form_Graph( int est ) {
  HP.initialize( h );
  for(int i=1; i<=g; i++)
  for(int j=1; j<=h; j++) {
    if( Dist[i][j]>est ) continue;
    HP.G[j].push_back(i+h);
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    for(int i=0; i<MX; i++)
    for(int j=0; j<MX; j++)
      Dist[i][j] = INT_MAX;

    scanf("%d", &n), g = h = 0;
    for(int i=0; i<n; i++) {
      scanf("%s", grd[i]);
      for(int j=0; j<n; j++) {
        if( grd[i][j]=='G' ) id[i][j] = ++g;
        if( grd[i][j]=='H' ) id[i][j] = ++h;
      }
    }

    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if( grd[i][j]=='G' ) BFS( i, j );

    int lo = 0, hi = 700, res = INT_MAX;
    while( lo<=hi ) {
      int mid = lo+(hi-lo)/2, cst = 0;
      form_Graph( mid );
      if( HP.Maximum_BPM()==h ) hi = mid-1, res = min(res, mid);
      else lo = mid+1;
    }
    printf("Case %d: ", ++caseno);
    if( res==INT_MAX ) printf("Vuter Dol Kupokat\n");
    else printf("%d\n", res*2+2);
  }
  return 0;
}
