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
#define     MX                152345
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int N, Q, D, M, ar[220], dp[220][12][22];

int ff( int i, int j, int x ) {
        if( i == N ) {
                if( j == M && (x+D) % D == 0 ) return 1;
                return 0;
        }
        if( j == M ) {
                if( (x+D) % D == 0 ) return 1;
                return 0;
        }
        if( dp[i][j][x] != -1 ) return dp[i][j][x];
        return dp[i][j][x] = ff( i+1, j+1, ( (x+ar[i])%D + D ) % D ) + ff( i+1, j, x );
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0;
        while( cin >> N >> Q && N && Q ) {
                for(int i=0; i<N; i++) cin >> ar[i];
                cout << "SET " << ++caseno << ":" << endl;
                int queryno = 0;
                while( Q-- ) {
                        cin >> D >> M;
                        memset(dp, -1, sizeof dp);
                        cout << "QUERY " << ++queryno << ": ";
                        cout << ff(0, 0, 0) << endl;
                }
        }

        return 0;
}
