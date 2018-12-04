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
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int coins[] = { 1, 5, 10, 25, 50 };
ll dp[MX][6];

ll way( int x, int i ) {
        if( i > 4 || x < 0 ) return 0;
        if( x == 0 ) return 1;
        if( dp[x][i] != -1 ) return dp[x][i];
        dp[x][i] = way( x, i+1 ) + way( x-coins[i], i ) ;
        return dp[x][i];
}

int main() {
        ///write;
        ///FasterIO;
        memset(dp, -1, sizeof dp);
        int n;
        while( ~sc("%d", &n) ) {
                ll ans = way(n, 0);
                if( ans == 1 ) pf("There is only 1 way to produce %d cents change.\n", n);
                else pf("There are %lld ways to produce %d cents change.\n", ans, n);
        }

        return 0;
}
