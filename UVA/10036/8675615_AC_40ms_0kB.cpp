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
int ar[MX], dp[MX][200];

void precal() {
        memset(dp, 0, sizeof dp);
        dp[n][0] = 1;
        for(int i=n-1; i>=0; i--) {
                for(int j=0; j<k; j++) {
                        dp[i][j] = dp[i+1][ ( j + ( ar[i] + k ) % k + k ) % k ] | dp[i+1][ ( j - ( ar[i] + k ) % k + k ) % k ];
                }
        }
        dp[0][0] ? cout << "Divisible" : cout << "Not divisible";
        cout << endl;
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
                        //ar[i] = (ar[i]+k) % k;
                }
                precal();
        }

        return 0;
}
