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
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int ar[MX];
int level[MX];

int LB( int lo, int hi, int x ) {
        if( lo > hi ) return lo;
        int mid = lo + (hi-lo) / 2;
        if( level[mid] < x ) {
                return LB( mid+1, hi, x );
        }
        else {
                return LB( lo, mid-1, x );
        }
}

int LIS( int n ) {
        memst(level, n+10, INT_MAX);
        level[0] = INT_MIN;
        int i, ln = 0;
        for(i=n-1; i>=0; i--) {
                int pp = LB(0, ln, ar[i]);
                level[pp] = ar[i];
                if( pp > ln ) ln = pp;
        }
        return ln;
}

int main() {
        ///write;
        ///FasterIO;
        int cases, caseno = 0, n, i = 0;
        while( ~sc("%d", &n) ) {
                if( n != -1 ) ar[i++] = n;
                else {
                        if( i == 0 ) return 0;
                        if( caseno ) NL;
                        pf("Test #%d:\n  maximum possible interceptions: %d\n", ++caseno, LIS(i));
                        i = 0;
                }
        }

        return 0;
}
