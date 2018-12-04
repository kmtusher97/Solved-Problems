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

const int MX = 2e5;
int rowsm[507][507], colsm[507][507], dp[507][507];

int main() {
        ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

        int n, m;
        while( cin >> n >> m ) {
                if( n == 0 && m == 0 ) return 0;
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                                cin >> rowsm[i][j];
                        }
                }
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                                cin >> colsm[i][j];
                        }
                }

                for(int i=1; i<=n; i++) {
                        for(int j=2; j<=m; j++) {
                                rowsm[i][j] += rowsm[i][j-1];
                        }
                }
                for(int i=1; i<=m; i++) {
                        for(int j=2; j<=n; j++) {
                                colsm[j][i] += colsm[j-1][i];
                        }
                }

                memset(dp, 0, sizeof dp);
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                                dp[i][j] = max( rowsm[i][j] + dp[i-1][j], colsm[i][j] + dp[i][j-1] );
                        }
                }
                cout << dp[n][m] << endl;
        }

        return 0;
}
