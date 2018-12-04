/*  ~*BISMILLAHIR RAHMARNIR RAHIM *~  */
#include <bits/stdc++.h>
using namespace std;

const int inf = 11234567;
int N, M;
map<string, int> mp;

struct HopcroftKarp {
        static const int MX_N = 360;
        int n, m, match[MX_N], dist[MX_N];
        vector<int> G[MX_N];

        void initialize( int _n, int _m ) {
          n = _n, m = _n;
          for(int i=0; i<=n+m; i++) G[i].clear();
        }

        void addEdge( int u, int v ) {
          G[u].push_back(v);
          G[v].push_back(u);
        }

        bool bfs() {
          queue<int> Q;
          for(int i=1; i<=n; i++) {
            if( match[i] ) dist[i] = inf;
            else Q.push(i), dist[i] = 0;
          }
          dist[0] = inf;

          while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            if( !u ) continue;
            for(int j=0; j<(int)G[u].size(); j++) {
              int v = G[u][j];
              if( dist[match[v]]!=inf ) continue;
              dist[match[v]] = dist[u] + 1, Q.push( match[v] );
            }
          }
          return ( dist[0]!=inf );
        }

        bool dfs( int u ) {
          if( u ) {
            for(int j=0; j<(int)G[u].size(); j++) {
              int v = G[u][j];
              if( dist[match[v]]==dist[u]+1 ) {
                if( dfs( match[v] ) ) {
                  match[u] = v;
                  match[v] = u;
                  return true;
                }
              }
            }
            dist[u] = inf;
            return false;
          }
          return true;
        }

        int maxBPM() {
          int ret = 0;
          memset(match, 0, sizeof match);
          while( bfs() ) {
            for(int i=1; i<=n; i++)
              if( !match[i] && dfs( i ) ) ret++;
          }
          return ret;
        }
} HP;

int main() {
  mp["XXL"] = 1;
  mp["XL"] = 2;
  mp["L"] = 3;
  mp["M"] = 4;
  mp["S"] = 5;
  mp["XS"] = 6;

  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &N, &M);
    HP.initialize( M, N*6 );
    for(int i=1; i<=M; i++) {
      char c[5];
      string clr;
      scanf("%s", c), clr = c;
      for(int j=1; j<=N; j++) {
        HP.addEdge( i, (6*(j-1))+mp[clr]+M );
      }
      scanf("%s", c), clr = c;
      for(int j=1; j<=N; j++) {
        HP.addEdge( i, (6*(j-1))+mp[clr]+M );
      }
    }
    int res = HP.maxBPM();
    printf("Case %d: ", ++caseno);
    if( res==M ) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
