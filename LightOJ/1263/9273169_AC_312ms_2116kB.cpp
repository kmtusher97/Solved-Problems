#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair
#define VISITED 1
#define UNVISITED 0

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 123456;
int n, m, now[1020], ar[1020];
vi Adjcnt[1005];
bool vis[1025];

void clrGrp() {
        for(int i=0; i<=1003; i++) Adjcnt[i].clear();
}

bool BFS( int x ) {
        qi q; q.push(x), vis[x] = VISITED;
        vi nn; nn.pb(x);

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                for(int i=0; i<Adjcnt[u].size(); i++) {
                        int v = Adjcnt[u][i];
                        if( vis[v] == UNVISITED ) {
                                q.push(v), nn.pb(v), vis[v] = VISITED;
                        }
                }
        }

        int sm = 0, sz = nn.size();
        for(int i=0; i<sz; i++) sm += now[ nn[i] ];

        if( sm%sz != 0 ) return false;
        for(int i=0; i<sz; i++) ar[ nn[i] ] = sm/sz;
        return true;
}

int main() {
        int cases, caseno = 0;
        scanf("%d", &cases);
        while( cases-- ) {
                int sm = 0, u, v;
                scanf("%d %d", &n, &m);
                for(int i=1; i<=n; i++) scanf("%d", &now[i]);
                while( m-- ) {
                        scanf("%d %d", &u, &v);
                        Adjcnt[u].pb(v), Adjcnt[v].pb(u);
                }

                bool ans;
                memset(vis, UNVISITED, sizeof vis);
                memset(ar, -1, sizeof ar);
                for(int i=1; i<=n; i++) {
                        if( vis[i] == UNVISITED ) ans = BFS(i);
                        if( !ans ) break;
                }

                if( ans ) {
                        for(int i=2; i<=n; i++) if( ar[i] != ar[i-1] ) {
                                ans = false;
                                break;
                        }
                }

                printf("Case %d: ", ++caseno);
                ans ? printf("Yes\n") : printf("No\n");

                clrGrp();
        }

        return 0;
}
