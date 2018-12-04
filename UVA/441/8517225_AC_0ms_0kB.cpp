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

int main() {
        ///write;
        ///FasterIO;
        int n, i, caseno = 0;
        while( ~sc("%d", &n) && n > 0 ) {
                int ar[n+5];
                for(i=1; i<=n; i++) {
                        sc("%d", &ar[i]);
                }
                if( caseno++ ) NL;
                for(int a=1; a<=n-5; a++) {
                        for(int b=a+1; b<=n-4; b++) {
                                for(int c=b+1; c<=n-3; c++) {
                                        for(int d=c+1; d<=n-2; d++) {
                                                for(int e=d+1; e<=n-1; e++) {
                                                        for(int f=e+1; f<=n; f++) {
                                                                pf("%d %d %d %d %d %d\n", ar[a], ar[b], ar[c], ar[d], ar[e], ar[f]);
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }

        return 0;
}