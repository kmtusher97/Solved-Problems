#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1123456;
int dp[MX];

bool chk( int x ) {
    int dgt[12];
    for(int i=0; i<10; i++) dgt[i] = 0;
    while( x ) {
        dgt[x%10]++;
        x /= 10;
    }
    for(int i=0; i<10; i++) {
        if( dgt[i] > 1 ) return false;
    }
    return true;
}

void precal() {
    for(int i=1; i<=5050; i++) {
        dp[i] = chk(i);
    }
    for(int i=2; i<=5050; i++) {
        dp[i] += dp[i-1];
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    precal();
    int m, n;
    while( cin >> m >> n ) {
        cout << dp[n]-dp[m-1] << endl;
    }
    return 0;
}
