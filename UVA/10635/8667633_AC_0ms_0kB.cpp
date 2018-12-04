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
#define     MX                63000
#define     INF               2123456789

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(0);

/*.................................................................................*/

int ar1[MX], ar2[MX], indx2[MX], freq[MX], level[MX];

int LwrBnd( int lo, int hi, int x ) {
        while( lo <= hi ) {
                int mid = lo + (hi-lo)/2;
                if( level[mid] < x ) lo = mid+1;
                else hi = mid-1;
        }
        return lo;
}

int LIS( vi v ) {
        int i, sz = v.size(), lis = 0;
        starr(level, sz+50, INF);
        level[0] = -INF;

        for(i=0; i<sz; i++) {
                int pp = LwrBnd(0, lis, v[i]);
                level[pp] = v[i];
                if( pp > lis ) lis = pp;
        }
        return lis;
}

int main() {
        ///write;
        FasterIO
        int cases, caseno = 0;
        cin >> cases;
        while( cases-- ) {
                int n, p, q, i, j;
                cin >> n >> p >> q;
                memset(freq, 0, sizeof freq);
                memset(indx2, -1, sizeof indx2);
                for(i=0; i<=p; i++) {
                        cin >> ar1[i];
                        freq[ ar1[i] ]++;
                }
                for(i=0; i<=q; i++) {
                        cin >> ar2[i];
                        freq[ ar2[i] ]++;
                        indx2[ ar2[i] ] = i;
                }
                vi temp;
                for(i=0; i<=p; i++) {
                        if( freq[ ar1[i] ] == 2 ) {
                                temp.pb( indx2[ ar1[i] ] );
                        }
                }
                cout << "Case " << ++caseno << ": " << LIS( temp ) <<endl;
        }

        return 0;
}
