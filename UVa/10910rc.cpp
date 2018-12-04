#include <bits/stdc++.h>
using namespace std;

int dp[75][75];

int ff( int m, int n ) {
        if( !m || n == 1 ) return 1;
        if( dp[m][n] != -1 ) return dp[m][n];

        int ans = 0;
        for(int i=0; i<=m; i++) ans += ff( m-i, n-1 );
        return dp[m][n] = ans;
}

int main() {
        int cases, n, t, p;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d %d %d", &n, &t, &p);
                memset(dp, -1, sizeof dp);
                printf("%d\n", ff( t-n*p, n ));
        }

        return 0;
}
