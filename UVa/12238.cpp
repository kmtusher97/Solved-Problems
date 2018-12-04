#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef queue<int> qi;

const int MX = 112345;
int level[MX], prnt[MX], sp[20][MX];
ll cost[MX];
vii adjcnt[MX];

void bfs() {
    memset(level, -1, sizeof level);
    memset(prnt, -1, sizeof prnt);
    memset(cost, 0, sizeof cost);
    qi q; q.push(0); level[0] = 0, cost[0] = 0;

    while( !q.empty() ) {
        int u = q.front(); q.pop();
        for(int i=0, sz=adjcnt[u].size(); i<sz; ++i) {
            int v = adjcnt[u][i].first;
            if( level[v] == -1 ) {
                q.push(v), prnt[v] = u;
                level[v] = level[u]+1;
                cost[v] = cost[u] + adjcnt[u][i].second;
            }
        }
    }
}

void sprs_tbl( int n ) {
    memset(sp, -1, sizeof sp);
    for(int i=0; i<n; ++i) {
        sp[0][i] = prnt[i];
    }
    for(int i=1; (1<<i)<n; ++i) {
        for(int j=0; j<n; ++j) {
            if( sp[i-1][j] != -1 )
                sp[i][j] = sp[i-1][sp[i-1][j]];
        }
    }
}

int level_up( int p, int q ) {
    for(int i=18; i>=0; --i) {
        if( level[p]-(1<<i) >= level[q] ) {
            p = sp[i][p];
        }
    }
    return p;
}

int LCA( int p, int q ) {
    for(int i=18; i>=0; --i) {
        if( sp[i][p] != -1 && sp[i][p] != sp[i][q] ) {
            p = sp[i][p], q = sp[i][q];
        }
    }
    return prnt[p];
}

void grph_clear() {
    for(int i=0; i<1e5+100; ++i) {
        adjcnt[i].clear();
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, Q, p, q, lca;
    while( cin >> n && n ) {
        grph_clear();
        for(int i=1, a, c; i<n; ++i) {
            cin >> a >> c;
            adjcnt[i].pb( mk_pr(a, c) );
            adjcnt[a].pb( mk_pr(i, c) );
        }
        bfs();
        sprs_tbl(n);
        cin >> Q;
        vector<ll> v;
        while( Q-- ) {
            cin >> p >> q;
            ll cst = cost[p]+cost[q];
            if( level[p] > level[q] ) {
                p = level_up( p, q );
            }
            else if( level[p] < level[q] ) {
                q = level_up( q, p );
            }
            if( p == q ) lca = p;
            else lca = LCA(p, q);
            cst -= (2 * cost[lca]);
            v.pb(cst);
        }
        cout << v[0];
        for(int i=1, sz=v.size(); i<sz; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}
