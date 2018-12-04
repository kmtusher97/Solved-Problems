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

int ar[200][200], m, n;

int fn( int *a ) {
        int i, j, cnt = 0, mx = INT_MIN;
        for(i=0; i<n; i++) {
                int mn = INT_MAX;
                for(j=i, cnt=0; j<n; j++) {
                        cnt++;
                        mn = min(mn, a[j]);
                        mx = max(mx, (cnt*mn));
                }
        }
        return mx;
}

void precal() {
        int i, j, mx = INT_MIN;
        int temp[n+10];
        memset(temp, 0, sizeof temp);
        for(i=0; i<m; i++) {
                for(j=0; j<n; j++) {
                        if( ar[i][j] == 0 ) {
                                temp[j]++;
                        }
                        else temp[j] = 0;
                }
                mx = max(mx, fn(temp));
        }
        pf("%d\n", mx);
}

int main() {
        ///write;
        ///FasterIO;
        int cases, caseno = 0, a;
        while( ~sc("%d %d", &m, &n) && m > 0 && n > 0 ) {
                for(int i=0; i<m; i++)
                for(int j=0; j<n; j++) {
                        sc("%d", &ar[i][j]);
                }
                precal();
        }

        return 0;
}
