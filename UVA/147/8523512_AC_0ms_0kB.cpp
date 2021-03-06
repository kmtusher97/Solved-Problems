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
#define     bug               pf("ok\n")
#define     VISITED           1
#define     UNVISITED         0
#define     PI                acos(-1.0)
#define     eps               0.0000001
#define     modulo            1000000007
#define     MX                262345
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

ll coins[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
ll dp[40000][12];

ll ff( ll x, ll p ) {
        if( x < 0 || p > 10 ) return 0;
        if( x == 0 ) return 1;
        if( dp[x][p] != -1 ) return dp[x][p];
        return dp[x][p] = ff( x - coins[p], p ) + ff( x, p + 1 );
}

int main() {
        ///write;
        ///FasterIO;
        memset( dp, -1, sizeof dp );
        double n;
        while( ~sc("%lf", &n) && n != 0.00 ) {
                n += eps;
                ll m = n * 100;
                ll ans = ff( m, 0 );
                pf("%6.2lf%17lld\n", n, ans);
        }
        return 0;
}
