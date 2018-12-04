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

int totl, n_o_el;
int coins[200];
int memo[MX];

int precal() {
        memo[0] = 1;
        for(int i=1; i<=totl+50; i++) memo[i] = 0;
        for(int i=0; i<n_o_el; i++) {
                for(int j=totl; j>=0; j--) {
                        if( j >= coins[i] ) memo[j] |= memo[ j - coins[i] ];
                }
        }
        int mn = INT_MAX;
        for(int i=0; i<=totl; i++) {
                if( memo[i] ) {
                        int p = abs( i - (totl-i) );
                        mn = min(mn, p);
                }
        }
        return mn;
}

int main() {
        //write;
        //FasterIO
        int cases, caseno = 0;
        cin >> cases;
        while( cases-- ) {
                cin >> n_o_el;
                totl = 0;
                for(int i=0; i<n_o_el; i++) {
                        cin >> coins[i];
                        totl += coins[i];
                }
                cout << precal() << endl;
        }

        return 0;
}
