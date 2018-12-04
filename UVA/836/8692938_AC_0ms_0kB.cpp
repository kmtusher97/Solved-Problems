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

int mtrx[100][100];

int MxSSM( int r, int c ) {
        for(int i=2; i<r; i++) {
                for(int j=1; j<c; j++) {
                        mtrx[i][j] += mtrx[i-1][j];
                }
        }
        int mx = 0;
        for(int i=1; i<r; i++) {
                for(int j=1; j<c; j++) {
                        for(int k=i; k<r; k++) {
                                for(int l=j; l<c; l++) {
                                        int sm = mtrx[k][l] + mtrx[i-1][j-1] - mtrx[i-1][l] - mtrx[k][j-1];
                                        int area = (k-i+1) * (l-j+1);
                                        if( sm == area ) mx = max(sm, mx);
                                }
                        }
                }
        }
        return mx;
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0, r = 1, c;
        string s;
        cin >> cases;
        getline(cin, s);
        getline(cin, s);
        while( cases-- ) {
                memset(mtrx, 0, sizeof mtrx);
                while( getline(cin, s) && s != "" ) {
                        c=1;
                        for(int k=0; k<s.size(); k++) {
                                mtrx[r][c] += ( mtrx[r][c-1] + s[k]-48 ), c++;
                        }
                        r++;
                }
                int ans = MxSSM(r, c);
                cout << ans << endl;
                if( cases ) cout << endl;
                r=1;
        }

        return 0;
}
