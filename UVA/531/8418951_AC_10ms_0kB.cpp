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
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

/*.................................................................................*/

vss v1, v2, v;
int dp[200][200];

void LCS() {
        int i, j, sz1 = v1.size(), sz2 = v2.size();
        memset( dp, UNVISITED, sizeof dp );
        for(i=0; i<sz1; i++)
        for(j=0; j<sz2; j++) {
                if( v1[i] == v2[j] ) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1] );
        }
        int mx = dp[sz1][sz2];
        for(i=sz1; i>0; i--) {
                for(j=sz2; j>0; j--) {
                        if( dp[i][j] == mx && v1[i-1] == v2[j-1] ) {
                                v.pb( v1[i-1] );
                                mx--;
                        }
                }
        }
        for(i=v.size()-1; i>=0; i--) {
                cout << v[i];
                if( i == 0 ) NL;
                else cout << " ";
        }

        v.clear(), v1.clear(), v2.clear();
}

int main() {
        ///write;
        string s;
        int cases, caseno = 0;
        while( cin >> s ) {
                if( s == "#" ) {
                        caseno++;
                        if( caseno > 0 && caseno % 2 == 0 ) {
                                LCS();
                        }
                }
                else {
                      if( caseno % 2 == 0 ) v1.pb(s);
                      else v2.pb(s);
                }
        }

        return 0;
}
