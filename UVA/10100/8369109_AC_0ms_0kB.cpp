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

vss v1, v2;
int dp[1007][1007];

int LCS( int n1, int n2 ) {
        memst(dp, 0);
        for(int i=0; i<n1; i++) {
                for(int j=0; j<n2; j++) {
                        if( v1[i] == v2[j] ) dp[i+1][j+1] = dp[i][j] + 1;
                        else dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1] );
                }
        }
        return dp[n1][n2];
}

int main() {
        ///FasterIO;
        ///write;
        int cases, caseno = 0;
        string line, temp;
        char ar[2000];
        while( getline(cin, line) ) {
                bool f1 = false, f2 = false;
                if( line.size() == 0 ) f1 = true;
                v1.clear();
                for(int i=0, j=0; i<=line.size(); i++) {
                        if( ( line[i] >= 'A' && line[i] <= 'Z' ) || ( line[i] >= 'a' && line[i] <= 'z' ) || ( line[i] >= '0' && line[i] <= '9' ) ) ar[j++] = line[i];
                        else {
                                ar[j] = '\0';
                                temp = ar, j = 0;
                                if( temp.size() ) v1.pb(temp);
                        }
                }
                getline(cin, line);
                if( line.size() == 0 ) f2 = true;
                v2.clear();
                for(int i=0, j=0; i<=line.size(); i++) {
                        if( ( line[i] >= 'A' && line[i] <= 'Z' ) || ( line[i] >= 'a' && line[i] <= 'z' ) || ( line[i] >= '0' && line[i] <= '9' ) ) ar[j++] = line[i];
                        else {
                                ar[j] = '\0';
                                temp = ar, j = 0;
                                if( temp.size() ) v2.pb(temp);
                        }
                }
                int ans = LCS( v1.size(), v2.size() );
                if( f1 || f2 ) pf("%2d. Blank!\n", ++caseno);
                else pf("%2d. Length of longest match: %d\n", ++caseno, ans);

        }

        return 0;
}
