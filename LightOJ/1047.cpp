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
int ar[205][205], dp[205][205];

int precal( int n ) {
        memset(dp, 0, sizeof dp);
        for(int i=1; i<=n; i++) {
                for(int j=1; j<=i; j++) {
                        dp[i][j] = ar[i][j] + max( dp[i-1][j], dp[i-1][j-1] );
                }
        }

        for(int i=n+1, k=n-1; i<=2*n-1; i++, k--) {
                for(int j=1; j<=k; j++) {
                        dp[i][j] = ar[i][j] + max( dp[i-1][j], dp[i-1][j+1] );
                }
        }

        return dp[2*n-1][1];
}

int main() {
        int cases, caseno = 0, n;
        scanf("%d", &cases);
        while( cases-- ) {
                memset(ar, 0, sizeof ar);
                scanf("%d", &n);
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=i; j++) {
                                scanf("%d", &ar[i][j]);
                        }
                }

                for(int i=n+1, k=n-1; i<=2*n-1; i++, k--) {
                        for(int j=1; j<=k; j++) {
                                scanf("%d", &ar[i][j]);
                        }
                }

                printf("Case %d: %d\n", ++caseno, precal(n));
        }

        return 0;
}
