#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[75][75];

void precal() {
        memset(dp, 0, sizeof dp);
        for(int i=0; i<72; i++) dp[0][i] = 1;

        for(int i=1; i<72; i++) {
                for(int j=1; j<72; j++) {
                        for(int k=0; k<=i; k++) {
                                dp[i][j] += dp[i-k][j-1];
                        }
                }
        }
}

int main() {
        precal();

        int cases, n, t, p;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d %d %d", &n, &t, &p);
                printf("%d\n", dp[t-n*p][n]);
        }

        return 0;
}
