/*
************************************************
*           * KAMRUL HASAN TUDHER              *
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
typedef     priority_queue<int>     pq;
typedef     priority_queue<pii>     pqii;

#define     sc              scanf
#define     pf              printf
#define     NL              printf("\n")
#define     pb              push_back
#define     mk_pr           make_pair
#define     NIL             -1
#define     VISITED         1
#define     UNVISITED       0
#define     PI              acos(-1.0)
#define     eps             0.0000001
#define     modulo          1000000007
#define     MX              32345

#define     READ            freopen("INPUT.in", "r", stdin)
#define     WRITE           freopen("OUTPUT.out", "w", stdout)
#define     read            freopen("INPUT.txt", "r", stdin)
#define     write           freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, v)   memset(arr, v, sizeof(arr))
#define     FasterIO        ios_base :: sync_with_stdio( false ); cin.tie( 0 );

int dx4[] = { 0, 0, 1, -1 };    ///4 connected
int dy4[] = { -1, 1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy8[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

ll LCM( ll a, ll b ) { return ( (a*b)/__gcd( a, b) ); }
ll POW( ll b, ll p ) { if( !p ) { return 1; } ll x = POW( b, p/2 ); x*=x; if( p&1 ) { x*=b; } return x; }
ll bigMod( ll b, ll p, ll m ) {  if( !p ) { return 1; } ll x = bigMod( b, p/2, m ); x = (x*x) % m; if( p&1 ) { x = (b*x) % m; } return x;  }
ll inv_mod( ll x ) { return bigMod( x, modulo-2, modulo ); }
//int prnt[500]; int prnt_find( int x ) { if( x == prnt[x] ) return x; return prnt[x] = prnt_find( prnt[x] ); }

///geometry functions
double reg_hexagon_area( double x ) { return ( (3.0 * sqrt(3.0) * x * x) / 2.0 ); }
double slope( double x1, double x2, double y1, double y2 ) { return ( (y1-y2) / (x1-x2) ); }
double oppst_side_of_angle( double a, double b, double angle ) { angle = (PI*angle)/180.0; return sqrt( a*a + b*b - (2*a*b*cos(angle)) ); }
double eucld_dis( double x1, double y1, double x2, double y2 ) { return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ); }
double trngle_area_hiron( double a, double b, double c ) { double s = (a+b+c)/2.0; return sqrt( s*(s-a)*(s-b)*(s-c) ); }

struct data{ int u, v, w; };

/*..............*/

int order[30], ar[30], dp[30][30];

int LCS( int n ) {
        int i, j;
        memst(dp, UNVISITED);
//        cout << "*** ";
//        for(i=1; i<=n; i++) cout << order[i] << " ";
//        NL;
        for(i=1; i<=n; i++) {
                for(j=1; j<=n; j++) {
                        if( order[i] == ar[j] ) {
                                dp[i][j] = dp[i-1][j-1] + 1;
                        }
                        else {
                                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
                        }
                }
        }

        return dp[n][n];
}

int main() {
        ///FasterIO;
        ///write;
        int cases, caseno = 0, n=0, i, j, a;
        sc("%d", &n);
        for(i=1; i<=n; i++) {
                sc("%d", &a);
                order[a] = i;
        }
        getchar();
        string line;
        while( getline(cin, line) && line != "" ) {
                stringstream ss(line);
                vi v;
                while( ss >> a ) {
                        v.pb(a);
                }
                if( v.size() == 1 ) {
                        n = v[0];
                        for(i=1; i<=n; i++) {
                                sc("%d", &a);
                                order[a] = i;
                        }
                        getchar();
                }
                else {
                        for(i=0, j=1; i<v.size(); i++, j++) {
                                ar[ v[i] ] = j;
                        }
                        pf("%d\n", LCS(n));
                }
        }

        return 0;
}
