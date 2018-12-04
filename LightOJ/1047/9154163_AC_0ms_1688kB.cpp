#include <bits/stdc++.h>
using namespace std;

#define FasterIO iso_base :: sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vss;
typedef vector<pii> vii;
typedef queue<int> qi;

const int MX = 123456;
int ar[25][4], dp[25][4];

int precal( int n ) {
        memset(dp, 0, sizeof dp);
        for(int i=1; i<=n; i++) {
                dp[i][1] = ar[i][1] + min( dp[i-1][2], dp[i-1][3] );
                dp[i][2] = ar[i][2] + min( dp[i-1][1], dp[i-1][3] );
                dp[i][3] = ar[i][3] + min( dp[i-1][1], dp[i-1][2] );
        }

        return min( dp[n][1], min( dp[n][2], dp[n][3] ) );
}

int main() {
        int cases, caseno = 0, n;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d", &n);
                for(int i=1; i<=n; i++) {
                        scanf("%d %d %d", &ar[i][1], &ar[i][2], &ar[i][3]);
                }

                printf("Case %d: %d\n", ++caseno, precal(n));
        }

        return 0;
}


