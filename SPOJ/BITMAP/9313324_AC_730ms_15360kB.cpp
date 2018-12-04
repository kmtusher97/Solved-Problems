#include <bits/stdc++.h>
using namespace std;

#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v

#define     pb                push_back
#define     pbk               pop_back
#define     mk_pr             make_pair
#define     NIL               -1
#define     VISITED           1
#define     UNVISITED         0
#define     PI                acos(-1.0)
#define     eps               0.0000001
#define     modulo            1000000007
#define     MX                362345
#define     INF               1123456789

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     pair<int, int>          pii;
typedef     vector<ll>              vl;
typedef     vector<int>             vi;
typedef     vector<pii>             vii;
typedef     vector<string>          vss;
typedef     queue<int>              qi;

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

ll LCM( ll a, ll b ) { return ( (a*b)/__gcd( a, b) ); }
ll POW( ll b, ll p ) { if( !p ) { return 1; } ll x = POW( b, p/2 ); x*=x; if( p&1 ) { x*=b; } return x; }
ll bigMod( ll b, ll p, ll m ) {  if( !p ) { return 1; } ll x = bigMod( b, p/2, m ); x = (x*x) % m; if( p&1 ) { x = (b*x) % m; } return x;  }
ll inv_mod( ll x ) { return bigMod( x, modulo-2, modulo ); }

const int mx = 200;
string G[mx];
int n, m, cst[mx][mx];
bool vis[mx][mx];

bool isValid( int x, int y ) {
        if( x<0 || y<0 || x>=n || y>=m || vis[x][y] ) return false;
        return true;
}

void BFS( int x, int y ) {
        memset(vis, UNVISITED, sizeof vis);
        qi q; q.push(x), q.push(y), vis[x][y] = VISITED, cst[x][y] = 0;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                int v = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                        int uu = u+dx[i];
                        int vv = v+dy[i];
                        if( isValid(uu, vv) && cst[uu][vv] > cst[u][v]+1 ) {
                                q.push(uu), q.push(vv), vis[uu][vv] = VISITED;
                                cst[uu][vv] = min( cst[uu][vv], cst[u][v]+1 );
                        }
                }
        }
}

int main() {
        FasterIO

        int cases, caseno;
        cin >> cases;
        while( cases-- ) {
                cin >> n >> m;
                for(int i=0; i<n; i++) cin >> G[i];

                for(int i=0; i<=n; i++) {
                        for(int j=0; j<=m; j++) {
                                cst[i][j] = INF;
                        }
                }
                for(int i=0; i<n; i++) {
                        for(int j=0; j<m; j++) {
                                if( G[i][j] == '1' ) BFS(i, j);
                        }
                }

                for(int i=0; i<n; i++) {
                        cout << cst[i][0];
                        for(int j=1; j<m; j++) cout << " " << cst[i][j];
                        cout << endl;
                }
        }

        return 0;
}
