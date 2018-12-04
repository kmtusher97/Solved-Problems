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

const int MX = 2134;
map<string, int> mp;
string ss1[MX], ss2[MX];

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cases, caseno = 0, n, m;
    cin >> cases;
    while( cases-- ) {
        cin >> n >> m;
        getline(cin, ss1[0]);
        for(int i=0; i<n; i++) {
            getline(cin, ss1[i]);
        }
        for(int i=0; i<m; i++) {
            getline(cin, ss2[i]);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                string tmp = ss1[i]+ss2[j];
                mp[tmp]++;
            }
        }
        cout << "Case " << ++caseno << ": " << mp.size() << endl;
        mp.clear();
    }

    return 0;
}
