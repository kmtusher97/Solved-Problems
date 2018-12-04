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
int n, node;
string ss[MX];

struct data {
    int frq[30], stp_bt;
    void clr() {
        for(int i=0; i<30; i++)
            frq[i] = -1;
        stp_bt = 0;
    }
} trie[MX];

void insrt( string s ) {
    int crnt = 0;
    for(int i=0, ln=s.length(); i<ln; i++) {
        if( trie[crnt].frq[s[i]-'a'] == -1 ) {
            trie[crnt].frq[s[i]-'a'] = ++node;
        }
        crnt = trie[crnt].frq[s[i]-'a'];
    }
    trie[crnt].stp_bt++;
}

int srch( string s ) {
    int cnt = 1, crnt = 0;
    for(int i=0, ln=s.length(); i<ln; i++) {
        int brnch = 0;
        for(int j=0, c=0; j<30; j++) {
            if( trie[crnt].frq[j] != -1 ) brnch++;
        }
        if( ( crnt != 0 && brnch > 1 ) || trie[crnt].stp_bt > 0 ) cnt++;
        crnt = trie[crnt].frq[s[i]-'a'];
    }
    return cnt;
}

void sloution() {
    node = 0;
    for(int i=0; i<n; i++) {
        cin >> ss[i];
        insrt( ss[i] );
    }
    double sm = 0;
    for(int i=0; i<n; i++) {
        sm += srch( ss[i] );
    }
    cout << fixed << setprecision(2) << sm/(double)n << endl;
}

void trie_clr() {
    for(int i=0; i<MX; i++) {
        trie[i].clr();
    }
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while( cin >> n ) {
        trie_clr();
        sloution();
    }
    return 0;
}
