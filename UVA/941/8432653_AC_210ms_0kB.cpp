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
ll fact[30];
void factrial() {
        fact[0] = fact[1] = 1;
        for(ll i=2; i<=20; i++) fact[i] = i * fact[i-1];
}

string redec( string s, int p ) {
        char ar[50];
        int i, j;
        for(i=0,j=0; i<s.size(); i++) {
                if( i != p ) ar[j++] = s[i];
        }
        ar[j] = '\0';
        s = ar;
        return s;
}

int main() {
        ///write;
        //FasterIO;
        factrial();
        string s;
        ll cases, caseno = 0, n;
        cin >> cases;
        while( cases-- ) {
                cin >> s >> n;
                sort(s.begin(), s.end());
                ll ln = s.size(), sz = ln, i, m, p;
                for(i=0; i<sz; i++) {
                        m = fact[ln - 1];
                        p = n/m;
                        cout << s[p];
                        s = redec(s, p);
                        n -= ( p * m );
                        ln = s.size();
                }
                NL;
        }

        return 0;
}
