/*
************************************************
*           * KAMRUL HASAN TUSHER              *
*           * JAHANGIRNAGAR UNIVERSITY         *
*           * CSE-45                           *
************************************************
*/
#include <bits/stdc++.h>

using namespace std;

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     pair<int, int>          pii;
typedef     pair<ll, ll>            pll;
typedef     pair<double, double>    pdd;
typedef     vector<double>          vd;
typedef     vector<ll>              vl;
typedef     vector<int>             vi;
typedef     vector<pii>             vii;
typedef     vector<pll>             vll;
typedef     vector<char>            vcc;
typedef     vector<string>          vss;
typedef     queue<int>              qi;
typedef     queue<pii>              qii;
typedef     priority_queue<int>     PQ;
typedef     priority_queue<pii>     PQII;

#define     sc                scanf
#define     pf                printf
#define     NL                printf("\n")
#define     pb                push_back
#define     mk_pr             make_pair
#define     NIL               -1
#define     VISITED           1
#define     UNVISITED         0
#define     PI                acos(-1.0)
#define     eps               0.0000001
#define     modulo            1000000007
#define     MX                262345
#define     INF               10000000000

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

int dx4[] = { 0, 0, 1, -1 };    ///4 connected
int dy4[] = { -1, 1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy8[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

ll LCM( ll a, ll b ) { return ( (a*b)/__gcd( a, b) ); }
ll POW( ll b, ll p ) { if( !p ) { return 1; } ll x = POW( b, p/2 ); x*=x; if( p&1 ) { x*=b; } return x; }
ll bigMod( ll b, ll p, ll m ) {  if( !p ) { return 1; } ll x = bigMod( b, p/2, m ); x = (x*x) % m; if( p&1 ) { x = (b*x) % m; } return x;  }
ll inv_mod( ll x ) { return bigMod( x, modulo-2, modulo ); }
///int prnt[500]; int prnt_find( int x ) { if( x == prnt[x] ) return x; return prnt[x] = prnt_find( prnt[x] ); }

///struct data{ int u, v, w; };

/*...........................................................................................................................................*/

int alt[15][102], dp[15][102];

void precal( int n ) {
        int i, j, p, q, r;
        for(i=0; i<11; i++)
                for(j=0; j<=n; j++) dp[i][j] = INF;
        dp[0][0] = 0;

        for(j=1; j<=n; j++) {
                for(i=0; i<=9; i++) {
                        p = q = r = dp[i][j];
                        p = min( p, 30 - alt[i][j] + dp[i][j-1] );
                        if( i > 0 ) q = min( q, 60 - alt[i-1][j] + dp[i-1][j-1] );
                        if( i < 9 ) r = min( r, 20 - alt[i+1][j] + dp[i+1][j-1] );
                        dp[i][j] = min( p, min(q, r) );
                }
        }

//        for(i=9; i>=0; i--) {
//                for(j=1; j<=n; j++) cout << dp[i][j] << " ";
//                cout << endl;
//        }

        cout << dp[0][n] << endl;
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0;
        cin >> cases;
        while( cases-- ) {
                int miles, n, i, j;
                cin >> miles;
                n = miles/100;

                memset(alt, 0, sizeof alt);

                for(i=9; i>=0; i--) {
                        for(j=1; j<=n; j++) {
                                cin >> alt[i][j];
                        }
                }

                precal(n);

                if( ++caseno ) cout << endl;
        }

        return 0;
}
