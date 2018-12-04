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
#define     MX                62345
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

pair<int, pii> xyz[MX];
int N, hgt[MX];

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0, n;
        pii temp, temp1;

        while( cin >> n && n ) {
                N = 0;
                while( n-- ) {
                        int a, b, c;
                        cin >> a >> b >> c;
                        temp = mk_pr(b, c), xyz[N++] = mk_pr(a, temp);
                        temp = mk_pr(c, b), xyz[N++] = mk_pr(a, temp);
                        temp = mk_pr(a, c), xyz[N++] = mk_pr(b, temp);
                        temp = mk_pr(c, a), xyz[N++] = mk_pr(b, temp);
                        temp = mk_pr(a, b), xyz[N++] = mk_pr(c, temp);
                        temp = mk_pr(b, a), xyz[N++] = mk_pr(c, temp);
                }

                sort(xyz, xyz+N);

//                NL;
//                for(int j=0; j<N; j++) {
//                        cout << xyz[j].first << " ";
//                        pii yz;
//                        yz = xyz[j].second;
//                        cout << yz.first << " " << yz.second << endl;
//                }
//                NL;

                for(int i=0; i<N; i++) {
                        temp = xyz[i].second;
                        hgt[i] = temp.second;
                }

                for(int i=0; i<N; i++) {
                        temp = xyz[i].second;
                        for(int j=i+1; j<N; j++) {
                                temp1 = xyz[j].second;
                                if( xyz[i].first < xyz[j].first && temp.first < temp1.first ) {
                                        if( hgt[j] < hgt[i] + temp1.second ) hgt[j] = hgt[i] + temp1.second;
                                }
                        }
                }

                int mx = 0;
                for(int i=0; i<N; i++) {
                        mx = max(mx, hgt[i]);
                }

                cout << "Case " << ++caseno << ": " << "maximum height = " << mx << endl;
        }

        return 0;
}
