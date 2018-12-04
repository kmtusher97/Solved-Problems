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
const int inf = 1123456789;
int cst[1005];
vi Adjcnt[1020];

void prmFctr( int x ) {
        int n = x;
        if( 2 < n && n%2 == 0 ) {
                Adjcnt[x].pb(2+x);
                while( n%2 == 0 ) { n /= 2; }
        }

        for(int i=3; i<=(int)sqrt(x); i+=2) {
                if( n%i == 0 ) {
                        Adjcnt[x].pb(i+x);
                        while( n%i == 0 ) { n /= i; };
                }
        }

        if( n > 1 && n < x ) Adjcnt[x].pb(n+x);
}

void mkGrp() {
        for(int i=1; i<1005; i++) {
                prmFctr(i);
        }
}

int bfs( int x, int y ) {
        for(int i=0; i<=y+2; i++) cst[i] = inf;
        qi q; q.push(x), cst[x] = 0;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                for(int i=0; i<(int)Adjcnt[u].size(); i++) {
                        int v = Adjcnt[u][i];
                        if( cst[v] == inf ) {
                                q.push(v), cst[v] = cst[u] + 1;
                        }
                }
        }

        if( cst[y] == inf ) return -1;
        return cst[y];
}

int main() {
        mkGrp();
        int cases, caseno = 0, s, t;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d %d", &s, &t);
                printf("Case %d: %d\n", ++caseno, bfs(s, t));
        }

        return 0;
}
