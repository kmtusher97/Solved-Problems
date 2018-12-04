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
#define     MX                52345
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int mtrx[120][120];

int mxarea( int r, int c ) {
        int i, j, k, l, mx = 0;
        for(i=1; i<=r; i++) {
                for(j=1; j<=c; j++) {
                        mtrx[i][j] += mtrx[i-1][j];
                }
        }
        for(i=1; i<=r; i++) {
                for(j=1; j<=c; j++) {
                        for(k=i; k<=r; k++) {
                                for(l=j; l<=c; l++) {
                                        int sm = mtrx[k][l] + mtrx[i-1][j-1] - mtrx[k][j-1] - mtrx[i-1][l];
                                        int area = (k-i+1) * (l-j+1);
                                        if( sm == area ) mx = max(mx, sm);
                                }
                        }
                }
        }
        cout << mx << endl;
}

int main() {
        ///write;
        FasterIO
        int r, c;
        while( cin >> r >> c ) {
                if( !r && !c ) break;
                for(int i=1; i<=r; i++)
                for(int j=1; j<=c; j++) {
                        int a;
                        cin >> a;
                        if( !a ) mtrx[i][j] = 1;
                        else mtrx[i][j] = 0;
                        mtrx[i][j] += mtrx[i][j-1];
                }
                mxarea(r, c);
        }

        return 0;
}
