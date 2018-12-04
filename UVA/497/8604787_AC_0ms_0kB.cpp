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

vi v;
int level[MX], lis[MX];

int LB( int lo, int hi, int x ) {
        while( lo <= hi ) {
                int mid = lo + (hi-lo)/2;
                if( level[mid] < x ) lo = mid+1;
                else hi = mid-1;
        }
        return lo;
}

int LIS( int n ) {
        memst(level, n+20, INF);
        level[0] = -INF;
        int ln = 0;
        for(int i=0; i<n; i++) {
                int p = LB( 0, ln, v[i] );
                level[p] = v[i];
                lis[i] = p;
                if( p > ln ) ln = p;
        }
        return ln;
}

int main() {
        //write;
        FasterIO
        int cases, caseno = 0, n;
        string s;
        cin >> cases;
        getline(cin, s);
        getline(cin, s);
        while( cases-- ) {
                n = 0;
                v.clear();
                while( getline(cin, s) ) {
                        if( s == "" ) break;
                        stringstream ss(s);
                        int p;
                        ss >> p;
                        v.pb(p);
                        n++;
                }
                int ln = LIS( n ), i;
                cout << "Max hits: " << ln << endl;
                vi v1;
                for(i=n-1; i>=0; i--) {
                        if( lis[i] == ln ) {
                                v1.pb( v[i] );
                                ln--;
                        }
                }
                for(i=v1.size()-1; i>=0; i--) {
                        cout << v1[i] << endl;
                }
                if( cases ) cout << endl;
        }

        return 0;
}
