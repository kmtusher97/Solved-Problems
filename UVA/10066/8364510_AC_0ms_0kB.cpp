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
#define     MX              62345
#define     INF             10000

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

/*.....................................................................*/

int n1, n2, ar1[200], ar2[200], dp[200][200];

int LCS() {
        memst(dp, 0);
        for(int i=0; i<n1; i++) {
                for(int j=0; j<n2; j++) {
                        if( ar1[i] == ar2[j] ) dp[i+1][j+1] = dp[i][j] + 1;
                        else dp[i+1][j+1] = max( dp[i][j+1], dp[i+1][j] );
                }
        }
        return dp[n1][n2];
}

int main() {
        ///FasterIO;
        ///write;
        int cases, caseno = 0;
        while( sc("%d %d", &n1, &n2) == 2 && n1 && n2 ) {
                for(int i=0; i<n1; i++) sc("%d", &ar1[i]);
                for(int i=0; i<n2; i++) sc("%d", &ar2[i]);
                pf("Twin Towers #%d\n", ++caseno);
                pf("Number of Tiles : %d\n", LCS());
                NL;
        }

        return 0;
}
