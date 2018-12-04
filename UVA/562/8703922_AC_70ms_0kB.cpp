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
#define     MX                52345
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int coins[120], dp[120][MX], n, sm;

int ff( int i, int vlu ) {
        if( i == n ) {
                return abs( (sm - vlu) - vlu );
        }
        if( dp[i][vlu] != -1 ) return dp[i][vlu];
        return dp[i][vlu] = min( ff( i+1, vlu + coins[i] ), ff( i+1, vlu ) );
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0;
        cin >> cases;
        while( cases-- ) {
                cin >> n;
                sm = 0;
                for(int i=0; i<n; i++) {
                        cin >> coins[i]; sm += coins[i];
                }
                memset(dp, -1, sizeof dp);
                cout << ff(0, 0) << endl;
        }

        return 0;
}
