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
#define     MX                12000
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int n, k;
int ar[MX], dp[200][MX];

int ff( int vlu, int i ) {
        if( i == n ) {
                if( ( vlu + k ) % k == 0 ) return 1;
                return 0;
        }
        if( dp[vlu][i] != -1 ) return dp[vlu][i];
        return dp[vlu][i] = ff( ( ( vlu + ar[i] ) % k + k ) % k, i+1  ) | ff( ( ( vlu - ar[i] ) % k + k ) % k, i+1  );
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0;
        cin >> cases;
        while( cases-- ) {
                cin >> n >> k;
                for(int i=0; i<n; i++) {
                        cin >> ar[i];
                        //ar[i] = ( ar[i] + k ) % k;
                }
                memset(dp, -1, sizeof dp);
                ff(0, 0) ? cout << "Divisible" : cout << "Not divisible";
                cout << endl;
        }

        return 0;
}
