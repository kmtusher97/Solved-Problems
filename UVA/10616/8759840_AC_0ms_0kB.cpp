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

void precal() {
        memset( dp, 0, sizeof dp );
        for(int i=0; i<=N; i++) dp[i][M][0] = 1;
        for(int i=N-1; i>=0; i--) {
                for(int j=M-1; j>=0; j--) {
                        for(int k=0; k<D; k++) {
                                dp[i][j][k] = dp[i+1][j+1][ ((k+ar[i])%D+D)%D ] + dp[i+1][j][k];
                        }
                }
        }
        cout << dp[0][0][0] << endl;
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
                        cout << "QUERY " << ++queryno << ": ";
                        precal();
                }
        }

        return 0;
}
