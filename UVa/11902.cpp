#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 123456;
vi Adjcnt[123];
int n, grp[123][123];
bool vis1[123], vis2[123], vis[123][123];

void bfs( int x ) {
        memset(vis1, 0, sizeof vis1);
        qi q; q.push(0), vis1[0] = true;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                for(int i=0; i<Adjcnt[u].size(); i++) {
                        int v = Adjcnt[u][i];
                        if( !vis1[v] ) {
                                q.push(v), vis1[v] = true;
                        }
                }
        }

        for(int i=0; i<n; i++) if( vis1[i] ) vis[0][i] = true;
}

void bfs1( int x ) {
        memset(vis2, 0, sizeof vis2);
        qi q; q.push(0), vis2[0] = true;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                for(int i=0; i<Adjcnt[u].size(); i++) {
                        int v = Adjcnt[u][i];
                        if( !vis2[v] && v != x ) {
                                q.push(v), vis2[v] = true;
                        }
                }
        }

        for(int i=0; i<n; i++) if( !vis2[i] && vis1[i] ) vis[x][i] = true;
}

void dvidr() {
        printf("+");
        for(int i=1; i<2*n; i++) printf("-");
        printf("+\n");
}

void clrGrp() {
        for(int i=0; i<102; i++) Adjcnt[i].clear();
}

int main() {
        int cases, caseno=0;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d", &n);
                for(int i=0; i<n; i++) {
                        for(int j=0, p; j<n; j++) {
                                scanf("%d", &p);
                                if( p ) Adjcnt[i].pb(j);
                        }
                }

                memset(vis, 0, sizeof vis);
                bfs(0);
                for(int i=1; i<n; i++) bfs1(i);

                printf("Case %d:\n", ++caseno);
                dvidr();
                for(int i=0; i<n; i++) {
                        printf("|");
                        for(int j=0; j<n; j++) {
                                if( vis[i][j] == 1 ) printf("Y|");
                                else printf("N|");
                        }
                        printf("\n"); dvidr();
                }

                clrGrp();
        }

        return 0;
}
