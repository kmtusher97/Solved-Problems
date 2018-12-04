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
bool vis[MX];
int prnt[MX];
vi Adjcnt[MX];
map<string, int> nodes;
map<int, string> cmnds;

void bfs( int x, int y, int n ) {
        memset(vis, false, sizeof vis);
        for(int i=0; i<=n+5; i++) prnt[i] = i;
        qi q; q.push(x), vis[x] = x;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                for(int i=0; i<(int)Adjcnt[u].size(); i++) {
                        int v = Adjcnt[u][i];
                        if( !vis[v] ) {
                                q.push(v), vis[v] = true;
                                prnt[v] = u;
                        }
                }
        }

        if( !vis[y] ) { cout << "No route" << endl; return; }
        int a = y;
        vi v; v.pb(y);
        while( true ) {
                if( a == x ) break;
                v.pb( prnt[a] );
                a = prnt[a];
        }

        for(int i=v.size()-2; i>=0; i--) {
                cout << cmnds[ v[i+1] ] << " " << cmnds[ v[i] ] << endl;
        }
        v.clear();
}

void clearGraph() {
        for(int i=0; i<MX; i++) Adjcnt[i].clear();
}

int main() {
        ios_base :: sync_with_stdio(0); cin.tie(0);
        
        int cases, caseno = 0, n;
        while( cin >> n ) {
                string u, v;
                int i = 0, a, b, mx = 0;
                while( n-- ) {
                        cin >> u >> v;
                        if( nodes.find(u) != nodes.end() ) a = nodes[u];
                        else a = i++, nodes[u] = a, cmnds[a] = u;

                        if( nodes.find(v) != nodes.end() ) b = nodes[v];
                        else b = i++, nodes[v] = b, cmnds[b] = v;

                        Adjcnt[a].pb(b), Adjcnt[b].pb(a); mx = max(mx, i);
                }

                cin >> u >> v;
                if( nodes.find(u) != nodes.end() ) a = nodes[u];
                else a = i++, nodes[u] = a, cmnds[a] = u;

                if( nodes.find(v) != nodes.end() ) b = nodes[v];
                else b = i++, nodes[v] = b, cmnds[b] = v;

                if( caseno++ ) cout << endl;
                bfs(a, b, i);
                clearGraph(), nodes.clear(), cmnds.clear();
        }

        return 0;
}
