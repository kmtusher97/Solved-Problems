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
#define     modulo            1000000
#define     MX                262345
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

ll memo[202][202];

ll ff( ll i, ll j ) {
        if( i == 0 || j == 1 ) return 1LL;
        if( memo[i][j] >= 0LL ) return memo[i][j];
        ll r = 0, k;
        for(k=0; k<=i; k++) {
                r = ( r % modulo + ff(i-k, j-1) % modulo ) % modulo;
        }
        return memo[i][j] = r;
}

int main() {
        ///write;
        FasterIO
        ll n, m;
        while( cin >> n >> m ) {
                if( !n && !m ) break;
                memset(memo, -1, sizeof memo);
                cout << ff(n, m) << endl;
        }

        return 0;
}
