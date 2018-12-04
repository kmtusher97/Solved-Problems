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

int mtrx1[800][800], mtrx2[800][800], dp[800][800];

int ff( int i, int j ) {
        if( i < 1 || j < 1 ) return dp[i][j];
        if( dp[i][j] > 0 ) return dp[i][j];
        return dp[i][j] = max( mtrx2[i][j] + ff( i, j-1 ), mtrx1[i][j] + ff( i-1, j ) );
}

int main() {
        ///write;
        ///FasterIO
        int r, c, i, j, a;
        while( sc("%d %d", &r, &c) == 2 ) {
                if( !r && !c ) break;
                for(i=1; i<=r; i++) {
                        for(j=1; j<=c; j++) {
                                sc("%d", &mtrx1[i][j]);
                                mtrx1[i][j] += mtrx1[i][j-1];
                        }
                }
                for(i=1; i<=r; i++) {
                        for(j=1; j<=c; j++) {
                                sc("%d", &mtrx2[i][j]);
                                mtrx2[i][j] += mtrx2[i-1][j];
                        }
                }
                memset(dp, 0, sizeof dp);
                pf("%d\n", ff(r, c));
        }

        return 0;
}
