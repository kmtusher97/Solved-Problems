#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<piii> viii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1e6;
int n, ar[123][123], dp[123][123];

int main() {
        //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        int cases, caseno = 0;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d", &n);
                for(int i=1; i<=n; i++)
                        for(int j=1; j<=i; j++) scanf("%d", &ar[i][j]);
                for(int i=n+1, k=n-1; i<2*n; i++, k--)
                        for(int j=1; j<=k; j++) scanf("%d", &ar[i][j]);

                memset(dp, 0, sizeof dp);
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=i; j++) {
                                dp[i][j] = ar[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
                        }
                }
                for(int i=n+1, k=n-1; i<2*n; i++, k--) {
                        for(int j=1; j<=k; j++) {
                                dp[i][j] = ar[i][j] + max(dp[i-1][j], dp[i-1][j+1]);
                        }
                }
                printf("Case %d: %d\n", ++caseno, dp[2*n-1][1]);
        }

        return 0;
}
