/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 1002

int n, m;

struct Hopcroft_Karp {
        int nodes, dist[MX_N], match[MX_N*2];
        vector<int> G[MX_N];

        void initialize( int _n ) {
          nodes = _n;
          for(int i=0; i<MX_N; i++) G[i].clear();
        }

        void addEdge( int u, int v ) { G[u].push_back(v); }

        bool bfs() {
          queue<int> Q; dist[0] = INT_MAX;
          for(int i=1; i<=nodes; i++) {
            if( match[i] ) dist[i] = INT_MAX;
            else Q.push(i), dist[i] = 0;
          }

          while( !Q.empty() ) {
            int u = Q.front(); Q.pop();
            if( !u ) continue;
            for(int i=0, sz=G[u].size(); i<sz; i++) {
              int v = G[u][i];
              if( dist[match[v]]!=INT_MAX ) continue;
              dist[match[v]] = dist[u]+1;
              Q.push(match[v]);
            }
          }
          return dist[0]!=INT_MAX;
        }

        bool dfs( int u ) {
          if( u ) {
            for(int i=0, sz=G[u].size(); i<sz; i++) {
              int v = G[u][i];
              if( dist[match[v]]!=dist[u]+1 ) continue;
              if( dfs( match[v] ) ) {
                match[v] = u;
                match[u] = v;
                return true;
            } }
            dist[u] = INT_MAX;
            return false;
          }
          return true;
        }

        int Maximum_Match() {
          memset(match, 0, sizeof match);
          int cnt = 0;

          while( bfs() ) {
            for(int i=1; i<=nodes; i++)
              if( !match[i] && dfs( i ) ) cnt++;
          }
          return cnt;
        }
} HP;

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &m);
    HP.initialize( n );
    for(int i=0, a, b; i<m; i++) {
      scanf("%d %d", &a, &b);
      HP.addEdge( a, b+n );
    }
    int res = n - HP.Maximum_Match();
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
