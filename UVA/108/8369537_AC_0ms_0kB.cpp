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
#define     INF             1000000000

#define     READ            freopen("INPUT.in", "r", stdin)
#define     WRITE           freopen("OUTPUT.out", "w", stdout)
#define     read            freopen("INPUT.txt", "r", stdin)
#define     write           freopen("OUTPUT.txt", "w", stdout)
#define     memst(arr, v)   memset(arr, v, sizeof(arr))
#define     FasterIO        ios_base :: sync_with_stdio( false ); cin.tie(0); cout.tie(0);

int dx4[] = { 0, 0, 1, -1 };    ///4 connected
int dy4[] = { -1, 1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy8[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

/*.....................................................................*/

int n, mtrx[200][200];

int MxSSA( int *ar ) {
        int i, sm = 0, mx = INT_MIN;
        bool flg = false;
        for(i=0; i<n; i++) {
                if( ar[i] >= 0 ) flg = true;
                mx = max(mx, ar[i]);
        }
        if( !flg ) return mx;
        mx = INT_MIN;
        for(i=0; i<n; i++) {
                sm += ar[i];
                if( sm < 0 ) sm = 0;
                mx = max(mx, sm);
        }
        return mx;
}

int MxSSM() {
        int l, r, i, temp[n], mx = INT_MIN;

        for(l=0; l<n; l++) {
                memst(temp, 0);
                for(r=l; r<n; r++) {
                        for(i=0; i<n; i++) {
                                temp[i] += mtrx[i][r];
                        }
                        mx = max(mx, MxSSA(temp));
                }
        }
        return mx;
}

int main() {
        ///FasterIO;
        ///write;
        int cases, caseno = 0;
        while( sc("%d", &n) == 1 ) {
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                                sc("%d", &mtrx[i][j]);

                pf("%d\n", MxSSM());

        }
        return 0;
}
